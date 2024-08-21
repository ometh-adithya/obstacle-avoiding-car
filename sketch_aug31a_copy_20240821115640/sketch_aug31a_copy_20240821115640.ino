#include <Servo.h>
Servo s = Servo();

#include <Ultrasonic.h>
Ultrasonic u = Ultrasonic(3, 4);

int ENA = 11;
int IN1 = 10;
int IN2 = 9;

int ENB = 5;
int IN3 = 7;
int IN4 = 6;

void setup() {
  // put your setup code here, to run once:
  s.attach(2);

  //LED
  pinMode(13, OUTPUT);  //RED
  pinMode(12, OUTPUT);  //BLUE
  pinMode(8, OUTPUT);   //GREEN


  //MOTOR A
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  analogWrite(ENA, 250);

  //MOTOR B
  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  analogWrite(ENB, 250);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly

  //red13
  digitalWrite(13, HIGH);
  delay(100);
  digitalWrite(13, LOW);
  delay(50);

  //BLUE12
  digitalWrite(12, HIGH);
  delay(100);
  digitalWrite(12, LOW);
  delay(50);

  //GREEN8
  digitalWrite(8, HIGH);
  delay(100);
  digitalWrite(8, LOW);
  delay(50);

  int x = Serial.read();

  // forward
  if (x == '1') {
    s.write(90);
    delay(300);
    int d = u.read();
    if (d > 20) {
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
    }
  }

  // reverse
  if (x == '2') {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    delay(500);
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
  }

  // Stop
  if (x == '3') {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
  }

  // turn right
  if (x == '4') {
    s.write(0);
    delay(300);
    int d = u.read();
    if (d > 20) {
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
      delay(500);
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, LOW);
    }
    s.write(90);
  }

  // turn left
  if (x == '5') {
    s.write(180);
    delay(300);
    digitalWrite(12, HIGH);
    digitalWrite(8, LOW);
    int d = u.read();
    if (d > 20) {

      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
      delay(500);
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, LOW);
    }
    s.write(90);
  }
}