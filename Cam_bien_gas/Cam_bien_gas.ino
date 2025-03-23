const int gasSensorPin = A0;
const int speakerPin = 13;

void setup() {
  pinMode(gasSensorPin, INPUT);
  pinMode(speakerPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int gasValue = analogRead(gasSensorPin);
  Serial.print("Gas Value: ");
  Serial.println(gasValue);

  if (gasValue > 500) {
    for (int i = 0; i < 127; i++) {
      int value = 128 + 127 * sin(i * 2 * PI / 180);
      analogWrite(speakerPin, value);
      delayMicroseconds(500);
    }
  } else {
    noTone(speakerPin);
  }

  delay(1000);
}
