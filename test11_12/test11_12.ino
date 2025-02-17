int value = HIGH;

void setup() {
 pinMode(11, OUTPUT);
 pinMode(12, OUTPUT);
 pinMode(7, INPUT);
}

void loop() {
  for(int i = 11; i<13; i++)
  {
    
    //value = analogRead(0)/4;
    digitalWrite(i, value);
    delay(500); 
    digitalWrite(i, LOW);  
    value = digitalRead(2); 
  }
 
  

}
