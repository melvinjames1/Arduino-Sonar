#include <Servo.h>
#include <IRremote.h>

Servo servoMotor; 
const int irReceiverPin = 11; 
const int servoPin = 12;

IRrecv irrecv(irReceiverPin); 
decode_results results;

void setup() {
  Serial.begin(9600); 
  irrecv.enableIRIn(); 
  servoMotor.attach(servoPin); 
}

void loop() {
  if (irrecv.decode(&results)) { 
    Serial.print("IR Code: ");
    Serial.println(results.value, HEX);
    

    switch (results.value) {
      case 0xFFA25D: 
        servoMotor.write(90); 
        delay(1000); 
        break;

    }

    irrecv.resume();
  }
}



