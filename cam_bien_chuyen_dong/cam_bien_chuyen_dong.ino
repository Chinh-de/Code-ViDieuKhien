//int pirPin = 2;
//int ledPin = 13;
//
//void setup() {
//  pinMode(pirPin, INPUT);
//  pinMode(ledPin, OUTPUT);
//  Serial.begin(9600);
//}
//
//void loop() {
//  int sensorValue = digitalRead(pirPin);
//  if (sensorValue == HIGH) {
//    digitalWrite(ledPin, HIGH);
//    Serial.println("Phat hien chuyen dong!");
//  } else {
//    digitalWrite(ledPin, LOW);
//    Serial.println("Khong co chuyen dong.");
//  }
//  delay(300);
//}


int pirPin = 2;
int ledPin = 13;
unsigned long previousMillis = 0;
const long interval = 200; // Kiểm tra mỗi 50ms

void setup() {
  pinMode(pirPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  unsigned long currentMillis = millis();
  
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    
    int sensorValue = digitalRead(pirPin);
    if (sensorValue == HIGH) {
      digitalWrite(ledPin, HIGH);
      Serial.println("Phát hiện chuyển động!");
    } else {
      digitalWrite(ledPin, LOW);
      Serial.println("Không có chuyển động.");
    }
  }
}
