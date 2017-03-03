#include <LedControl.h>

/*Glenn Pantaleon
 * Senior Design LED MATRIX CODING
 * March 31,2016
 */
// Sets up Pin connection (below lc*)
LedControl lc = LedControl(12,11,10,1);

unsigned long delaytime = 100;

//Infrared Sensors Pin Setup
// Pin Values WILL CHANGE
const int ParkingSenA = 1;
const int ParkingSenB = 2;
const int ParkingSenC = 3;
const int ParkingSenD = 4;

int PSenA;
int PSenB;
int PSenC;
int PSenD;

// Functions For LED Matrix
// Functions to draw Directions 
void writeArudinoShape1(){
  // Write Stop Shape data on LED MATRIX
  byte stopSign[8] = {B00000000,B00000000,B11111111,B11111111,B00000000,B11111111,B11111111,B00000000};
  
  lc.setRow(0,0,stopSign[0]);
  lc.setRow(0,1,stopSign[1]);
  lc.setRow(0,2,stopSign[2]);
  lc.setRow(0,3,stopSign[3]);
  lc.setRow(0,4,stopSign[4]);
  lc.setRow(0,5,stopSign[5]);
  lc.setRow(0,6,stopSign[6]);
  lc.setRow(0,7,stopSign[7]);
  lc.setRow(0,8,stopSign[8]);
  delay(delaytime);
  }

void writeArudinoShape2(){
  // Write Foward Arrow Shape data on LED MATRIX
  byte forwardArrow[8] = {B00001000,B00011100,B00111110,B01111111,B00011100,B00011100,B00011100,B00011100};
  
  lc.setRow(0,0,forwardArrow[0]);
  lc.setRow(0,1,forwardArrow[1]);
  lc.setRow(0,2,forwardArrow[2]);
  lc.setRow(0,3,forwardArrow[3]);
  lc.setRow(0,4,forwardArrow[4]);
  lc.setRow(0,5,forwardArrow[5]);
  lc.setRow(0,6,forwardArrow[6]);
  lc.setRow(0,7,forwardArrow[7]);
  lc.setRow(0,8,forwardArrow[8]);
  delay(delaytime);
  }

void writeArudinoShape3(){
  // Write Left Arrow Shape data on LED MATRIX
  byte leftArrow[8] = {B00010000,B00110000,B01111111,B11111111,B01111111,B00110000,B00010000,B00000000};
  
  lc.setRow(0,0,leftArrow[0]);
  lc.setRow(0,1,leftArrow[1]);
  lc.setRow(0,2,leftArrow[2]);
  lc.setRow(0,3,leftArrow[3]);
  lc.setRow(0,4,leftArrow[4]);
  lc.setRow(0,5,leftArrow[5]);
  lc.setRow(0,6,leftArrow[6]);
  lc.setRow(0,7,leftArrow[7]);
  lc.setRow(0,8,leftArrow[8]);
  delay(delaytime);
  }

void writeArudinoShape4(){
  // Write Right Arrow Shape data on LED MATRIX
  byte rightArrow[8] = {B00001000,B00001100,B11111110,B11111111,B11111110,B00001100,B00001000,B00000000};
  
  lc.setRow(0,0,rightArrow[0]);
  lc.setRow(0,1,rightArrow[1]);
  lc.setRow(0,2,rightArrow[2]);
  lc.setRow(0,3,rightArrow[3]);
  lc.setRow(0,4,rightArrow[4]);
  lc.setRow(0,5,rightArrow[5]);
  lc.setRow(0,6,rightArrow[6]);
  lc.setRow(0,7,rightArrow[7]);
  lc.setRow(0,8,rightArrow[8]);
  delay(delaytime);
  }
  
// Functions to draw Parking Spot Places
void writeArudinoNum1(){
  // Write number '1' parking spot data on LED MATRIX
  byte park1[8] = {B00011000,B00111000,B01111000,B00011000,B00011000,B00011000,B00011000,B01111110};
  
  lc.setRow(0,0,park1[0]);
  lc.setRow(0,1,park1[1]);
  lc.setRow(0,2,park1[2]);
  lc.setRow(0,3,park1[3]);
  lc.setRow(0,4,park1[4]);
  lc.setRow(0,5,park1[5]);
  lc.setRow(0,6,park1[6]);
  lc.setRow(0,7,park1[7]);
  lc.setRow(0,8,park1[8]);
  delay(delaytime);
  }

