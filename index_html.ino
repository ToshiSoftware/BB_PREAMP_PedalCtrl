// HTML code to display when bpp.local is accessed.

char index_html1[]=
"<html>\n\
<head>\n\
<title>Presettable Blues Breaker Editor</title>\n\
<style type=\"text/css\">\n\
<!--\n\
\n\
html {\n\
	-webkit-text-size-adjust: 100%;\n\
}\n\
\n\
body,div,dl,dt,dd,ul,ol,li,h1,h2,h3,h4,h5,h6,pre,form,input,p,blockquote,th,td {\n\
	margin:0;\n\
	padding:0;\n\
	font-family: Arial, Helvetica, sans-serif;\n\
	color: #222222;\n\
	line-height: 1.5em;\n\
	font-size:18px;\n\
}\n\
table {\n\
	border-collapse:collapse;\n\
	border-spacing:0;\n\
	font-size:18px;\n\
	margin-left:8px;\n\
	margin-right:8px;\n\
	margin-top:2px;\n\
	margin-bottom: 2px;\n\
}\n\
h1 {\n\
	margin: 0.5em 0 0 0;\n\
	padding: 2px;\n\
	color: #0068B7;\n\
	font-weight: bold;\n\
	border-bottom: #0068B7 6px solid;\n\
	clear: both;\n\
	font-size: 20px;\n\
}\n\
.btn--orange,\n\
a.btn--orange {\n\
  color: #fff;\n\
  background-color: #eb6100;\n\
}\n\
.btn--orange:hover,\n\
a.btn--orange:hover {\n\
  color: #fff;\n\
  background: #f56500;\n\
}\n\
\n\
a.btn--radius {\n\
   border-radius: 100vh;\n\
}\n\
\n\
-->\n\
</style>\n\
\n\
<meta name=\"viewport\" content=\"width=device-width\" />\n\
\n\
</head>\n\
<body>\n\
\n\
<div>\n\
<h1>Presettable Blues Breaker Editor V1.1<br>\n\
</h1>\n\
</div>\n\
  \n\
<form action=\"http://bbp.local/preset\" method=\"get\" >\n\
\n\
\n\
  <table width=\"95%\" border=\"1\" cellpadding=\"0\" cellspacing=\"0\">\n\
    <tr>\n\
      <td width=\"10%\" bgcolor=\"#66CC99\"><div align=\"center\"><strong>Preset No.</strong></div></td>\n\
      <td width=\"20%\" bgcolor=\"#66CC99\"><div align=\"center\"><strong>Volume</strong></div></td>\n\
      <td width=\"20%\" bgcolor=\"#66CC99\"><div align=\"center\"><strong>Gain</strong></div></td>\n\
      <td width=\"25%\" bgcolor=\"#66CC99\"><div align=\"center\"><strong>Treble</strong></div></td>\n\
      <td width=\"25%\" bgcolor=\"#66CC99\"><div align=\"center\"><strong>Bass</strong></div></td>\n\
    </tr>\n\
    <tr>\n\
      <td width=\"10%\"><div align=\"center\">0</div></td>\n\
      <td width=\"20%\"><label>\n\
        <div align=\"center\">\n\
          <input type=\"text\" name=\"v0\" id=\"v0\" style=\"width: 100%;\" maxlength=\"2\">\n\
          </div>\n\
      </label></td>\n\
      <td width=\"20%\"><label>\n\
        <div align=\"center\">\n\
          <input type=\"text\" name=\"g0\" id=\"g0\" style=\"width: 100%;\" maxlength=\"2\">\n\
          </div>\n\
      </label></td>\n\
      <td width=\"25%\"><label>\n\
          <div align=\"center\">\n\
            <input type=\"text\" name=\"t0\" id=\"t0\" style=\"width: 100%;\" maxlength=\"3\">\n\
          </div>\n\
      </label></td>\n\
      <td width=\"25%\"><label>\n\
        <div align=\"center\">\n\
          <input type=\"text\" name=\"b0\" id=\"b0\" style=\"width: 100%;\" maxlength=\"3\">\n\
          </div>\n\
      </label></td></td>\n\
    </tr>\n\
    <tr>\n\
      <td><div align=\"center\">1</div></td>\n\
      <td width=\"20%\"><label>\n\
        <div align=\"center\">\n\
          <input type=\"text\" name=\"v1\" id=\"v1\" style=\"width: 100%;\" maxlength=\"2\"  >\n\
          </div>\n\
      </label></td>\n\
      <td width=\"20%\"><label>\n\
        <div align=\"center\">\n\
          <input type=\"text\" name=\"g1\" id=\"g1\" style=\"width: 100%;\" maxlength=\"2\"  >\n\
          </div>\n\
      </label></td>\n\
      <td width=\"25%\"><label>\n\
          <div align=\"center\">\n\
            <input type=\"text\" name=\"t1\" id=\"t1\" style=\"width: 100%;\" maxlength=\"3\"  >\n\
          </div>\n\
      </label></td>\n\
      <td width=\"25%\"><label>\n\
        <div align=\"center\">\n\
          <input type=\"text\" name=\"b1\" id=\"b1\" style=\"width: 100%;\" maxlength=\"3\"  >\n\
          </div>\n\
      </label></td>\n\
      </tr>\n\
    <tr>\n\
      <td><div align=\"center\">2</div></td>\n\
      <td width=\"20%\"><label>\n\
        <div align=\"center\">\n\
          <input type=\"text\" name=\"v2\" id=\"v2\" style=\"width: 100%;\" maxlength=\"2\">\n\
          </div>\n\
      </label></td>\n\
      <td width=\"20%\"><label>\n\
        <div align=\"center\">\n\
          <input type=\"text\" name=\"g2\" id=\"g2\" style=\"width: 100%;\" maxlength=\"2\">\n\
          </div>\n\
      </label></td>\n\
      <td width=\"25%\"><label>\n\
          <div align=\"center\">\n\
            <input type=\"text\" name=\"t2\" id=\"t2\" style=\"width: 100%;\" maxlength=\"3\">\n\
          </div>\n\
      </label></td>\n\
      <td width=\"25%\"><label>\n\
        <div align=\"center\">\n\
          <input type=\"text\" name=\"b2\" id=\"b2\" style=\"width: 100%;\" maxlength=\"3\">\n\
          </div>\n\
      </label></td>\n\
      </tr>\n\
    <tr>\n\
      <td><div align=\"center\">3</div></td>\n\
      <td width=\"20%\"><label>\n\
        <div align=\"center\">\n\
          <input type=\"text\" name=\"v3\" id=\"v3\" style=\"width: 100%;\" maxlength=\"2\">\n\
          </div>\n\
      </label></td>\n\
      <td width=\"20%\"><label>\n\
        <div align=\"center\">\n\
          <input type=\"text\" name=\"g3\" id=\"g3\" style=\"width: 100%;\" maxlength=\"2\">\n\
          </div>\n\
      </label></td>\n\
      <td width=\"25%\"><label>\n\
          <div align=\"center\">\n\
            <input type=\"text\" name=\"t3\" id=\"t3\" style=\"width: 100%;\" maxlength=\"3\">\n\
          </div>\n\
      </label></td>\n\
      <td width=\"25%\"><label>\n\
        <div align=\"center\">\n\
          <input type=\"text\" name=\"b3\" id=\"b3\" style=\"width: 100%;\" maxlength=\"3\">\n\
          </div>\n\
      </label></td>\n\
      </tr>\n\
    <tr>\n\
      <td><div align=\"center\">4</div></td>\n\
      <td width=\"20%\"><label>\n\
        <div align=\"center\">\n\
          <input type=\"text\" name=\"v4\" id=\"v4\" style=\"width: 100%;\" maxlength=\"2\">\n\
          </div>\n\
      </label></td>\n\
      <td width=\"20%\"><label>\n\
        <div align=\"center\">\n\
          <input type=\"text\" name=\"g4\" id=\"g4\" style=\"width: 100%;\" maxlength=\"2\">\n\
          </div>\n\
      </label></td>\n\
      <td width=\"25%\"><label>\n\
          <div align=\"center\">\n\
            <input type=\"text\" name=\"t4\" id=\"t4\" style=\"width: 100%;\" maxlength=\"3\">\n\
          </div>\n\
      </label></td>\n\
      <td width=\"25%\"><label>\n\
        <div align=\"center\">\n\
          <input type=\"text\" name=\"b4\" id=\"b4\" style=\"width: 100%;\" maxlength=\"3\">\n\
          </div>\n\
      </label></td>\n\
      </tr>\n\
    <tr>\n\
      <td><div align=\"center\">5</div></td>\n\
      <td width=\"20%\"><label>\n\
        <div align=\"center\">\n\
          <input type=\"text\" name=\"v5\" id=\"v5\" style=\"width: 100%;\" maxlength=\"2\">\n\
          </div>\n\
      </label></td>\n\
      <td width=\"20%\"><label>\n\
        <div align=\"center\">\n\
          <input type=\"text\" name=\"g5\" id=\"g5\" style=\"width: 100%;\" maxlength=\"2\">\n\
          </div>\n\
      </label></td>\n\
      <td width=\"25%\"><label>\n\
          <div align=\"center\">\n\
            <input type=\"text\" name=\"t5\" id=\"t5\" style=\"width: 100%;\" maxlength=\"3\">\n\
          </div>\n\
      </label></td>\n\
      <td width=\"25%\"><label>\n\
        <div align=\"center\">\n\
          <input type=\"text\" name=\"b5\" id=\"b5\" style=\"width: 100%;\" maxlength=\"3\">\n\
          </div>\n\
      </label></td>\n\
      </tr>\n\
    <tr>\n\
      <td><div align=\"center\">6</div></td>\n\
      <td width=\"20%\"><label>\n\
        <div align=\"center\">\n\
          <input type=\"text\" name=\"v6\" id=\"v6\" style=\"width: 100%;\" maxlength=\"2\">\n\
          </div>\n\
      </label></td>\n\
      <td width=\"20%\"><label>\n\
        <div align=\"center\">\n\
          <input type=\"text\" name=\"g6\" id=\"g6\" style=\"width: 100%;\" maxlength=\"2\">\n\
          </div>\n\
      </label></td>\n\
      <td width=\"25%\"><label>\n\
          <div align=\"center\">\n\
            <input type=\"text\" name=\"t6\" id=\"t6\" style=\"width: 100%;\" maxlength=\"3\">\n\
          </div>\n\
      </label></td>\n\
      <td width=\"25%\"><label>\n\
        <div align=\"center\">\n\
          <input type=\"text\" name=\"b6\" id=\"b6\" style=\"width: 100%;\" maxlength=\"3\">\n\
          </div>\n\
      </label></td>\n\
      </tr>\n\
    <tr>\n\
      <td><div align=\"center\">7</div></td>\n\
      <td width=\"20%\"><label>\n\
        <div align=\"center\">\n\
          <input type=\"text\" name=\"v7\" id=\"v7\" style=\"width: 100%;\" maxlength=\"2\">\n\
          </div>\n\
      </label></td>\n\
      <td width=\"20%\"><label>\n\
        <div align=\"center\">\n\
          <input type=\"text\" name=\"g7\" id=\"g7\" style=\"width: 100%;\" maxlength=\"2\">\n\
          </div>\n\
      </label></td>\n\
      <td width=\"25%\"><label>\n\
          <div align=\"center\">\n\
            <input type=\"text\" name=\"t7\" id=\"t7\" style=\"width: 100%;\" maxlength=\"3\">\n\
          </div>\n\
      </label></td>\n\
      <td width=\"25%\"><label>\n\
        <div align=\"center\">\n\
          <input type=\"text\" name=\"b7\" id=\"b7\" style=\"width: 100%;\" maxlength=\"3\">\n\
          </div>\n\
      </label></td>\n\
      </tr>\n\
    <tr>\n\
      <td><div align=\"center\">8</div></td>\n\
      <td width=\"20%\"><label>\n\
        <div align=\"center\">\n\
          <input type=\"text\" name=\"v8\" id=\"v8\" style=\"width: 100%;\" maxlength=\"2\">\n\
          </div>\n\
      </label></td>\n\
      <td width=\"20%\"><label>\n\
        <div align=\"center\">\n\
          <input type=\"text\" name=\"g8\" id=\"g8\" style=\"width: 100%;\" maxlength=\"2\">\n\
          </div>\n\
      </label></td>\n\
      <td width=\"25%\"><label>\n\
          <div align=\"center\">\n\
            <input type=\"text\" name=\"t8\" id=\"t8\" style=\"width: 100%;\" maxlength=\"3\">\n\
          </div>\n\
      </label></td>\n\
      <td width=\"25%\"><label>\n\
        <div align=\"center\">\n\
          <input type=\"text\" name=\"b8\" id=\"b8\" style=\"width: 100%;\" maxlength=\"3\">\n\
          </div>\n\
      </label></td>\n\
      </tr>\n\
    <tr>\n\
      <td><div align=\"center\">9</div></td>\n\
      <td width=\"20%\"><label>\n\
        <div align=\"center\">\n\
          <input type=\"text\" name=\"v9\" id=\"v9\" style=\"width: 100%;\" maxlength=\"2\">\n\
          </div>\n\
      </label></td>\n\
      <td width=\"20%\"><label>\n\
        <div align=\"center\">\n\
          <input type=\"text\" name=\"g9\" id=\"g9\" style=\"width: 100%;\" maxlength=\"2\">\n\
          </div>\n\
      </label></td>\n\
      <td width=\"25%\"><label>\n\
          <div align=\"center\">\n\
            <input type=\"text\" name=\"t9\" id=\"t9\" style=\"width: 100%;\" maxlength=\"3\">\n\
          </div>\n\
      </label></td>\n\
      <td width=\"25%\"><label>\n\
        <div align=\"center\">\n\
          <input type=\"text\" name=\"b9\" id=\"b9\" style=\"width: 100%;\" maxlength=\"3\">\n\
          </div>\n\
      </label></td>\n\
    </tr>\n\
  </table>\n\
<br>\n\
\n\
 <p align=\"center\"><input class=\"btn btn--orange btn--radius\" type=\"submit\" name=\"sn\" value=\"Submit preset data\"/></p>\n\
<script language=\"javascript\">\n";


