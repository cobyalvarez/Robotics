#include <Servo.h>

Servo myservo;  // create servo object to control a servo
int defaultPosition = 90;  // default position for the servo

void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  randomSeed(analogRead(0));  // seed the random number generator with analog input 0
}

void loop() {
  int randomDegrees = random(20, 31);  // generate a random number between 20 and 30
  int randomDirection = random(0, 2);   // generate a random number 0 or 1 for direction

  if (randomDirection == 0) {
    // Move in the positive direction
    for (int pos = 0; pos <= randomDegrees; pos += 1) {
      myservo.write(pos);
      delay(10);  // adjust delay as needed
    }
  } else {
    // Move in the negative direction
    for (int pos = 180; pos >= 180 - randomDegrees; pos -= 1) {
      myservo.write(pos);
      delay(10);  // adjust delay as needed
    }
  }
  // Return to the default position
 int currentPosition = myservo.read();
while (currentPosition != defaultPosition) {
  currentPosition += (currentPosition < defaultPosition) ? 1 : -1;
  myservo.write(currentPosition);
  delay(10);  // Adjust delay as needed
}

  delay(1000);  // wait for a second before the next iteration
}