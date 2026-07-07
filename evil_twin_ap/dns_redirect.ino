DNSServer dnsServer;
const byte DNS_PORT = 53;

void initDNSRedirect() {
  IPAddress apIP = WiFi.softAPIP();
  dnsServer.start(DNS_PORT, "*", apIP);
  Serial.println("DNS redirekcija aktivna - svi upiti vode na ESP8266.");
}

void processDNS() {
  dnsServer.processNextRequest();
}
