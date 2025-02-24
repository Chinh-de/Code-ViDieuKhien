#include <DHT.h>

#define DHT11_PIN 4
#define DHTTYPE DHT11

DHT dht11(DHT11_PIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht11.begin();
  Serial.println("DHT11 TEST PROGRAM");
  Serial.println();
  Serial.println("Type\tStatus\tHumidity (%)\tTemperature (\"C\")");
}

void loop() {
  delay(400);
  
  float h = dht11.readHumidity();
  float t = dht11.readTemperature();
  
  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  
  Serial.print("DHT11\tOK\t");
  Serial.print(h);
  Serial.print("%\t\t");
  Serial.print(t);
  Serial.println("°C");
}
