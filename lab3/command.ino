const int ledPin = 11;  
String readString; 
void setup() 
{
    Serial.begin(9600); 
    pinMode(ledPin, OUTPUT);  
 
}

void loop() 
{
    while (Serial.available()) 
    { 
      //read the input
        char c = Serial.read();  
        readString += c;  
        delay(2);  
    }
    
    if (readString.length() > 0) 
    {
        readString.trim();  // This will modify readString directly
      
        Serial.println(readString); 
      if(readString="O"){
        //if O it will turn on
        digitalWrite(ledPin, HIGH); 
      }
      //This will make the light turn off
      else if(readString="F"){
        digitalWrite(ledPin, HIGH); 
      }
      //returns invalif code
      else{
        Serial.println("Invalid Command");
      }
      //resets the readString at the end
      readString="";
    }
}