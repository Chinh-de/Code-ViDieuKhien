#include <DHT.h>


#define IN1 5
#define IN2 6
#define ENA 9  // Chân PWM điều chỉnh tốc độ (nếu cần)
#define DHT11_PIN 4
#define DHTTYPE DHT11

DHT dht11(DHT11_PIN, DHTTYPE);

void setup() {
    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);
    pinMode(ENA, OUTPUT);
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    Serial.begin(9600);
    dht11.begin();
    Serial.println("DHT11 TEST PROGRAM");
    Serial.println();
    Serial.println("Type\tStatus\tHumidity (%)\tTemperature (\"C\")");
}

void loop() {
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

  if(h>=75){
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    delay(100);
  } else { 
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    delay(100);
  }
}
