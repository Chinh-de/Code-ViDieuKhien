int ledpin = 13;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ledpin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0) {
    String setupled = Serial.readString();
    setupled.trim();
    if (setupled == "on") {
      digitalWrite(ledpin, HIGH);
    } else if (setupled == "off") {
      digitalWrite(ledpin, LOW);
    } else {
      Serial.print("Invalid input");
    }
  }
}
