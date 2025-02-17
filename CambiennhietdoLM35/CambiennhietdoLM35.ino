//Trái qua phải: vcc, a0, gnd 

int ALARM = 4; // Định nghĩa chân Buzzer là chân số 4
int LM35 = A0; // Kết nối cảm biến LM35 đến chân Analog 0
float tmprVal = 0; // Giá trị nhiệt độ
float sinVal; 
int toneVal; 
unsigned long tepTimer = 0; // Biến thời gian

void setup() { 
    Serial.begin(9600); // Cấu hình baud rate 9600 bps
    pinMode(ALARM, OUTPUT); // Cấu hình chân Buzzer là Output
}

void loop() { 
    int val = analogRead(LM35); // Đọc giá trị từ cảm biến LM35
    tmprVal = (float)val * (5.0 / 10.24); // Chuyển đổi giá trị điện áp thành nhiệt độ

    if (tmprVal > 31.5) { // Nếu nhiệt độ > 27°C, bật còi báo động
        for (int x = 0; x < 180; x++) { 
            sinVal = sin(x * (3.1412 / 180.0)); // Chuyển đổi sin thành radian
            toneVal = 2000 + (int)(sinVal * 1000); // Sử dụng sin để tạo tần số âm thanh
            tone(ALARM, toneVal); // Phát âm thanh ở tần số toneVal
            delay(2);
        }
    } else { // Nếu nhiệt độ <= điều  kiện°C, tắt còi
        noTone(ALARM);
    }

    // Cứ mỗi 500ms, in giá trị nhiệt độ ra Serial
    if (millis() - tepTimer > 500) { 
        tepTimer = millis(); 
        Serial.print("Temperature: "); 
        Serial.print(tmprVal); 
        Serial.println("C"); 
    } 
}
