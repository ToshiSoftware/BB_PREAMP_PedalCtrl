// callback from Arduino web-server lib

#include "web_server.h"
#include "myUtil.h"

char htmlbody[32768];

// create html message sent to web browser
void CreateIndexHtml(void)
{
  char tmpstr[256];
      strcpy(htmlbody, index_html1);
      for(int i=0;i<NUM_PRESET;i++)
      {
        sprintf(tmpstr, "document.getElementById('v%d').value = %d;\n", i, presetParams[i].volume);
        strcat(htmlbody, tmpstr);
        sprintf(tmpstr, "document.getElementById('g%d').value = %d;\n", i, presetParams[i].gain);
        strcat(htmlbody, tmpstr);
        sprintf(tmpstr, "document.getElementById('t%d').value = %d;\n\n", i, presetParams[i].treble);
        strcat(htmlbody, tmpstr);
        sprintf(tmpstr, "document.getElementById('b%d').value = %d;\n\n", i, presetParams[i].bass);
        strcat(htmlbody, tmpstr);
      }
      strcat(htmlbody, index_html3);
      if(debug_output_to_html){
        strcat(htmlbody, "<br />\n");
        strcat(htmlbody, debug_message);
        strcat(htmlbody, "<br />\n");
      }
      strcat(htmlbody, index_html4);
}

// callback when root url accessed
void handleRoot(void) {
  char uriStr[256];
  // exit
  if(appVars.available_wifi==true)
  {
    httpServer.uri().toCharArray(uriStr, 255);
    if(strcmp(uriStr, "/")==0){
      // send index.html
      CreateIndexHtml();
      httpServer.send(200, "text/html", htmlbody);
    }
  }
}

// callback when parameter change uri(/preset) accessed
void handleSetVol(void) {
  int changeCount=0;
  char uriStr[256];

  // check uri
  httpServer.uri().toCharArray(uriStr, 255);
  if(strcmp(uriStr, "/preset")==0){
    if(appVars.available_wifi==true)
    {
      for (uint8_t i = 0; i < httpServer.args(); i++) {
        //  message += " " + httpServer.argName(i) + ": " + httpServer.arg(i) + "\n";
        char name[32]; 
        httpServer.argName(i).toCharArray(name, 31);
        if(strlen(name)==2){
          // check if the 1st letter is e/f/t
          if(name[0]=='v' || name[0]=='g' || name[0]=='t' || name[0]=='b'){
            // check if the 2nd letter is between 0 to 9
            if(name[1]>='0' && name[1]<='9'){
              int index = name[1]-'0';
              if(index>=0 && index<=9)
              {
                int value = httpServer.arg(i).toInt();
                if(name[0]=='v' && value>=0 && value<=99) presetParams[index].volume = value;
                else if(name[0]=='g' && value>=0 && value<=99) presetParams[index].gain = value;
                else if(name[0]=='t' && value>=-50 && value<=50) presetParams[index].treble = value;
                else if(name[0]=='b' && value>=-50 && value<=50) presetParams[index].bass = value;
                changeCount++;
              }
            }
          }
        }
      }
      
      // verify preset value
      CheckAndCorrectPreset();

      // send index html
      CreateIndexHtml();
      httpServer.send(200, "text/html", htmlbody);

      // if any preset is changed
      if(changeCount){
        // update html
        appVars.changed_via_wifi = true;

        // save to eeprom
        save_eeprom();
        // LCD
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Presets replaced");
        lcd.setCursor(0,1);
        lcd.print("via WiFi.");
        delay(3000);
      }
    }
  }
  else{
      CreateIndexHtml();
      httpServer.send(200, "text/html", htmlbody);
  }
}