void writeArudinoNum2(){
  // Write number '2' parking spot data on LED MATRIX
  byte park2[8] = {B00111100,B01000010,B00000100,B00001000,B00010000,B00100000,B01000000,B01111110};
  
  lc.setRow(0,0,park2[0]);
  lc.setRow(0,1,park2[1]);
  lc.setRow(0,2,park2[2]);
  lc.setRow(0,3,park2[3]);
  lc.setRow(0,4,park2[4]);
  lc.setRow(0,5,park2[5]);
  lc.setRow(0,6,park2[6]);
  lc.setRow(0,7,park2[7]);
  lc.setRow(0,8,park2[8]);
  delay(delaytime);
  }

void writeArudinoNum3(){
  // Write number '3' parking spot data on LED MATRIX
  byte park3[8] = {B01111110,B00000010,B00000010,B00000010,B00111110,B00000010,B00000010,B01111110};
  
  lc.setRow(0,0,park3[0]);
  lc.setRow(0,1,park3[1]);
  lc.setRow(0,2,park3[2]);
  lc.setRow(0,3,park3[3]);
  lc.setRow(0,4,park3[4]);
  lc.setRow(0,5,park3[5]);
  lc.setRow(0,6,park3[6]);
  lc.setRow(0,7,park3[7]);
  lc.setRow(0,8,park3[8]);
  delay(delaytime);
  }

void writeArudinoNum4(){
  // Write number '4' parking spot data on LED MATRIX
  byte park4[8] = {B00000100,B00001100,B00010100,B00100100,B01000100,B01111110,B00000100,B00000100};
  
  lc.setRow(0,0,park4[0]);
  lc.setRow(0,1,park4[1]);
  lc.setRow(0,2,park4[2]);
  lc.setRow(0,3,park4[3]);
  lc.setRow(0,4,park4[4]);
  lc.setRow(0,5,park4[5]);
  lc.setRow(0,6,park4[6]);
  lc.setRow(0,7,park4[7]);
  lc.setRow(0,8,park4[8]);
  delay(delaytime);
  }
  
// Main Code
void setup() {
  lc.shutdown(0,false);
  lc.setIntensity(0,8);
  lc.clearDisplay(0);
  
 
  pinMode(ParkingSenA, INPUT);
  pinMode(ParkingSenB, INPUT);
  pinMode(ParkingSenC, INPUT);
  pinMode(ParkingSenD, INPUT);
}


void loop() {

  PSenA = digitalRead(ParkingSenA);
  PSenB = digitalRead(ParkingSenB);
  PSenC = digitalRead(ParkingSenC);
  PSenD = digitalRead(ParkingSenD);
  
  // ADD THE FUNCTION OF WHICH SPOT IS VACANT; THEIR CALLED 'writeArduinoNum'
  
  if (PSenA,PSenB,PSenC,PSenD == LOW){ //Spots all taken
    writeArudinoShape1();
    writeArudinoShape2();
    writeArudinoShape1();
    writeArudinoShape2();
    }
    else if(PSenA == HIGH && PSenB,PSenC,PSenD == LOW){ //Spot 1 Vacant
      writeArudinoShape1();
      writeArudinoShape2();
      writeArudinoShape3();
      }
      else if (PSenB == HIGH && PSenC,PSenD,PSenA == LOW){ //Spot 2 Vacant
        writeArudinoShape1();
        writeArudinoShape2();
        writeArudinoShape4();
        }
        else if (PSenC == HIGH && PSenD,PSenA,PSenB == LOW){ //Spot 3 Vacant
          writeArudinoShape1();
          writeArudinoShape2();
          writeArudinoShape1();
          writeArudinoShape3();
          }
          else if (PSenD == HIGH && PSenA,PSenB,PSenC == LOW){ //Spot 4 Vacant
            writeArudinoShape1();
            writeArudinoShape2();
            writeArudinoShape1();
            writeArudinoShape4();
           }
  else
  {
    
    }
}
