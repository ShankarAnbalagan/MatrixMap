const int trigPin = 9;
const int echoPin = 10;
const int interruptPin=5;

float duration, distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(interruptPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(interruptPin, LOW);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = (duration*.0343)/2;
  Serial.print("Distance: ");
  Serial.println(distance);
  if(distance<15.00f)
    digitalWrite(interruptPin, LOW);
  else
    digitalWrite(interruptPin, HIGH);
  delay(500);
}
