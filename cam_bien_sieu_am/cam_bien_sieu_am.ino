const int trigPin = 5;
const int echoPin = 3;
long duration;
int distance;
int led =13;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(led, OUTPUT);
  pinMode(echoPin, INPUT);
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
    digitalWrite(led, HIGH);
  } else if (distance <= 20){
    digitalWrite(led, LOW);
    delay(200);
    digitalWrite(led, HIGH);
  } else {
    digitalWrite(led, LOW);
  }
  delay(200);
}
