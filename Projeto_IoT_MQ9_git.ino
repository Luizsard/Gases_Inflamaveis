   #include <ESP8266WiFi.h>         
   #include <ESP8266HTTPClient.h>   

   // Configurações de WiFi e ThingSpeak
   const char* ssid = "Sua_SSID";
   const char* password = "Sua_Senha";
   const char* apiKey = "Sua_API_Key";
   const char* server = "http://api.thingspeak.com/update";
   const int channelID = 1430139;

   // Configurações do Buzzer e LED
   const int buzzerPin = D2;
   const int ledPin = D1;
   const int threshold = 400;

   void setup() {
     Serial.begin(115200);
     pinMode(buzzerPin, OUTPUT);  
     pinMode(ledPin, OUTPUT);
     WiFi.begin(ssid, password);
     while (WiFi.status() != WL_CONNECTED) {
       delay(1000);
       Serial.println("Conectando ao WiFi...");
     }
     Serial.println("Conectado ao WiFi!");
   }

   void loop() {
     int sensorValue = analogRead(A0);
     Serial.print("Valor do sensor MQ-9: ");
     Serial.println(sensorValue);

     if (sensorValue > threshold) {
       digitalWrite(buzzerPin, HIGH);
       digitalWrite(ledPin, HIGH);
       Serial.println("Alerta! Nível de gás elevado.");
     } else {
       digitalWrite(buzzerPin, LOW);
       digitalWrite(ledPin, LOW);
     }

     if (WiFi.status() == WL_CONNECTED) {
       WiFiClient client;
       HTTPClient http;
       String url = String(server) + "?api_key=" + apiKey + "&field1=" + String(sensorValue);
       http.begin(client, url);
       int httpResponseCode = http.GET();
       if (httpResponseCode > 0) {
         Serial.print("Código de resposta HTTP: ");
         Serial.println(httpResponseCode);
       } else {
         Serial.print("Erro ao enviar dados: ");
         Serial.println(httpResponseCode);
       }
       http.end();
     } else {
       Serial.println("Erro na conexão WiFi!");
     }
     delay(20000);
   }