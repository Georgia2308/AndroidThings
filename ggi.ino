/* MQ-4 Methane Sensor Circuit with Arduino */

#include <SoftwareSerial.h>

SoftwareSerial BLU(0, 1);

const int AOUTpin = 0; //the AOUT pin of the methane sensor goes into analog pin A0 of the arduino
int limit;
int value;

void setup() {
  Serial.begin(9600);//sets the baud rate
  BLU.begin(9600);
  Serial.write("ON\n");
}

void loop()
{
      value = analogRead(AOUTpin); //reads the analaog value from the methane sensor's AOUT pin
      Serial.println(value);//prints the methane value
      
      String data = String(value);
      BLU.println(data);
      delay(500);
}
