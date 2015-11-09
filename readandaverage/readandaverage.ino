
// The following script has been designed to interface with the SHARP IR Proximity sensor sen00242
// The script allows for the user to display sensor readings in the Arduino serial monitor
//
// Fluvio L. Lobo Fenoglietto - 11092015 -

int sensorPin = 0; //analog pin 0

void setup(){
  Serial.begin(9600);
}

void loop(){
  int val = analogRead(sensorPin);
  double dist = (double) val;

  if (dist > 450) {
    Serial.println("too close");
  }

  // Mathematical operations on "dist"
  // double realdist = dist/100;
  
  // Serial.println(val);
  // Serial.println(dist);
  // Serial.println(realdist);

  //just to slow down the output - remove if trying to catch an object passing by
  delay(100);

}
