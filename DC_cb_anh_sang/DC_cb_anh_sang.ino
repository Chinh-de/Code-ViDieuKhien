#define IN1 5
#define IN2 6
//#define ENA 9  // Chân PWM điều chỉnh tốc độ (nếu cần)

int LIGHT=0; 
int val=0; 


void setup() {
    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);
    Serial.begin(9600); 

//    pinMode(ENA, OUTPUT);
//    analogWrite(ENA, 200); // Đặt tốc độ động cơ (0 - 255)
}

void loop() {
  val=analogRead(LIGHT); 
  Serial.println(val); 
  if (val<500) 
  {
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    delay(100);    
  }
  else 
  {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    delay(100);
  }

}
