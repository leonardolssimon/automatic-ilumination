const int photoresistor = A0;     
const int relayN1 = 3;            
const int pirSensor = 7;                

int state = LOW;                  // By default, no motion detected
int valuePir = 0;                 // Variable to store the PIR sensor value
int valuePhoto = 0;               // Variable to store the photoresistor sensor value

void setup() {
  pinMode(pirSensor, INPUT);      // Initialize PIR sensor
  pinMode(photoresistor, INPUT);  // Set photoresistor
  pinMode(relayN1, OUTPUT);       // Initialize Relay
  digitalWrite(relayN1, HIGH);    // Start Relay turned off
}

void loop() {
  valuePir = digitalRead(pirSensor);                // read PIR sensor value
  valuePhoto = analogRead(photoresistor);           // read phororesistor sensor value
  if (valuePir == HIGH) {                           // check if motion is detected    
    if (state == LOW && valuePhoto < 300) {         // check if the state is LOW and if the value in the photoresistor is lower than 300
      digitalWrite(relayN1, LOW);                   // turn on the relay/lamp
      delay(30000);                                 // wait 30 seconds
      state = HIGH;                                 // update variable state to HIGH
    }
  } 
  else {      
      if (state == HIGH){                           // check if the state is HIGH
        digitalWrite(relayN1, HIGH);                // turn off the relay/lamp
        state = LOW;                                // update variable state to LOW
    }
  }
}
