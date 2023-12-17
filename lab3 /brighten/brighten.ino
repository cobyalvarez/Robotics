int led = 5;         // the PWM pin the LED is attached to
int brightness = 0;  // how bright the LED is
int light = 5;  // how many points to light up the LED by

void setup() {
  pinMode(led, OUTPUT);
}

void loop() {
  while(brightness<100){
  analogWrite(led, brightness);
  delay(8);
  brightness = brightness + light;
  }

  if (brightness == 100 || brightness > 100) {
  brightness = 0;
  }
  delay(8);
}
