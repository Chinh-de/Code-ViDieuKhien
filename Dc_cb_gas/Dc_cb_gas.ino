#define IN1 5
#define IN2 6
#define ENA 9  // Chân PWM điều chỉnh tốc độ (nếu cần)

const int gasSensorPin = A0;
int gasValue = 0;

void setup() {
    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);
    pinMode(gasSensorPin, INPUT);
    Serial.begin(9600);
    pinMode(ENA, OUTPUT);
    analogWrite(ENA, 220); // Đặt tốc độ động cơ (0 - 255)
}

void loop() {
    gasValue = analogRead(gasSensorPin);
    Serial.print("Gas Value: ");
    Serial.println(gasValue);
  
    if (gasValue > 500) {
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      delay(1000);
    } else {
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      delay(1000);
    }

}
