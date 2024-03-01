/* Example sketch to control a stepper motor with TB6560 stepper motor driver and Arduino without a library. More info: https://www.makerguides.com */

// Define stepper motor connections and steps per revolution:
/* int buttonPin1 = 7;
int buttonPin2 = 4;

#define dirPin 2
#define stepPin 3
#define stepsPerRevolution 3

void setup() {
  Serial.begin(9600);
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  // Declare pins as output:
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
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

// Now ankle, direction, and steps hold the respective integer values


    // Scenario 1: Handling angle and steps data
    if (data.startsWith("13,")) {
      String infoData = data.substring(3);
      int delimiterIndex = infoData.indexOf('-');                       // Find the index of the '-' character
      if (delimiterIndex != -1) {                                       // Check if the delimiter exists in the string
        int direction = infoData.substring(0, delimiterIndex).toInt();  // Extract the substring before the '-'
        int angleSteps = infoData.substring(delimiterIndex + 1).toInt();    // Extract the angle substring and convert to an integer

        if (direction == 1) {
          digitalWrite(dirPin, HIGH);
          for (int i = 0; i < angleSteps; i++) {
            digitalWrite(stepPin, HIGH);
            delayMicroseconds(1000);
            digitalWrite(stepPin, LOW);
            delayMicroseconds(1000);
          }  // Write the direction to pin 2
        } else if (direction == 0) {
          digitalWrite(dirPin, LOW);
          for (int i = 0; i < angleSteps; i++) {
            // These four lines result in 1 step:
            digitalWrite(stepPin, HIGH);
            delayMicroseconds(1000);
            digitalWrite(stepPin, LOW);
            delayMicroseconds(1000);
          }
        }
      }
    }

    // Scenario 2: Handling direction pin commands for specific pins
    if (data.startsWith("2,") || data.startsWith("8,")) {  // Check if the command is for direction pin
      int pin = data.startsWith("2,") ? dirPin : 8;
      int revSteps = (pin == 8) ? 200 : 800;      // Determine the number of steps based on the pin
      int direction = data.substring(2).toInt();  // Extract direction (0 or 1)
      if (direction == 1) {
        digitalWrite(dirPin, HIGH);
        for (int i = 0; i < revSteps; i++) {
          digitalWrite(stepPin, HIGH);
          delayMicroseconds(1000);
          digitalWrite(stepPin, LOW);
          delayMicroseconds(1000);
        }  // Write the direction to pin 2
      } else if (direction == 0) {
        digitalWrite(dirPin, LOW);
        for (int i = 0; i < revSteps; i++) {
          // These four lines result in 1 step:
          digitalWrite(stepPin, HIGH);
          delayMicroseconds(1000);
          digitalWrite(stepPin, LOW);
          delayMicroseconds(1000);
        }
      }
    }

}



  //physical buttons
  int buttonState1 = digitalRead(buttonPin1);
  int buttonState2 = digitalRead(buttonPin2);

  if (buttonState1 == HIGH) {  // Set the spinning direction clockwise:
    digitalWrite(dirPin, HIGH);

    // Spin the stepper motor 1 revolution slowly:
    for (int i = 0; i < stepsPerRevolution; i++) {
      // These four lines result in 1 step:
      digitalWrite(stepPin, HIGH);
      delayMicroseconds(1000);
      digitalWrite(stepPin, LOW);
      delayMicroseconds(1000);
    }
  }
  if (buttonState2 == HIGH) {  // Set the spinning direction counterclockwise:
    digitalWrite(dirPin, LOW);

    // Spin the stepper motor 1 revolution quickly:
    for (int i = 0; i < stepsPerRevolution; i++) {
      // These four lines result in 1 step:
      digitalWrite(stepPin, HIGH);
      delayMicroseconds(1000);
      digitalWrite(stepPin, LOW);
      delayMicroseconds(1000);
    }
  }
}
 */