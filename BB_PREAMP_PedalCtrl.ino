/*
  Arduino BB-Preamp pedal controller using ESP32C3 (Seeed XIAO)
  Web server TEST URI:
    open the following URIs:
      http://bbp.local/
*/

#include <WiFi.h>
#include <WiFiClient.h>
#include <WebServer.h>
#include <ESPmDNS.h>
#include <HTTPUpdateServer.h>
#include <time.h>

#include <MIDI.h>
#include <Wire.h>
#include <ST7032.h>
#include <EEPROM.h>

#include "BB_PREAMP_PedalCtrl.h"
#include "myUtil.h"
#include "mySPI.h"
#include "web_server.h"
#include "ui_handler.h"

// debug
int debug_output_to_html=false;
char debug_message[1024]="Debug message..<br />\n";

// Def: LCD
ST7032 lcd;

// Def: Wifi+WebServer
const char* host = "bbpreamp-webupdate";
extern char index_html[];
WebServer httpServer(80);
HTTPUpdateServer httpUpdater;

// Def: eeprom data
EEPROM_DATA eeprom;

// Def: MIDI
MIDI_CREATE_INSTANCE(HardwareSerial, Serial, MIDI);

// Def: HwTimer
hw_timer_t *timer0 = NULL;

// Def: mySPI
Type_HC165Manage hc165;
Type_InputManage sdi;

// Def: app palams
Type_AppParams appParam;
Type_PresetParams presetParams[NUM_PRESET];
Type_AppInternalVars appVars;

// SSID PASSPHRASE available charactors
char valid_ssid_char[]=VALID_SSID;
char valid_pass_char[]=VALID_PASS;


void SetupAppParams(void)
{
  // parameters to save to eeprom 
  memset(&appParam, 0, sizeof(Type_AppParams));
  appParam.volume = 25;
  appParam.gain = 50;
  appParam.treble = 0;
  appParam.bass = 0;
  appParam.presetNo = 0;
  appParam.midi_ch = 1; // 1-16
  appParam.footsw_mode = 0;
  memset(appParam.wifi_ssid, 0, WIFI_SSID_MAX_LEN+1);
  memset(appParam.wifi_pass, 0, WIFI_PASS_MAX_LEN+1);
  appParam.wifi_enable = false;
  appParam.preset_max = 9;

  // variables internal use
  memset(&appVars, 0, sizeof(Type_AppInternalVars));
  appVars.selected_knob=0;
  appVars.selected_mode=0;
  appVars.selected_settings=0;
  appVars.selected_yesno=0;
  appVars.preset_changed=false;
  appVars.available_wifi=false;
  appVars.mode = 0;
  appVars.changed_via_wifi = false;
  appVars.changed_wifi_7seg = false;

  memset(appVars.edited_wifi_ssid, 0, WIFI_SSID_MAX_LEN+1);
  memset(appVars.edited_wifi_pass, 0, WIFI_PASS_MAX_LEN+1);

  appVars.edit_cursor_char_id = 0;
  appVars.wifi_onoff_changed = false;

  // preset param
  int i;
  for(i=0;i<NUM_PRESET;i++){
    presetParams[i].volume=25;
    presetParams[i].gain=50;
    presetParams[i].treble=0;
    presetParams[i].bass=0;
 }
}


