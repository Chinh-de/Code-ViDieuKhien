#define IN1 5
#define IN2 6
#define ENA 9  // Chân PWM điều chỉnh tốc độ (nếu cần)
const int trigPin = 12;
const int echoPin = 11;
long duration;
int distance;

void setup() {
    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);
    pinMode(ENA, OUTPUT);
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
//    digitalWrite(IN1, HIGH);
//    digitalWrite(IN2, LOW);
//    analogWrite(ENA, 200); // Đặt tốc độ động cơ (0 - 255)
    Serial.begin(9600);
}

void loop() {
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    distance = duration * 0.034 / 2;
    Serial.print("Distance Measured=");
    Serial.print(distance);
    Serial.println("cm");
    
    if(distance <= 10){
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      delay(100);
    } else {
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      delay(100);
    
    }
    delay(200);
}
