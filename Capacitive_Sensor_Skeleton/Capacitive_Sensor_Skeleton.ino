void setup() 
{ 
  Serial.begin(9600); 
} 
 
void loop() 
{ 
  /* Nur duch Berührung mit einem Metallstift soll im folgenden eine blaue LED eingeschaltet werden */

  delay(10); 
}


/* folgende Zeilen richtig einfügen: */
#include <CapacitiveSensor.h> 
CapacitiveSensor Sensor = CapacitiveSensor(XXX, XXX); /* Die richtigen Werte für XXX einsetzen */
val = Sensor.capacitiveSensor(30);
