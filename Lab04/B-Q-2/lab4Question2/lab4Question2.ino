void setup() {
  
  pinMode(2, INPUT_PULLUP);// define pin two as input for push button
  pinMode(10, OUTPUT);// defind pin 10 as output
}

void loop() {
  
  int pushed_button = digitalRead(2);// read pin 2 and put the result in the "pushed" variable
  if(pushed_button == HIGH){
    digitalWrite(10, HIGH);// if pusheed is equal LOW, turn the pin 10 HIGH (give it 5v)
  }else{
    digitalWrite(10, LOW);// else set pin 10 to low or zero volt
  }
}