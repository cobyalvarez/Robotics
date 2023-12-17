const int BUTTON_PIN = 3; 
const int LED_PIN    = 10; 

int ledState = LOW;     
int lastButtonState;    
int currentButtonState; 

unsigned long lastDebounceTime = 0;  
unsigned long debounceDelay = 50;    

void setup() {
  Serial.begin(9600);                
  pinMode(BUTTON_PIN, INPUT_PULLUP); 
  pinMode(LED_PIN, OUTPUT);          

  lastButtonState = digitalRead(BUTTON_PIN); 
}

void loop() {
  int reading = digitalRead(BUTTON_PIN);

  if (reading != lastButtonState) {
    // reset the debouncing timer
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {

    if (reading != currentButtonState) {
      currentButtonState = reading;

      // only toggle the LED if the new button state is LOW
      if (currentButtonState == LOW) {
        ledState = !ledState;  // change the state of the LED
      }
    }
  }

  // set the LED
  digitalWrite(LED_PIN, ledState);

  // save the reading
  lastButtonState = reading;
}
