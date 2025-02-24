#include <DHT.h>

#define DHT11_PIN 4
#define DHTTYPE DHT11
int ALARM = 6; // Định nghĩa chân Buzzer là chân số 4
float sinVal; 
int toneVal;

DHT dht11(DHT11_PIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht11.begin();
  pinMode(ALARM, OUTPUT);
  Serial.println("DHT11 TEST PROGRAM");
  Serial.println();
  Serial.println("Type\tStatus\tHumidity (%)\tTemperature (\"C\")");
}

void loop() {
//  delay(400);
//  
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
    for (int x = 0; x < 180; x++) { 
            sinVal = sin(x * (3.1412 / 180.0)); // Chuyển đổi sin thành radian
            toneVal = 2000 + (int)(sinVal * 1000); // Sử dụng sin để tạo tần số âm thanh
            tone(ALARM, toneVal); 
            delay(2);
        }
  } else { 
        noTone(ALARM);
  }
}
