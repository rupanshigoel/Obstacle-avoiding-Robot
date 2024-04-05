const int trigPin = 8;
const int echoPin = 9;
const int in1 = 2;
const int in2 = 4;
const int in3 = 7;
const int in4 = 5;

const int en1 = 3;
const int en2 = 6;

void setup() 
{
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode (in1, OUTPUT);
  pinMode (in2, OUTPUT);
  pinMode (in3, OUTPUT);
  pinMode (in4, OUTPUT);
  pinMode (en1, OUTPUT);
  pinMode (en2, OUTPUT);
  Serial.begin(9600);
}
long duration, distance;

void loop()
{ 
  analogWrite(en1, 80);    
  analogWrite(en2, 80);    
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);  
  duration = pulseIn(echoPin, HIGH);
  distance = duration/58.2;
  Serial.println(distance);
  if(distance<30)
    {
      stop();
      delay(500);
      backward();
      delay(500);
      turn();
      delay(500);
    }
    
  else
    {
      forward();
    }  
}

void backward() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void forward() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void turn(){
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void stop(){
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);  
}
