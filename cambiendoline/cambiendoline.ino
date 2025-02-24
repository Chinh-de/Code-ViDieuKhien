//phản xạ line trắng
//hấp thụ là line đen, ko có gì là line đen, or hấp thụ hết gần như hoàn toàn là line đen

int LINE = 2;
int val = 0;
int led = 13;

//int ALARM = 6; // Định nghĩa chân Buzzer là chân số 4
//float sinVal; 
//int toneVal;


void setup() {
    pinMode(led, OUTPUT);
    pinMode(LINE, INPUT);
    Serial.begin(9600); 
}

void loop() {
    val = digitalRead(LINE);
    Serial.println(val);
    if (val == 1) {
        digitalWrite(led, HIGH);  // Bật đèn LED
    } else {
        digitalWrite(led, LOW);   // Tắt đèn LED
    }

//    if(val == 1){
//    for (int x = 0; x < 180; x++) { 
//            sinVal = sin(x * (3.1412 / 180.0)); // Chuyển đổi sin thành radian
//            toneVal = 2000 + (int)(sinVal * 1000); // Sử dụng sin để tạo tần số âm thanh
//            tone(ALARM, toneVal); 
//            delay(2);
//        }
//  } else { 
//        noTone(ALARM);
//  }
}
