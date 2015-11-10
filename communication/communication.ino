

int sensorPin = 0; //reference to analog pin 0 (A0)

void setup() {
  // setup routines
  Serial.begin(9600);
  while (! Serial);
  // Instruction message:
  // START REC.
  Serial.println("Enter 'start' to begin reading serial data from sensor");
}

void loop() {

  if (Serial.available()) {

    char resp = Serial.read();
    char expected = 'start';

    if (resp == expected) {

      Serial.println("START RECORDING");
      
    }
    
  }

} // End 'void-loop'
