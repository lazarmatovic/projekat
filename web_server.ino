ESP8266WebServer server(80);

const char PLACEHOLDER_PAGE[] = R"====(
<!DOCTYPE html>
<html>
<head><meta charset="UTF-8"><title>Captive Portal - Placeholder</title></head>
<body </h2>
  <p></p>
</body>
</html>
)====";

void handleRoot() {
  server.send(200, "text/html", PLACEHOLDER_PAGE);
}

void handleNotFound() {

  server.sendHeader("Location", "/", true);
  server.send(302, "text/plain", "");
}

void initWebServer() {
  server.on("/", handleRoot);
  server.onNotFound(handleNotFound);
  server.begin();
  Serial.println("Web server pokrenut na portu 80.");
}

void processWebServer() {
  server.handleClient(); 
}
