


#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>


IPAddress    apIP(11, 11, 11, 11);
const char* ssid = "hadeel";
const char* password = "15528888";
ESP8266WebServer server (80);



void w_setup() {

      WiFi.mode(WIFI_AP_STA);
    WiFi.softAPConfig(apIP, apIP, IPAddress(255, 255, 255, 0));
  WiFi.softAP(ssid);
    Serial.print("creating ssid=");
    Serial.println(ssid);
    IPAddress myIP = WiFi.softAPIP();
    Serial.print("AP IP address: ");
    Serial.println(myIP);
    server.on("/", handleRoot);
    server.onNotFound(handleNotFound);
    server.begin();
    Serial.println("HTTP server started");
}

void w_loop() {
    server.handleClient();//.server is defined at this tab
    delay(10);
}

void handleNotFound() {
  String message = "File Not Found\n\n";
  message += "URI: ";
  message += server.uri();
  message += "\nMethod: ";
  message += ( server.method() == HTTP_GET ) ? "GET" : "POST";
  message += "\nArguments: ";
  message += server.args();
  message += "\n";

  for ( uint8_t i = 0; i < server.args(); i++ ) {
    message += " " + server.argName ( i ) + ": " + server.arg ( i ) + "\n";
  }

  server.send ( 404, "text/plain", message );
  
}
void handleRoot() {
 
  String color;
  if(server.hasArg("c")){
   color=server.arg("c");
  setNeoColor(color);
  }
    if (server.hasArg("off")) {
      digitalWrite(R,LOW);
          digitalWrite(G,LOW);
              digitalWrite(B,LOW);
      }
 
  char temp[5000];
  snprintf ( temp, 5000,

"<!DOCTYPE html>\n<html>\n\
  <head>\n\
    <title>RGB LED</title>\n\
    <style>\
      body { background-color: #cccccc; font-family: Arial; Color: #008; }\
    </style>\n\
    <meta name=\"viewport\" content=\"width=device-width, height=device-height, initial-scale=1.0, user-scalable=0, minimum-scale=1.0, maximum-scale=1.0\" />\n\
  </head>\n\
  <body>\n\
    <h1>CHOOSE A COLOR:</h1>\n\
    \n\
    <form action=\"\" name=\"pick\" method=\"get\">\n\
    <input type=\"color\" name=\"c\" value=\"#ffffff\" type=\color\" />\n\
    <input type=\"submit\">\n\
    \n\
      <button name = \"off\">turn OFF</button>\n\</form>\n\
    \n\
  </body>\
</html>"

  );
  server.send ( 200, "text/html", temp );
   

}
