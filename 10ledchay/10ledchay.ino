#define LED_START 4   // Chân LED bắt đầu
#define LED_END 13    // Chân LED kết thúc

void setup() {
  for (int i = LED_START; i <= LED_END; i++) {
    pinMode(i, OUTPUT); // Cấu hình tất cả các chân LED là OUTPUT
  }
}

void loop() {
  for (int i = LED_START; i <= LED_END; i++) {
    digitalWrite(i, HIGH); // Bật LED
    delay(200);            // Chờ 200ms
    digitalWrite(i, LOW);  // Tắt LED
  }
}
