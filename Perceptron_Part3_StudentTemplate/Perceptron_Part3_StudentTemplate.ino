
//******************************************************
//****************** Global variables ******************
//******************************************************

//------------------------------------------------------------GIVEN KNOWN VARIABLES

//------------------------x1  x2 x3 x4 x5 d
float training_set1[120] = {1, 1, 1, 1, 1, 1,
                           1, 1, 0, 1, 1, 1,
                           1, 0, 1, 1, 1, 1,
                           0, 1, 1, 1, 1, 1,
                           1, 0, 1, 0, 1, 1,
                           0, 0, 1, 1, 1, 1,
                           0, 1, 0, 1, 1, 1,
                           1, 0, 0, 1, 1, 1,
                           1, 1, 0, 0, 1, 1,
                           1, 1, 1, 0, 0, 1,
                           0, 0, 0, 0, 0, 0,
                           0, 0, 1, 0, 1, 0,
                           0, 1, 0, 0, 1, 0,
                           1, 0, 0, 0, 1, 0,
                           0, 0, 0, 1, 0, 0,
                           1, 0, 0, 0, 1, 0,
                           1, 1, 0, 0, 0, 0,
                           0, 1, 1, 0, 0, 0, 
                           0, 0, 1, 1, 0, 0,
                           0, 0, 0, 1, 1, 0};                           

// ~~~ Use these varibles in the learning portion of the Perceptron 

float x_0=1.0; //value of input 0 of the perceptron; it's the bias
float x_1; //hold actual value of input 1 of the perceptron
float x_2; //hold actual value of input 2 of the perceptron
float x_3; //hold actual value of input 3 of the perceptron
float x_4; //hold actual value of input 4 of the perceptron
float x_5; //hold actual value of input 5 of the perceptron


float d; //hold actual desired output
float y; //hold the actual dot product of training sample

float w_0=0.0; //holds actual weight of input 0
float w_1=0.0; //hold actual weight of input 1
float w_2=0.0; //hold actual weight of input 2
float w_3=0.0; //hold actual weight of input 3
float w_4=0.0; //hold actual weight of input 4
float w_5=0.0; //hold actual weight of input 5


float f_x; //binary output of the perceptron
float threshold=0.5; //deside when the perceptron 'fires'
float alpha=0.1; //learning parameter where 0<α≤1
float error; //hold actual error of the training sample
float error_sum=5.0; //hold the error sum of the training set
int counter; //counter for training samples
int t=0; //auxiliary variable 

// ~~~ These are for the Testing portion

float X_1; //hold actual value of input 1 of the perceptron for application
float X_2; //hold actual value of input 2 of the perceptron for application
float X_3; //hold actual value of input 3 of the perceptron for application
float X_4; //hold actual value of input 4 of the perceptron for application
float X_5; //hold actual value of input 5 of the perceptron for application

float Y; //hold dot product with final weights

// ~~~ These are for the photoresistors

int output_led = 2;

int pr0 = 0; //pr0 is photoresistor0 input
int pr1 = 1; //pr1 is photoresistor1 input
int pr2 = 2; //pr2 is photoresistor2 input
int pr3 = 3; //pr3 is photoresistor3 input
int pr4 = 4; //pr4 is photoresistor4 input

int pr0reading = 0; //is the data value reading of pr0 
int pr1reading = 0; //is the data value reading of pr1 
int pr2reading = 0; //is the data value reading of pr2 
int pr3reading = 0; //is the data value reading of pr3 
int pr4reading = 0; //is the data value reading of pr4 

int pr0threshold = 600; // photoresistor0's threshold
int pr1threshold = 300; // photoresistor1's threshold
int pr2threshold = 200; // photoresistor2's threshold
int pr3threshold = 100; // photoresistor3's threshold
int pr4threshold = 900; // photoresistor4's threshold

//---------------------------------------------------------------------------- Please replace all the ???s : 
/* How many times does the Perceptron need to go over the training data?
 *
 
 *int total_cycles = ??? ; 
 * int current_cycle = ??? ;
 * int data_sets= ??? ;
 *
 *
*/
int total_cycles = 300;
int current_cycle = 0;
int data_sets = 20;

