const int motor_pin1=4;
const int motor_pin2=5;
const int turn_right=7;
const int turn_left=8;
const int xPin = 3;     
const int ledPin =  6;      

int i=0;
volatile int buttonState = 0;        

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(motor_pin1,OUTPUT);
  pinMode(motor_pin2,OUTPUT);
  pinMode(turn_right,OUTPUT);
  pinMode(turn_right,OUTPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(xPin, INPUT_PULLUP);
  attachInterrupt(1,blink, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite(motor_pin1, LOW);
  digitalWrite(motor_pin2, LOW);
  digitalWrite(turn_right, LOW);
  digitalWrite(turn_left, LOW);
  
  String directions="";
  int l=0;
  char ch;
  unsigned long time_start;
  if(Serial.available()){
    directions=Serial.readString();
    l=directions.length();
    for(int i=0;i<l;i++){
      ch=directions.charAt(i);
      Serial.println(ch);
      switch(ch){
        case 'F':
          time_start=millis();
          while(millis()-time_start<=2000){

            Serial.println("Going Front\n");
            
            digitalWrite(motor_pin1, HIGH);
            digitalWrite(motor_pin2, LOW);
            digitalWrite(turn_right, LOW);
            digitalWrite(turn_left, LOW);
          }
          break;
       case 'L':
          time_start=millis();
          while(millis()-time_start<=2000){

            Serial.println("Going Left\n");
            
            digitalWrite(motor_pin1, HIGH);
            digitalWrite(motor_pin2, LOW);
            digitalWrite(turn_right, LOW);
            digitalWrite(turn_left, HIGH);
          }
          break;
       case 'R':
          time_start=millis();
          while(millis()-time_start<=2000){

            Serial.println("Going Right\n");

            
            digitalWrite(motor_pin1, HIGH);
            digitalWrite(motor_pin2, LOW);
            digitalWrite(turn_right, HIGH);
            digitalWrite(turn_left, LOW);
          }
          break;
       case '\0':
          digitalWrite(motor_pin1, LOW);
          digitalWrite(motor_pin2, LOW);
          digitalWrite(turn_right, LOW);
          digitalWrite(turn_left, LOW);
      }
    }
  }
}
void blink() {
  digitalWrite(ledPin,!digitalRead(ledPin));
  digitalWrite(motor_pin1, LOW);
  digitalWrite(motor_pin2, LOW);
  digitalWrite(turn_right, LOW);
  digitalWrite(turn_left, LOW);
}
