int LINE = 2;
int val = 0;
int led = 13;

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
}
