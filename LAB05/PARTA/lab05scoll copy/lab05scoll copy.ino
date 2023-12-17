// Define the connection pins for the rotary encoder
const int pinCLK = 2; // Connected to CLK on the encoder
const int pinDT = 4;  // Connected to DT on the encoder
int encoderPos = 0; // Start position for the encoder
int lastEncoderPos = 0; // Stores the last position of the encoder
boolean encoderALast = LOW;
boolean encoderB;

// Define the LEDs and the number of LEDs
const int ledPins[] = {5, 6, 9, 10, 11}; // Connect LEDs to these pins
const int numLeds = sizeof(ledPins) / sizeof(int);

void setup() {
  // Setup the LED pins
  for (int i = 0; i < numLeds; i++) {
    pinMode(ledPins[i], OUTPUT);
    digitalWrite(ledPins[i], LOW); // Make sure all LEDs are off initially
  }

  // Setup the encoder pins
  pinMode(pinCLK, INPUT);
  pinMode(pinDT, INPUT);

  // Enable pull-up resistor
  digitalWrite(pinCLK, HIGH);
  digitalWrite(pinDT, HIGH);

  // Initialize the serial port (for debugging)
  Serial.begin(9600);
}

void loop() {
  // Read the current state of CLK
  boolean encoderA = digitalRead(pinCLK);

  // If the previous and the current state of CLK are different, then a pulse occurred
  if (encoderA != encoderALast) { // Means the knob is rotating
    // If the DT state is different than the CLK state, that means the encoder is rotating clockwise
    if (digitalRead(pinDT) != encoderA) {
      encoderPos++;
      if (encoderPos >= numLeds) {
        encoderPos = numLeds - 1; // Prevent going beyond the last LED
      }
    } else {
      encoderPos--;
      if (encoderPos < 0) {
        encoderPos = 0; // Prevent going below the first LED
      }
    }
    // Update LEDs to reflect new position
    updateLEDs(encoderPos);

    Serial.print("Position: ");
    Serial.println(encoderPos); // Output for debugging
  } 
  encoderALast = encoderA; // Update the previous state of CLK with the current state
}

void updateLEDs(int position) {
  // Turn off all LEDs first
  for (int i = 0; i < numLeds; i++) {
    digitalWrite(ledPins[i], LOW);
  }
  // Then turn on the LED at the current position
  digitalWrite(ledPins[position], HIGH);
}