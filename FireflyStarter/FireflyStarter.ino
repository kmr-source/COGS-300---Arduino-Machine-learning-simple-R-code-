int ledPin = 13;
int photo1Pin = A0;
int photo2Pin = A2;
//int photo3Pin = A3;

int photo1Res;
int photo2Res;
//int photo3Res;

int photo1Threshold = 250;
int photo2Threshold = 250;
//int photo3Threshold = 800;


unsigned long currentTime;


unsigned long nextActivation; //The time at which the next activation phase will begin
unsigned long activationDelay = 1500; //The time between the end of a blink and the next activation


unsigned long nextPrint; //The next time at which something should be printed
unsigned long printDelay = 100; //Time between print statements (feel free to change)

unsigned long onTime; //The time at which the LED will turn on
unsigned long offTime; //The time at which the LED will turn off
unsigned long onDelay = 1000; //Time between activation and the LED turning on
unsigned long offDelay = 500; //Time between LED turning on and off


void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  
  currentTime = millis();
  nextPrint = currentTime + nextPrint;

  //TODO 1: Use currentTime and activationDelay to set the time of your first activation (theta) (nextActivation = theata0)
  nextActivation = currentTime+activationDelay;
  //nextActivation;
  
 
}


void loop() {
  // put your main code here, to run repeatedly:
  currentTime = millis();

  //TODO 2: Activation phase (Turn on/ off)
  //change the false to check if firefly has reached the activation time (theta) (turn LED on)
  if (currentTime>=nextActivation) {
    //Using your prelab, figure out which variables to set here
    // onTime = A , offTime=B; 
    onTime = currentTime+onDelay;
    offTime = onTime+offDelay;
    nextActivation = offTime+activationDelay; //theata2


 
    Serial.println("I am blinking soon");
  }
  
  //TODO 3: Blinking phase
  //Change the false to check when should the light be on and off
  if (currentTime<=offTime && currentTime>=onTime){
    digitalWrite(ledPin, HIGH); // turning on
    Serial.println("Blinking now!");
  }
  else {
    digitalWrite(ledPin, LOW);
  }

  
  photo1Res = analogRead(photo1Pin);
  photo2Res = analogRead(photo2Pin);

  
  //This is for if you would like to print out any other values
  if(currentTime > nextPrint){
      Serial.print("P1: ");
      Serial.println(photo1Res);
      Serial.print("P2: ");
      Serial.println(photo2Res);
  }
  
  //TODO 4: Perception Phase
  //change the false to check if any lights around you are on
  if (photo1Res>photo1Threshold || photo2Res>photo2Threshold){
    onTime = currentTime+onDelay;
    offTime = onTime+offDelay;
    nextActivation = offTime+activationDelay; 
    Serial.println("Saw another blink");
    }
  
}
