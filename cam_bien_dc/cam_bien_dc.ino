#define IN1 5
#define IN2 6
//#define ENA 9  // Chân PWM điều chỉnh tốc độ (nếu cần)

void setup() {
    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);
//    pinMode(ENA, OUTPUT);
//    analogWrite(ENA, 200); // Đặt tốc độ động cơ (0 - 255)
}

void loop() {
    // Quay theo chiều thuận
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    delay(1000); // Chạy 1 giây

    // Dừng động cơ 0.1s (để tránh sốc)
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    delay(100);

    // Quay ngược chiều
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    delay(1000);

    // Dừng động cơ 0.1s
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    delay(100);
}
