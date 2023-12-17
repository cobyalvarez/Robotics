long randNumber;
int redLED = 13;
int yellowLED = 10;
int greenLED = 7;
int blueLED = 5;
int whiteLED = 3;
int delayS = 100;
int LEDcount = 5;

void setup() {
  Serial.begin(9600);
  pinMode(redLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(blueLED, OUTPUT);
  pinMode(whiteLED, OUTPUT);
}

void readByte(bool* arr)
{
  //assume lenght 4

  digitalWrite(redLED,arr[0]);
  digitalWrite(yellowLED,arr[1]);
  digitalWrite(greenLED,arr[2]);
  digitalWrite(blueLED,arr[3]);
}

void loop() {
  /*
  for(int i = 0; i < 20; i++){
    randNumber = random(5);
    if(randNumber == 0){
      digitalWrite (redLED,HIGH);
      delay(delayS);
      digitalWrite (redLED,LOW);
    }
    else if (randNumber == 1){
      digitalWrite (yellowLED,HIGH);
      delay(delayS);
      digitalWrite (yellowLED,LOW);
    }
    else if ( randNumber == 2){
      digitalWrite (greenLED,HIGH);
      delay(delayS);
      digitalWrite (greenLED,LOW);
    }
    else if (randNumber==3){
      digitalWrite (blueLED,HIGH);
      delay(delayS);
      digitalWrite (blueLED,LOW);
    }
    else if(randNumber==4){
      digitalWrite (whiteLED,HIGH);
      delay(delayS);
      digitalWrite (whiteLED,LOW);
      break;
    }
    delay(100);
  }*/
  for(int i=0;i<16;i++){
    
  }
  bool arr[4] = {1,1,1,1};
  bool off[4] = {0,0,0,0};
  readByte(arr);
  delay(200);
  readByte(off);
  delay(500);
}