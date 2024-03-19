/*
#include <Servo.h>

Servo gripperServo;
#define  servoPin 6
int maxSteps = 90;

//joint 1
#define dirPin1 34
#define stepPin1 36

//joint 2
#define dirPin1 28
#define stepPin1 26

//joint 3
#define dirPin1 55
#define stepPin1 54

//joint 4
#define dirPin1 48
#define stepPin1 46

//joint 5
#define dirPin1 61
#define stepPin1 60

#define stepsPerRevolution 3

void setup() {
  Serial.begin(9600);

  //Gripper
  gripperServo.attach(6);

  // Declaring pins as output:
  pinMode(stepPin1, OUTPUT);
  pinMode(dirPin1, OUTPUT);
  pinMode(stepPin2, OUTPUT);
  pinMode(dirPin2, OUTPUT);
  pinMode(stepPin3, OUTPUT);
  pinMode(dirPin3, OUTPUT);
  pinMode(stepPin4, OUTPUT);
  pinMode(dirPin4, OUTPUT);
  pinMode(stepPin5, OUTPUT);
  pinMode(dirPin5, OUTPUT);
}

void loop() {
 if (Serial.available() > 0) {  // If data is available to read
    String data = Serial.readStringUntil('\n');
char *ankleStr, *directionStr, *stepsStr;
char *str = strdup(data.c_str()); // Convert String to C-style string

// Tokenize the string using strtok()
ankleStr = strtok(str, "-");
directionStr = strtok(NULL, "-");
stepsStr = strtok(NULL, "-");

// Convert strings to integers
int ankle = atoi(ankleStr);
int direction = atoi(directionStr);
int steps = atoi(stepsStr);

  switch (ankle) {
    case 1:
      if (direction == 1) {
        digitalWrite(dirPin1, HIGH);
        for (int i = 0; i < steps; i++) {
          if(i <= steps - (3*(steps/4)) ){
            digitalWrite(stepPin1, HIGH);
          delayMicroseconds(1000);
          digitalWrite(stepPin1, LOW);
          delayMicroseconds(1000);
          } 
          if(i > steps - (3*(steps/4)) && i <= steps - (steps/4)){
            digitalWrite(stepPin1, HIGH);
          delayMicroseconds(500);
          digitalWrite(stepPin1, LOW);
          delayMicroseconds(500);
          } 
          if(i > steps - (steps/4) ){
            digitalWrite(stepPin1, HIGH);
          delayMicroseconds(1000);
          digitalWrite(stepPin1, LOW);
          delayMicroseconds(1000);
          } 
        }
      } else if (direction == 0) {
        digitalWrite(dirPin1, LOW);
        for (int i = 0; i < steps; i++) {
           if(i <= steps - (3*(steps/4)) ){
            digitalWrite(stepPin1, HIGH);
          delayMicroseconds(1000);
          digitalWrite(stepPin1, LOW);
          delayMicroseconds(1000);
          } 
          if(i > steps - (3*(steps/4)) && i <= steps - (steps/4)){
            digitalWrite(stepPin1, HIGH);
          delayMicroseconds(500);
          digitalWrite(stepPin1, LOW);
          delayMicroseconds(500);
          } 
          if(i > steps - (steps/4) ){
            digitalWrite(stepPin1, HIGH);
          delayMicroseconds(1000);
          digitalWrite(stepPin1, LOW);
          delayMicroseconds(1000);
          }
        }
      }
      break;
    case 2:
      if (direction == 1) {
        digitalWrite(dirPin2, HIGH);
        for (int i = 0; i < steps; i++) {
           if(i <= steps - (3*(steps/4)) ){
            digitalWrite(stepPin2, HIGH);
          delayMicroseconds(1000);
          digitalWrite(stepPin2, LOW);
          delayMicroseconds(1000);
          } 
          if(i > steps - (3*(steps/4)) && i <= steps - (steps/4)){
            digitalWrite(stepPin2, HIGH);
          delayMicroseconds(500);
          digitalWrite(stepPin2, LOW);
          delayMicroseconds(500);
          } 
          if(i > steps - (steps/4) ){
            digitalWrite(stepPin2, HIGH);
          delayMicroseconds(1000);
          digitalWrite(stepPin2, LOW);
          delayMicroseconds(1000);
          };
        }
      } else if (direction == 0) {
        digitalWrite(dirPin2, LOW);
        for (int i = 0; i < steps; i++) {
           if(i <= steps - (3*(steps/4)) ){
            digitalWrite(stepPin2, HIGH);
          delayMicroseconds(1000);
          digitalWrite(stepPin2, LOW);
          delayMicroseconds(1000);
          } 
          if(i > steps - (3*(steps/4)) && i <= steps - (steps/4)){
            digitalWrite(stepPin2, HIGH);
          delayMicroseconds(500);
          digitalWrite(stepPin2, LOW);
          delayMicroseconds(500);
          } 
          if(i > steps - (steps/4) ){
            digitalWrite(stepPin2, HIGH);
          delayMicroseconds(1000);
          digitalWrite(stepPin2, LOW);
          delayMicroseconds(1000);
          };
        }
      }
      break;
    case 3:
      if (direction == 1) {
        digitalWrite(dirPin3, HIGH);
        for (int i = 0; i < steps; i++) {
           if(i <= steps - (3*(steps/4)) ){
            digitalWrite(stepPin3, HIGH);
          delayMicroseconds(1000);
          digitalWrite(stepPin3, LOW);
          delayMicroseconds(1000);
          } 
          if(i > steps - (3*(steps/4)) && i <= steps - (steps/4)){
            digitalWrite(stepPin3, HIGH);
          delayMicroseconds(500);
          digitalWrite(stepPin3, LOW);
          delayMicroseconds(500);
          } 
          if(i > steps - (steps/4) ){
            digitalWrite(stepPin3, HIGH);
          delayMicroseconds(1000);
          digitalWrite(stepPin3, LOW);
          delayMicroseconds(1000);
          }
        }
      } else if (direction == 0) {
        digitalWrite(dirPin3, LOW);
        for (int i = 0; i < steps; i++) {
           if(i <= steps - (3*(steps/4)) ){
            digitalWrite(stepPin3, HIGH);
          delayMicroseconds(1000);
          digitalWrite(stepPin3, LOW);
          delayMicroseconds(1000);
          } 
          if(i > steps - (3*(steps/4)) && i <= steps - (steps/4)){
            digitalWrite(stepPin3, HIGH);
          delayMicroseconds(500);
          digitalWrite(stepPin3, LOW);
          delayMicroseconds(500);
          } 
          if(i > steps - (steps/4) ){
            digitalWrite(stepPin3, HIGH);
          delayMicroseconds(1000);
          digitalWrite(stepPin3, LOW);
          delayMicroseconds(1000);
          }
        }
      }
      break;
    case 4:
      if (direction == 1) {
        digitalWrite(dirPin4, HIGH);
        for (int i = 0; i < steps; i++) {
           if(i <= steps - (3*(steps/4)) ){
            digitalWrite(stepPin4, HIGH);
          delayMicroseconds(1000);
          digitalWrite(stepPin4, LOW);
          delayMicroseconds(1000);
          } 
          if(i > steps - (3*(steps/4)) && i <= steps - (steps/4)){
            digitalWrite(stepPin4, HIGH);
          delayMicroseconds(500);
          digitalWrite(stepPin4, LOW);
          delayMicroseconds(500);
          } 
          if(i > steps - (steps/4) ){
            digitalWrite(stepPin4, HIGH);
          delayMicroseconds(1000);
          digitalWrite(stepPin4, LOW);
          delayMicroseconds(1000);
          }
        }
      } else if (direction == 0) {
        digitalWrite(dirPin4, LOW);
        for (int i = 0; i < steps; i++) {
           if(i <= steps - (3*(steps/4)) ){
            digitalWrite(stepPin4, HIGH);
          delayMicroseconds(1000);
          digitalWrite(stepPin4, LOW);
          delayMicroseconds(1000);
          } 
          if(i > steps - (3*(steps/4)) && i <= steps - (steps/4)){
            digitalWrite(stepPin4, HIGH);
          delayMicroseconds(500);
          digitalWrite(stepPin4, LOW);
          delayMicroseconds(500);
          } 
          if(i > steps - (steps/4) ){
            digitalWrite(stepPin4, HIGH);
          delayMicroseconds(1000);
          digitalWrite(stepPin4, LOW);
          delayMicroseconds(1000);
          }
        }
      }
      break;
    case 5:
      if (direction == 1) {
        digitalWrite(dirPin5, HIGH);
        for (int i = 0; i < steps; i++) {
           if(i <= steps - (3*(steps/4)) ){
            digitalWrite(stepPin5, HIGH);
          delayMicroseconds(1000);
          digitalWrite(stepPin5, LOW);
          delayMicroseconds(1000);
          } 
          if(i > steps - (3*(steps/4)) && i <= steps - (steps/4)){
            digitalWrite(stepPin5, HIGH);
          delayMicroseconds(500);
          digitalWrite(stepPin5, LOW);
          delayMicroseconds(500);
          } 
          if(i > steps - (steps/4) ){
            digitalWrite(stepPin5, HIGH);
          delayMicroseconds(1000);
          digitalWrite(stepPin5, LOW);
          delayMicroseconds(1000);
          }
        }
      } else if (direction == 0) {
        digitalWrite(dirPin5, LOW);
        for (int i = 0; i < steps; i++) {
           if(i <= steps - (3*(steps/4)) ){
            digitalWrite(stepPin5, HIGH);
          delayMicroseconds(1000);
          digitalWrite(stepPin5, LOW);
          delayMicroseconds(1000);
          } 
          if(i > steps - (3*(steps/4)) && i <= steps - (steps/4)){
            digitalWrite(stepPin5, HIGH);
          delayMicroseconds(500);
          digitalWrite(stepPin5, LOW);
          delayMicroseconds(500);
          } 
          if(i > steps - (steps/4) ){
            digitalWrite(stepPin5, HIGH);
          delayMicroseconds(1000);
          digitalWrite(stepPin5, LOW);
          delayMicroseconds(1000);
          }
        }
      }
      break;
      case 6:
      if(steps <= maxSteps)
      {
        gripperServo.write(steps);
        delay(1000); 
      }
      break;
    default:
      Serial.println("Wrong input");
    }
  }
}*/