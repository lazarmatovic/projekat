const char* AP_SSID = "Free_WiFi";

void initAP() {
  WiFi.mode(WIFI_AP);

  WiFi.softAP(AP_SSID);

  Serial.print("Access Point pokrenut, SSID: ");
  Serial.println(AP_SSID);
  Serial.print("IP adresa AP-a: ");
  Serial.println(WiFi.softAPIP());
}
