#include <SoftwareSerial.h>

SoftwareSerial mySerial(10, 11); // RX, TX


int LED = 13;

const int buttonPin = 4;
boolean prvButtonState = false;

int brate = 9600;

void setup()
{
  pinMode(LED, OUTPUT); 
  
  pinMode(buttonPin, INPUT);
  
  Serial.begin(brate);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }
  
  Serial.println("=== START ===");

  // set the data rate for the SoftwareSerial port
  mySerial.begin(brate);
  
  Keyboard.begin();
}


void loop()
{
  
  int buttonState = digitalRead(buttonPin);
  
  //Serial.println(buttonState);
  
  //Serial.println("loop");
  
  if (buttonState == HIGH) prvButtonState = !prvButtonState;
  delay(200);
  
  if(prvButtonState){
    //Serial.println("Button Press!");
    
    if (mySerial.available()){
      Keyboard.println(mySerial.readString());
      //Serial.println("Serial ist da");
    }
  
    digitalWrite(LED, LOW);
  }
  else digitalWrite(LED, HIGH);
  
  
  

}
