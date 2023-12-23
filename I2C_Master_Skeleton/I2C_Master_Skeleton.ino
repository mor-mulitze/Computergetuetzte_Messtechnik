#include <Wire.h>


/* Platz fuer globale Variablen */

void setup()
{
  Wire.begin();
  Serial.begin(9600);
}

void loop()
{
  delay(50);
  
  /* Hier entwerfen Sie das Programm fur den Master */
  
  /* Starten Sie die Komunikation und warten auf Daten ("Hi") vom Slave*/
}
