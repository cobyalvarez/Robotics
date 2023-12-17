void setup() {
// initialize both serial ports:
Serial.begin(9600);
Serial.print("-------------------\n");
Serial.print("Hello Arduino Land");
Serial.print("-------------------\n");
pinMode(LED_BUILTIN, OUTPUT);
}
int count = 0;
int ledState = HIGH;
String countString = String(count);
void loop() {
if(ledState == HIGH) {
ledState = LOW;
}
else {
ledState = HIGH;
}
digitalWrite(5, ledState);
digitalWrite(5, ledState);
//countString = String(count);
if(count % 20){
Serial.print(count);
Serial.print(", ");
}
else{
  Serial.print(count);
  Serial.print("\n");
}
count ++;
delay(500);
}