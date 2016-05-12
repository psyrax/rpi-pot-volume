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
  
  buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH) {
    data["toggle"] = true;
  } else {
    data["toggle"] = false;
  };
  
  int potVal = map(analogRead(potPin), 0, 1023, 0, 100);
  if ( potVal < prevPot-2 || potVal > prevPot+2 ){
    data["volume"] = potVal;
    data.printTo(Serial);
    Serial.println();
    prevPot = potVal;
    delay(1000);
  };
  

}
