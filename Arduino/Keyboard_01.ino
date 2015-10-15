#include <SoftwareSerial.h>

SoftwareSerial mySerial(10, 11); // RX, TX


int LED = 13;

const int buttonPin = 4;
int previousButtonState = HIGH;

int brate = 9600;
boolean einz = true;

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
  
  //Serial.println(mySerial.read());
  
  digitalWrite(LED, HIGH);   // turn the LED on (HIGH is the voltage level)
  
  int buttonState = digitalRead(buttonPin);
  // if the button state has changed, 
  if ((buttonState != previousButtonState) 
    // and it's currently pressed:
  && (buttonState == HIGH)) {
     //Keyboard.println(Serial.read());
    if(!einz){
      mySerial.println("Hello, Handy?");
      Serial.println("Hallo, PC!");
      einz = false;
    }
    
   if (mySerial.available() > 0) Keyboard.println(mySerial.read());
  
    digitalWrite(LED, LOW);    // turn the LED off by making the voltage LOW
  }

}
