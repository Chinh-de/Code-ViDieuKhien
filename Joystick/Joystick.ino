const int gasSensorPin = A0;
const int LED = 13;
float sinVal;
int toneVal;
void setup() {
  pinMode(gasSensorPin, INPUT);
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int gasValue = analogRead(gasSensorPin);
  Serial.print("Gas Value: ");
  Serial.println(gasValue);

  if (gasValue > 400) {
    digitalWrite(LED,HIGH);
  } else {
    digitalWrite(LED,LOW);
  }

  delay(100);
}
