#define TRIG_PIN 6
#define ECHO_PIN 7
#define SWITCH_PIN 8

void setup() {
  // Initialize the Serial Monitor
  Serial.begin(9600);

  // Configure the ultrasonic sensor pins
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  
  // Set up the switch pin with an internal pull-up resistor
  pinMode(SWITCH_PIN, INPUT_PULLUP);
}

void loop() {
  // Read the switch state
  bool metric = digitalRead(SWITCH_PIN);

  // Get the distance from the ultrasonic sensor
  float distance = getDistance();

  // Convert distance to inches if the switch is closed (LOW)
  if (!metric) {
    distance *= 0.393701;
  }

  // Print the distance in the correct units
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(metric ? " cm" : " in");

  // Wait a bit before taking another measurement
  delay(500);
}

float getDistance() {
  // Ensure trigger pin is low
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  // Trigger the sensor by setting the trigPin high for 10 microseconds
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Read the echoPin. pulseIn returns the duration in microseconds.
  long duration = pulseIn(ECHO_PIN, HIGH);

  // Calculate the distance: duration / 58.2 = distance in centimeters
  float distance = duration / 58.2;

  return distance;
}
