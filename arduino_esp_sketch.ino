
#include <WiFi.h>

#include <WiFiClient.h>

#include <WiFiServer.h>

#include <WebServer.h>



const char* ssid = "ESP";
const char* password = "987654321";


WebServer server(80);
void poweron(){
  Serial.println("Device power on");
}


void setup(void) {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.softAP(ssid, password);
  Serial.println("");


  server.on("/power/on",poweron);



  server.begin();
  Serial.println("HTTP server started");
  IPAddress IP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(IP);
  
}

void loop(void) {
  server.handleClient();
}
