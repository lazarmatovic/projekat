#include <ESP8266WiFi.h>
#include <DNSServer.h>
#include <ESP8266WebServer.h>

void setup() {
  Serial.begin(9600); 

  initAP();          
  initDNSRedirect();  
  initWebServer();    

  Serial.println("Sistem pokrenut. Ceka se konekcija uredjaja...");
}

void loop() {
  processDNS();       
  processWebServer();  
}
