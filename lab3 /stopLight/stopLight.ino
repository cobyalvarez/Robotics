int redLED = 13;
int yellowLED = 8;
int greenLED = 4;
int delayM = 1000;
int delayS = 500;
int restart = 2000;

void setup() {
  pinMode(redLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  randomSeed(analogRead(0));

}

void loop() {
  digitalWrite (redLED,HIGH);
  delay(delayM);
  digitalWrite (redLED,LOW);
  delay(250);
  digitalWrite (yellowLED,HIGH);
  delay(delayS);
  digitalWrite (yellowLED,LOW);
  delay(250);
  digitalWrite (greenLED,HIGH);
  delay(delayM);
  digitalWrite (greenLED,LOW);
  delay(restart);
}