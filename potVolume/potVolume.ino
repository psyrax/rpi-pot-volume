#include <ArduinoJson.h>

int potPin = A0;
int buttonPin = A1;
int buttonState = 0;
int prevPot = 0;

StaticJsonBuffer<200> jsonBuffer;
JsonObject& data = jsonBuffer.createObject();
 
void setup() {
   Serial.begin(9600);
   pinMode(buttonPin, INPUT);
}

void loop() {
  
  
  data["button"] = analogRead(buttonPin);
  
  int potVal = map(analogRead(potPin), 0, 1023, 0, 100);
  if ( potVal < prevPot-2 || potVal > prevPot+2 ){
    data["volume"] = 100- potVal;
    data.printTo(Serial);
    Serial.println();
    prevPot = potVal;
    delay(300);
  };
  if ( data["button"] > 400 ){
    data.printTo(Serial);
    Serial.println();
    delay(500);
  };
  

}
