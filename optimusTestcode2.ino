#include <NewPing.h>
int L_IN_Positive = 14; // ARDUINO (A0) ------ L293 (L +) // Front Left Servo
int L_IN_Negative = 15; // ARDUINO (A1) ------ L293 (L-)  // Back Left Servo
int R_IN_Positive = 16; // ARDUINO (A2) ------ L293 (R +) // Front Right Servo
int R_IN_Negative = 17; // ARDUINO (A3) ------ L293 (R-)  // Back Right Servo

// Global Variables (ALL CAPZ)
const int ECHO_PIN=9;
const int TRIG_PIN=8; 
const float MAX_DIST = 100.0; // in centimeters
const float pi = 3.14;
const int delayTime = 5;


//variables to be used
int echopin = ECHO_PIN;
int trigpin = TRIG_PIN;
float maxdist = MAX_DIST;

//Sets up pin connection
NewPing sonar(trigpin,echopin,maxdist);


//Need Vehical Specs ***********
float frontWheelLength = 15.5; //length between front wheels (mm)
float truckWidth = frontWheelLength; // Width of Truck = Lenght of Front Wheels 
float fbWheelLength = 18.0; //length between front and back wheels (mm)
float wheelDiameter = 6.5; // Wheel diameter in mm
float truckLength = 25.5; // truck length in mm



//Functions for setting variables
float setMaxDist(){
  //Sets up max distance for ultrasonic by ping
  float maxDist = MAX_DIST;
  return maxDist;
  }

float findTravelDist(float maxDistance){
  //Finds new distance destination using max distance (ping to distance)
  int travelPing = sonar.ping();
  if (travelPing == maxDistance){
    float travelDist = maxDistance;
    return travelDist;
    }
    else if (travelPing < maxDistance){
      float newTravelDist = sonar.convert_cm(travelPing);
      return newTravelDist;
      }
  }
  
int setRevDest(float travelDistance){
  //Sets total revolutions to get to destination based on travel distance
  float travelRevDest = travelDistance;
  travelRevDest = (int) travelRevDest;
  return travelRevDest;
  }

int setRevMotion(int travelRevDestination){
  // Sets revolution count to get to destination
  int rotMotion = (travelRevDestination/(pi*travelRevDestination)); //sets number of rotations;
  for (int revCount = 0; revCount<=rotMotion; revCount++){
    digitalWrite(L_IN_Positive, HIGH); 
    digitalWrite(L_IN_Negative, LOW);
    digitalWrite(R_IN_Positive, HIGH); 
    digitalWrite(R_IN_Negative, LOW);
    if (revCount==rotMotion){
      hold();
      revCount = 0;
      return revCount;
      }
    return revCount;
    }
    }


//Functions for moving Optimus
void forward() {
  float maxOptimus_dist = setMaxDist();
  float optimusTrav_dist = findTravelDist(maxOptimus_dist);
  
  int optimusForward = setRevMotion(optimusTrav_dist);
  analogWrite(L_IN_Positive,optimusForward);
  analogWrite(L_IN_Negative, 0); 
  analogWrite(R_IN_Positive,optimusForward);
  analogWrite(R_IN_Negative,0); 
  delay(delayTime); 
}

void hold(){
  //Makes Optimus stop
  digitalWrite(L_IN_Positive, LOW); 
  digitalWrite(L_IN_Negative, LOW); 
  digitalWrite(R_IN_Positive, LOW); 
  digitalWrite(R_IN_Negative, LOW);
  delay(delayTime);  
}

void detect(){
  //Makes Optimus STOP and detect
  float maxOptimus_dist = setMaxDist();
  
  digitalWrite(trigpin,LOW);
  delayMicroseconds(2);
  float optimusTrav_dist = findTravelDist(maxOptimus_dist);
  digitalWrite(trigpin,HIGH);
  hold();
}


// Main Code
void setup(){
  Serial.begin(9600);  
  pinMode(echopin,INPUT); 
  pinMode(trigpin,OUTPUT);
  pinMode(L_IN_Positive,  OUTPUT);  // pin 14 (PWM) 
  pinMode(L_IN_Negative,  OUTPUT);  // pin 15 (PWM)
  pinMode(R_IN_Positive, OUTPUT);   // pin 16 (PWM)
  pinMode(R_IN_Negative, OUTPUT);   // pin 17 (PWM) 
}

void loop(){
  forward();
  
}

