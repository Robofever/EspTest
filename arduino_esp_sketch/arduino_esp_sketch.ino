/////Note this is a test code
/////The only purpose is to achieve a communication between arduino and and the given app
/////the following error occurs
////rst:0xc (SW_CPU_RESET),boot:0x13 (SPI_FAST_FLASH_BOOT)
////guru meditation error: core 1 panic'ed (loadprohibited). exception was unhandled.
//The above error keeps on occuring
//However if line 51(Code to print command) is removed then it vanishes
#include <WiFi.h>

#include <WiFiClient.h>

#include <WiFiServer.h>

#include <WebServer.h>



const char* ssid = "ESP";               //SSID 
const char* password = "987654321";     //Password


WebServer server(80);                   //Server at port 80
void poweron(){
  Serial.println("Device power on");
}


void setup(void) {
  Serial.begin(115200);                            
  WiFi.softAP(ssid, password);      //Start AP
  Serial.println("");


  server.on("/power/on",poweron);   //Handle server request



  server.begin();                   //Start Server
  Serial.println("HTTP server started");
  IPAddress IP = WiFi.softAPIP();
  Serial.print("AP IP address: ");       
  //Displays ipaddress
  Serial.println(IP);
  
}

void loop(void) {
  server.handleClient();                      //handle server requests
  WiFiClient client;                          
   char command = client.read();              //Read incoming messages
   Serial.println(command);                   //It prints the incoming char
   if (command == 'H') {                       //If incoming char has ASCII value of H
          Serial.println("Led is now on.");    //Print LED is on on serial monitor
   }
   else if (command == 'L') {
          Serial.println("Led is now off.");
   }        
}
