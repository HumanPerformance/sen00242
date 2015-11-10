

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

      int outputArray[100];
      int i;
      for (i = 0; i < 100; i++) {
        
        int counter = i;
        int sensorVal = analogRead(sensorPin);
        
        outputArray[i] = sensorVal;
        
        String separator = ", ";
        String outputString = counter + separator + sensorVal;
        Serial.println(outputString);

        delay(100); // Purposely delay recording
      
      }
    
    }

  }

}// End 'void-loop'
