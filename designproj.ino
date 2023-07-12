const int motorPin = 2;   // Motor pin for control
const int motorPin2 = 3;
const int motorPin3 = 4;
const int motorPin4 = 5;
const int motorPin5 = 6;
const int motorPin6 = 7;  // Motor pin for control

unsigned long startTime = 0;  // Variable to store the start time

void setup() {
  pinMode(motorPin, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT);
  pinMode(motorPin5, OUTPUT);
  pinMode(motorPin6, OUTPUT);
  Serial.begin(9600); // Must match the baud rate in Python code
}

void loop() {
  if (Serial.available() > 0) {
    String message = Serial.readStringUntil('\n');
    int delimiterIndex = message.indexOf(':');
    
    if (delimiterIndex != -1) {
      int freq = message.substring(0, delimiterIndex).toInt();
      float value = message.substring(delimiterIndex + 1).toFloat();
      int x, z;
      if (freq != 50) {
        x = value * 1000;
        if (x > 1000) {
          x = 1000;
        }
        z = map(x, 0, 1000, 0, 255);
      } else {
        x = value;
        z = map(x, 0, 50, 0, 255);
      }
      
      // Store the start time
      startTime = millis();

      // Process the received frequency and value
      if (freq == 50) {
        analogWrite(motorPin3, z);
      }
      if (freq == 500) {
        analogWrite(motorPin2, z);
      }
      if (freq == 9000) {
        analogWrite(motorPin, z);
      }
      if (freq == 300) {
        analogWrite(motorPin4, z);
      }
      if (freq == 8000) {
        analogWrite(motorPin5, z);
      }
      if (freq == 2500) {
        analogWrite(motorPin6, z);
      }

      // Calculate the execution time
      unsigned long executionTime = millis() - startTime;
      Serial.print("Execution Time: ");
      Serial.print(executionTime);
      Serial.println(" ms");
    }
  }
}