// System setup
void setup(void) {
  // SYSTEM HW -------------------------------------------
  // init app params
  SetupAppParams();

  // TEST pin
  pinMode(LED1_PIN, OUTPUT);
  digitalWrite(LED1_PIN, LOW);

  // SPI for digital pot
  SetupAD5263();
  MySpiTransfer(0,0,0,0);

  // LCD Display -------------------------------------------
  // LCD: setup
  char STARTING_STR[]="Starting up...";
  
  lcd.begin(16, 2);
  lcd.setContrast(45);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("BruesBreaker 1.1");

  lcd.setCursor(0, 1);
  for(int i=0; i<strlen(STARTING_STR); i++){
    char text[2];
    text[0]=STARTING_STR[i];
    text[1]='\0';
    lcd.print(text);
    delay(200);
  }
  delay(2000);

  // EEPROM -------------------------------------------
  // EEPROM: start
  memset(&eeprom, 0, sizeof(EEPROM_DATA));
  EEPROM.begin(sizeof(EEPROM_DATA)+0x100); 
  load_eeprom();

  // $$$$ for test
  //strcpy(appParam.wifi_ssid, STASSID);
  //strcpy(appParam.wifi_pass, STAPSK);

  // WiFi(web server) -------------------------------------------
  // WiFi: start
  if(appParam.wifi_enable == true){
    // ignore case
    if(strcmp(appParam.wifi_ssid, "")==0 || strcmp(appParam.wifi_pass, "")==0 ){
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Wifi unavailable");
        lcd.setCursor(0, 1);
        lcd.print("Wrong SSID/PASS");
        delay(4000);
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Rebooting..");
        delay(2000);
        appParam.wifi_enable = false;
        save_eeprom();
        ESP.restart();
    }
    else{
      // try to connect
      WiFi.mode(WIFI_AP_STA);
      int tmpct=0;
      while(1)
      {
        WiFi.begin(appParam.wifi_ssid, appParam.wifi_pass);
        if(WiFi.waitForConnectResult() == WL_CONNECTED) 
        {
          appVars.available_wifi=true;
          break;
        }
        delay(500);
        tmpct++;
        if(tmpct>WIFI_CONNECTION_RETRY) break;
        // 
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Connecting Wifi.");
        lcd.setCursor(0, 1);
        lcd.print("Retry:");
        lcd.print(tmpct);
        lcd.print("/");
        lcd.print(WIFI_CONNECTION_RETRY);
      }
      // if wifi is ready
      if(appVars.available_wifi==true)
      {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("http://");
        lcd.print(MDNS_STR);
        lcd.print(".local");
        // params
        lcd.setCursor(0,1);
        lcd.print(WiFi.localIP());
        delay(2000);
      }
      // if Wifi connection error, reboot system to correct SSID or PASS
      else{
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Wifi unavailable");
        lcd.setCursor(0, 1);
        lcd.print("Wrong SSID/PASS");
        delay(4000);
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Rebooting..");
        delay(2000);
        appParam.wifi_enable = false;
        save_eeprom();
        ESP.restart();
      }
    }
  }
  else {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Wifi disabled");
      lcd.setCursor(0, 1);
      lcd.print("See SET menu");
      delay(2000);
  }

  if(appVars.available_wifi==true)
  {  
    // WiFi: DNS start  , register "esp32.local" to Multicast Domain Name System(mDNS)
    MDNS.begin(host);
    if (MDNS.begin(MDNS_STR)) {
      //Serial.println("mDNS responder started");
    }
    lcd.setCursor(0, 0);

    // Time: get JST time(JAPAN)
    configTime( JST, 0, "ntp.nict.jp", "ntp.jst.mfeed.ad.jp");

    // Web Server: setup
    httpUpdater.setup(&httpServer);

    // Web Server: handler when root accessed
    httpServer.on("/", handleRoot);
    httpServer.on("/preset", handleSetVol);
    httpServer.onNotFound(handleRoot);

    // Web Server: launch web server
    httpServer.begin();
    MDNS.addService("http", "tcp", 80);
  }

  // MIDI -------------------------------------------
  #ifndef USE_SERIAL
    MIDI.begin(MIDI_CHANNEL_OMNI);
  #endif
 
  // INTERRUPT for INPUT HW(Button, Encoder) -------------------------------------------
  // interrupt for mySPI
  SetupReadHC165();
  SetupParseSdiData();
  timer0 = timerBegin(0, PRESCALER_DIVIDE_RATE, true);
  timerAttachInterrupt(timer0, &ReadHC165, true); // calllback
  timerAlarmWrite(timer0, TIMER_UI_INTERVAL, true); // 1000 microsec
  timerAlarmEnable(timer0); // start timer

  // INIT APP STATE -------------------------------------------
  // load preset data to the current params
  LoadPresetToCurrentParam(appParam.presetNo);

  // Wifi connection
  if(appVars.available_wifi == true)
  {
    appVars.mode=MODE_WIFI_CONNECTING;
    appParam.onoff = false;
    appParam.presetNo = 0;
    appParam.volume = 25;
    appParam.gain = 50;
    appParam.treble = 0;
    appParam.bass = 0;
  }
  else{
    if(appParam.footsw_mode==FOOTSW_PRESET){
      appParam.onoff = true;
    }
  } 

  // initial state
  lcd.clear();
  UpdateEntireLcdDisplay();
  SendMyHC595Serial(false);
}

// Event loop
int updated_button=false;
int updated_encoder=false;
int updated_midi=false;

void loop(void) {
  static int counter=0;
  int i;

  // Sdi handler
  if(hc165.flag_read) { // set by ReadHC165()
    hc165.flag_read = false; // wait next interrupt
    // handle serial input data
    ParseSdiData();
    HandleSw();
    HandleEncoder();

    // UI handler
    updated_button = UiButtonHandler();
    updated_encoder = UiEncoderHandler();
    updated_midi = HandleMidi(); 

    // LCD for ui handler
    if(updated_button || updated_encoder || updated_midi){
      // update display
      UpdateEntireLcdDisplay();
      SendMyHC595Serial(false);
    }

  }

  // LCD for preset table change via wifi
  if(appVars.changed_via_wifi == true)
  {
    appVars.changed_via_wifi = false;
    // load preset data to the current params
    LoadPresetToCurrentParam(appParam.presetNo);
    // update display
    UpdateEntireLcdDisplay();
    SendMyHC595Serial(false);
  }

  // HTTPD handler
  if(appVars.available_wifi==true){
    httpServer.handleClient();
  }

  // blink when wifi
  if(appVars.available_wifi == true && appVars.changed_wifi_7seg == true )
  {
    static int counter=0;
    appVars.changed_wifi_7seg = false;
    counter++;
    counter%=6;
    // set serial
    unsigned char seg7=0, hc595=0;
    int step_treble, step_gain, step_bass, step_volume;

    // 7seg
    seg7 = ~(0x01<<counter);

    // AD8405 step
    step_treble = 0;
    step_gain = 0;
    step_bass = 0;
    step_volume = 0;
    // effect
    MySpiTransfer(seg7, hc595, 0, step_treble);
    MySpiTransfer(seg7, hc595, 1, step_gain);
    MySpiTransfer(seg7, hc595, 2, step_bass);
    MySpiTransfer(seg7, hc595, 3, step_volume);
  }

}

