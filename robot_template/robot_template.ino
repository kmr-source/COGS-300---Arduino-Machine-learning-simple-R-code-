#define LMotor_In 10 
#define LMotor_Out 9 
#define RMotor_In 6 
#define RMotor_Out 5 
//#include <NewPing.h>

int left_sen = A0;    //A = left
int center_sen = A1;  //B = center
int right_sen = A2;   //C = right
int ValSens_A = 0;
int ValSens_B = 0;
int ValSens_C = 0;

//FRONT SENSOR
#define TRIGGER_FRONT 3
#define ECHO_FRONT 4

//LEFT SENSOR
#define TRIGGER_LEFT 12
#define ECHO_LEFT 13
#define MAX_DISTANCE 200

//NewPing leftsonar(TRIGGER_LEFT, ECHO_LEFT, MAX_DISTANCE);
//NewPing frontsonar(TRIGGER_FRONT, ECHO_FRONT, MAX_DISTANCE);

#define LEFTTHRESHOLD 20
#define FRONTTHRESHOLD 20

#define centerThres 200
#define leftThres 300
#define rightThres 300


//    int photocellPin = 0; // the cell and 10K pulldown are connected to a0
//    int photocellReading; // the analog reading from the sensor divider
//    int LEDpin = 11; // connect Red LED to pin 11 (PWM pin) (this is not needed to use the sensor but if you have one laying around it could add a cool affect! This can be bought at your local Radio Shack.)
//    int LEDbrightness; //
 

//    void loop(void) {
//    photocellReading = analogRead(photocellPin);
//    Serial.print("Analog reading = ");
//    Serial.println(photocellReading); // the raw analog reading
//    // LED gets brighter the darker it is at the sensor
//    // that means we have to -invert- the reading from 0-1023 back to 1023-0
//    photocellReading = 1023 - photocellReading;    //now we have to map 0-1023 to 0-255 since thats the          range analogWrite uses
//    LEDbrightness = map(photocellReading, 0, 1023, 0, 255);
//    analogWrite(LEDpin, LEDbrightness);
//    delay(100);        
//    }

void setup() {
  Serial.begin(9600);
}

void loop(){
  forward();
  delay(1000);

  stop();
  delay(1000);

  backward();
  delay(1000);

  stop();
  delay(2000);

  right();
  delay(3000);

  stop();
  delay(2000);

  left();
  delay(3000);

  
}

void forward() {                                  
  Serial.println("forward");
//LEFT MOTOR
  analogWrite(LMotor_In, 200);
  analogWrite(LMotor_Out, 0);

//RIGHT MOTOR
  analogWrite(RMotor_In, 200);
  analogWrite(RMotor_Out, 0);   
}

void backward() {                                 
  Serial.println("backward");
//LEFT MOTOR
  analogWrite(LMotor_In, 0);
  analogWrite(LMotor_Out, 200);

//RIGHT MOTOR
  analogWrite(RMotor_In, 0);
  analogWrite(RMotor_Out, 200);   
}

void left() {                                     //left
  Serial.println("left");
//LEFT MOTOR
  analogWrite(LMotor_In, 0);
  analogWrite(LMotor_Out, 0);

//RIGHT MOTOR
  analogWrite(RMotor_In, 200);
  analogWrite(RMotor_Out, 0);   
}

void right() {                                     //right
  Serial.println("right");
//LEFT MOTOR
  analogWrite(LMotor_In, 200);
  analogWrite(LMotor_Out, 0);

//RIGHT MOTOR
  analogWrite(RMotor_In, 0);
  analogWrite(RMotor_Out, 0);   
}

void stop() {                                     //stop
  Serial.println("stop");
//LEFT MOTOR
  analogWrite(LMotor_In, 0);
  analogWrite(LMotor_Out, 0);

//RIGHT MOTOR
  analogWrite(RMotor_In, 0);
  analogWrite(RMotor_Out, 0);   
}
