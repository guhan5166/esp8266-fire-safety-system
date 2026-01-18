#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <time.h>

#define FLAME_PIN D5
#define GAS_PIN A0
#define BUZZER_PIN D6

const char* ssid = "YOUR_WIFI_NAME";
const char* password = "YOUR_WIFI_PASSWORD";

ESP8266WebServer server(80);

int gasThreshold = 400;
bool fireDetected = false;

void handleRoot() {
  int gasValue = analogRead(GAS_PIN);
  int flameValue = digitalRead(FLAME_PIN);

  fireDetected = (flameValue == LOW || gasValue > gasThreshold);

  time_t now = time(nullptr);
  struct tm* timeinfo = localtime(&now);

  char timeStr[60];
  strftime(timeStr, sizeof(timeStr), "%A | %d %B %Y | %H:%M:%S", timeinfo);

  String page = "<!DOCTYPE html><html><head>";
  page += "<meta http-equiv='refresh' content='1'>";
  page += "<meta name='viewport' content='width=device-width, initial-scale=1.0'>";
  page += "<style>";

  if (fireDetected) {
    page += "body{background:#b00000;}";
  } else {
    page += "body{background:#0b1f0b;}";
  }

  page += "body{margin:0;height:100vh;display:flex;align-items:center;justify-content:center;";
  page += "font-family:'Segoe UI','Inter','Roboto',Arial,sans-serif;color:white;}";

  page += ".panel{";
  page += "width:85%;max-width:900px;";
  page += "padding:60px 50px;";
  page += "background:rgba(0,0,0,0.35);";
  page += "backdrop-filter:blur(10px);";
  page += "border-radius:18px;";
  page += "box-shadow:0 20px 50px rgba(0,0,0,0.5);";
  page += "text-align:center;}";

  page += ".title{font-size:72px;font-weight:800;letter-spacing:4px;}";
  page += ".status{font-size:48px;font-weight:700;margin-top:20px;}";
  page += ".time{font-size:34px;margin-top:35px;font-weight:500;}";
  page += ".details{font-size:22px;margin-top:30px;opacity:0.9;}";

  page += "</style></head><body>";

  page += "<div class='panel'>";

  if (fireDetected) {
    page += "<div class='title'>EMERGENCY</div>";
    page += "<div class='status'>FIRE DETECTED</div>";
  } else {
    page += "<div class='title'>SYSTEM NORMAL</div>";
    page += "<div class='status'>NO FIRE CONDITION</div>";
  }

  page += "<div class='time'>";
  page += timeStr;
  page += "</div>";

  page += "<div class='details'>";
  page += "Gas Level: ";
  page += String(gasValue);
  page += " | Flame Sensor: ";
  page += (flameValue == LOW ? "ACTIVE" : "INACTIVE");
  page += "</div>";

  page += "</div></body></html>";

  server.send(200, "text/html", page);
}

void setup() {
  Serial.begin(9600);

  pinMode(FLAME_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  configTime(19800, 0, "pool.ntp.org", "time.nist.gov");

  Serial.println("\nConnected");
  Serial.print("Dashboard IP: ");
  Serial.println(WiFi.localIP());

  server.on("/", handleRoot);
  server.begin();
}

void loop() {
  server.handleClient();

  if (fireDetected) {
    digitalWrite(BUZZER_PIN, HIGH);
  } else {
    digitalWrite(BUZZER_PIN, LOW);
  }
}
