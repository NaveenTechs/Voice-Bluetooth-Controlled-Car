
/*
  Voice & Bluetooth Controlled Car
  Arduino UNO + HC-05 + L298N + 4 DC Motors

  Commands:
  F = Forward
  B = Backward
  L = Left
  R = Right
  S = Stop
*/

const int IN1 = 5;
const int IN2 = 6;
const int IN3 = 7;
const int IN4 = 8;

const int ENA = 9;
const int ENB = 10;

char command;

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  Serial.begin(9600);

  stopCar();
}

void loop() {
  if (Serial.available() > 0) {
    command = Serial.read();

    switch (command) {
      case 'F':
      case 'f':
        forward();
        break;

      case 'B':
      case 'b':
        backward();
        break;

      case 'L':
      case 'l':
        left();
        break;

      case 'R':
      case 'r':
        right();
        break;

      case 'S':
      case 's':
        stopCar();
        break;
    }
  }
}

void forward() {
  analogWrite(ENA, 200);
  analogWrite(ENB, 200);

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void backward() {
  analogWrite(ENA, 200);
  analogWrite(ENB, 200);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void left() {
  analogWrite(ENA, 200);
  analogWrite(ENB, 200);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void right() {
  analogWrite(ENA, 200);
  analogWrite(ENB, 200);

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void stopCar() {
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