char index_html2[]=
" document.getElementById('v0').value = 25; \n\
 document.getElementById('g0').value = 50; \n\
 document.getElementById('t0').value = 0; \n\
 document.getElementById('b0').value = 0; \n\
\n\
 document.getElementById('v1').value = 25; \n\
 document.getElementById('g1').value = 50; \n\
 document.getElementById('t1').value = 0; \n\
 document.getElementById('b1').value = 0; \n\
\n\
 document.getElementById('v2').value = 25; \n\
 document.getElementById('g2').value = 50; \n\
 document.getElementById('t2').value = 0; \n\
 document.getElementById('b2').value = 0; \n\
\n\
 document.getElementById('v3').value = 25; \n\
 document.getElementById('g3').value = 50; \n\
 document.getElementById('t3').value = 0; \n\
 document.getElementById('b3').value = 0; \n\
\n\
 document.getElementById('v4').value = 25; \n\
 document.getElementById('g4').value = 50; \n\
 document.getElementById('t4').value = 0; \n\
 document.getElementById('b4').value = 0; \n\
\n\
 document.getElementById('v5').value = 25; \n\
 document.getElementById('g5').value = 50; \n\
 document.getElementById('t5').value = 0; \n\
 document.getElementById('b5').value = 0; \n\
\n\
 document.getElementById('v6').value = 25; \n\
 document.getElementById('g6').value = 50; \n\
 document.getElementById('t6').value = 0; \n\
 document.getElementById('b6').value = 0; \n\
\n\
 document.getElementById('v7').value = 25; \n\
 document.getElementById('g7').value = 50; \n\
 document.getElementById('t7').value = 0; \n\
 document.getElementById('b7').value = 0; \n\
\n\
 document.getElementById('v8').value = 25; \n\
 document.getElementById('g8').value = 50; \n\
 document.getElementById('t8').value = 0; \n\
 document.getElementById('b8').value = 0; \n\
\n\
 document.getElementById('v9').value = 25; \n\
 document.getElementById('g9').value = 50; \n\
 document.getElementById('t9').value = 0; \n\
 document.getElementById('b9').value = 0; ";

char index_html3[]=
"</script>\n\
\n\
</form>\n";

char index_html4[]=
"</body>\n\
</html>\n";