void setup() {
  Serial.begin(9600);
 

//******************************************************
//********************* Learning **********************
//*******************************************************/


  t=0; //auxiliary variable 
  while (current_cycle < total_cycles)
  {
    error_sum=0.0; //reset error sum
    for (int j=0; j<data_sets; j++)
    {   
      
      x_1=training_set1[t];                    
      x_2=training_set1[t+1];  
      x_3=training_set1[t+2];
      x_4=training_set1[t+3];
      x_5=training_set1[t+4];
      d=training_set1[t+5];  
      t=t+6;
      
      //------------------------------------------------------------------- Please replace all the ???s :   

      //Define y here.  (weight of sum)             
      y= (w_0*x_0) + (w_1*x_1)+(w_2*x_2)+(w_3*x_3)+(w_4*x_4)+(w_5*x_5);

      //Create an if-statement for y.
                
      if (y >= threshold)
      {
        f_x = 1.0; 
      }
      else
      {
        f_x = 0.0; 
      }
      
      
      //Define the error.
      error= d-f_x;  
      
      // Define the error_sum.
      error_sum= error_sum+error; 

      //Change the weights of the hidden layer
      
      w_0= w_0+(t*error*x_0);
      w_1= w_1+(t*error*x_1);              
      w_2= w_2+(t*error*x_2);             
      w_3= w_3+(t*error*x_3);
      w_4= w_4+(t*error*x_4);
      w_5= w_5+(t*error*x_5);
      
      
      //-------------------------------------------------------------------

               
      
    }
    current_cycle++;
    t=0;
    Serial.print("Cycle: ");
    Serial.print(current_cycle); 
    Serial.print(" Error Sum = ");
    Serial.print(error_sum);
    Serial.println(" ");
  }
  Serial.println("Learning progress finished!");
  Serial.println(" ");

/******************************************************
//******************** Test It! *********************
//******************************************************/

  while (1)
  {
    Serial.print("Submit input value for x_1: ");
    counter=0; //reset counter
    
    delay(3000);
    pr0reading = analogRead(pr0);
    
    while (counter <1)
    {
      if (pr0reading <= pr0threshold)
        {
          X_1 = 0;
          Serial.println(X_1);
          counter++;
        }
        
        if (pr0reading > pr0threshold)
        {
          X_1 = 1;
          Serial.println(X_1);
          counter++;
          }
      }
     
    
    counter=0; //reset counter

    
    Serial.print("Submit input value for x_2: ");
    delay(3000);
    
    pr1reading = analogRead(pr1);
    
    while (counter <1)
    {
      if (pr1reading <= pr1threshold)
        {
          X_2 = 0;
          Serial.println(X_2);
          counter++;
        }
        
        if (pr1reading > pr1threshold)
        {
          X_2 = 1;
          Serial.println(X_2);
          counter++;
          }
      }
     
    
    counter=0; //reset counter

    Serial.print("Submit input value for x_3: ");
    delay(3000);
     pr2reading = analogRead(pr2);
    
    while (counter <1)
    {
      if (pr2reading <= pr2threshold)
        {
          X_3 = 0;
          Serial.println(X_3);
          counter++;
        }
        
        if (pr2reading > pr2threshold)
        {
          X_3 = 1;
          Serial.println(X_3);
          counter++;
          }
      }
    
    counter=0; //reset counter

    Serial.print("Submit input value for x_4: ");
    delay(3000);
    pr3reading = analogRead(pr3);
    
    while (counter <1)
    {
      if (pr3reading <= pr3threshold)
        {
          X_4 = 0;
          Serial.println(X_4);
          counter++;
        }
        
        if (pr3reading > pr3threshold)
        {
          X_4 = 1;
          Serial.println(X_4);
          counter++;
          }
      }
    
    counter=0; //reset counter

    Serial.print("Submit input value for x_5: ");
    delay(3000);
     pr4reading = analogRead(pr4);
    
    while (counter <1)
    {
      if (pr4reading <= pr4threshold)
        {
          X_5 = 0;
          Serial.println(X_5);
          counter++;
        }
        
        if (pr4reading > pr4threshold)
        {
          X_5 = 1;
          Serial.println(X_5);
          counter++;
          }
      }
    
    counter=0; //reset counter


    //------------------------------------------------------------------------------ Please replace all the ???s : 
    
    Y= w_0+ (w_1*X_1)+(w_2*X_2)+(w_3*X_3)+(w_4*X_4)+(w_5*X_5);;
    
    // How do you know when the output is a 1 or 0?
    //when it fires = 1 , does not then 0;
    // Make sure turn the output_LED on when f_x = 1, and off when it's 0

    
    if ( y >threshold) {
        digitalWrite(output_led, HIGH);
        f_x=1;
      }
      else {
        digitalWrite(output_led, LOW);
        f_x = 0;
      }
      
      
    Serial.print("The desired output is: ");
    Serial.println(f_x);
    Serial.println(" ");
  }
}
