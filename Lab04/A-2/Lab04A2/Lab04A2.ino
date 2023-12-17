const int buttonPin = 10; 

// the previous reading from the input pin
int lastButtonState = LOW;

// the current input pin state
int currentButtonState = LOW;

// counter for the number of button presses
int count = 0;
int releaseCount = 0;

void setup() {

  pinMode(buttonPin, INPUT_PULLUP);

  Serial.begin(9600);
}

void loop() {
  // read the pushbutton input pin:
  currentButtonState = digitalRead(buttonPin);

  if (currentButtonState != lastButtonState) {
    if (currentButtonState == LOW) {
      Serial.println("Button was pressed");
      count++;
      Serial.print("Number of presses: ");
      Serial.println(count);
    } else {
      Serial.println("Button was released");
      releaseCount++;
      Serial.print("Number of releases: ");
      Serial.println(releaseCount);
    }

    delay(50);
  }

  lastButtonState = currentButtonState;
}