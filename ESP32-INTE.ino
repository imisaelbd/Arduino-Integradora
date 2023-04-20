#include <WiFi.h>
#include <HTTPClient.h>

#define RXp2 16
#define TXp2 17

String prueba = "";

const char* ssid = "Integradora";
const char* password = "123456789";

void setup() {
  Serial.begin(115200);
  Serial2.begin(9600, SERIAL_8N1, RXp2, TXp2);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Conectando a la red WiFi!");
  }
  Serial.println("Conectado exitosamente!");
}

void loop() {
  if (WiFi.status() == WL_CONNECTED) {
    if (Serial2.available()) {
      prueba = Serial2.readStringUntil('\n');
      Serial.println(prueba);
      int opc = prueba.toInt();
      HTTPClient http;
      int httpResponseCode;
      switch (opc) {
        case 1:
          Serial.println("GET BTN 1");
          http.begin("http://54.197.163.83:8080/api/alarma/activate/1/idInstitucion/c471db15-c8ea-4a4f-b40e-134be3e1469d");

          httpResponseCode = http.GET();

          if (httpResponseCode > 0) {
            Serial.printf("Codigo de respuesta HTTP: %d\n", httpResponseCode);
            String response = http.getString();
            Serial.println(response);
          } else {
            Serial.printf("Error: %s\n", http.errorToString(httpResponseCode).c_str());
          }
          http.end();
          break;
        case 2:
          Serial.println("GET BTN 2");
          http.begin("http://54.197.163.83:8080/api/alarma/activate/2/idInstitucion/c471db15-c8ea-4a4f-b40e-134be3e1469d");

          httpResponseCode = http.GET();

          if (httpResponseCode > 0) {
            Serial.printf("Codigo de respuesta HTTP: %d\n", httpResponseCode);
            String response = http.getString();
            Serial.println(response);
          } else {
            Serial.printf("Error: %s\n", http.errorToString(httpResponseCode).c_str());
          }
          http.end();
          break;
        case 3:
          Serial.println("GET BTN 3");
          http.begin("http://54.197.163.83:8080/api/alarma/activate/3/idInstitucion/c471db15-c8ea-4a4f-b40e-134be3e1469d");

          httpResponseCode = http.GET();

          if (httpResponseCode > 0) {
            Serial.printf("Codigo de respuesta HTTP: %d\n", httpResponseCode);
            String response = http.getString();
            Serial.println(response);
          } else {
            Serial.printf("Error: %s\n", http.errorToString(httpResponseCode).c_str());
          }
          http.end();
          break;
        case 4:
          Serial.println("GET BTN 4");
          http.begin("http://54.197.163.83:8080/api/alarma/activate/4/idInstitucion/c471db15-c8ea-4a4f-b40e-134be3e1469d");

          httpResponseCode = http.GET();

          if (httpResponseCode > 0) {
            Serial.printf("Codigo de respuesta HTTP: %d\n", httpResponseCode);
            String response = http.getString();
            Serial.println(response);
          } else {
            Serial.printf("Error: %s\n", http.errorToString(httpResponseCode).c_str());
          }
          http.end();
          break;
        default:
          Serial.println("?!");
          break;
      }
    }
  }
}