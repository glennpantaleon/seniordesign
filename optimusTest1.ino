#include <NewPing.h>

int L_IN_Positive = 14; // ARDUINO (A0) ------ L293 (L +)
int L_IN_Negative = 15; // ARDUINO (A1) ------ L293 (L-)
int R_IN_Positive = 16; // ARDUINO (A2) ------ L293 (R +)
int R_IN_Negative = 17; // ARDUINO (A3) ------ L293 (R-)

/ ************************************************* *****************************************
* About the definition of obstacle avoidance sensors and wiring instructions
************************************************** **************************************** /
const int SensorLeft = 2; // left obstacle avoidance sensor (OUT) ------ L293D driver board (LXJ)
// L293D driver board (LXJK) ------ ARDUINO (2)
const int SensorRight = 6; // Right tracking sensor (OUT) ------ L293D driver board (RXJ)
// L293D driver board (RXJK) ------ ARDUINO (6)

/ ************************************************* *****************************************
* About sensor status lights variables
************************************************** **************************************** /
int SL; // left avoidance Status Light Note: When the car left in front of the set range obstacles, SL = LOW, left the status lights, the car needs to turn right to avoid obstacles;
int SR; // Right avoidance Status Light Note: When the car right in front within the set range obstacles, SR = LOW, the right status lights, turn left the car needs to avoid obstacles;

/ ************************************************* *****************************************
* Port Initialization
************************************************** **************************************** /
void setup ()
{
Serial.begin (9600);
pinMode (L_IN_Positive, OUTPUT); // pin 14 (PWM)
pinMode (L_IN_Negative, OUTPUT); // pin 15 (PWM)
pinMode (R_IN_Positive, OUTPUT); // pin 16 (PWM)
pinMode (R_IN_Negative, OUTPUT); // pin 17 (PWM)
pinMode (SensorLeft, INPUT);
pinMode (SensorRight, INPUT);
}

/ ************************************************* *****************************************
* The main program
************************************************** **************************************** /
void loop ()
{
SL = digitalRead (SensorLeft);
SR = digitalRead (SensorRight);
if (SL == HIGH && SR == HIGH) // car left front and right front are not obstacles, about the status lights are not bright, the car forward
{
digitalWrite (L_IN_Positive, HIGH);
digitalWrite (L_IN_Negative, LOW);
analogWrite (L_IN_Positive, 150);
analogWrite (L_IN_Negative, 0);
digitalWrite (R_IN_Positive, HIGH);
digitalWrite (R_IN_Negative, LOW);
analogWrite (R_IN_Positive, 150);
analogWrite (R_IN_Negative, 0);
}
else
{
if (SL == HIGH & SR == LOW) // car right in front of obstacles, the right status lights, turn left the car
{
delay (1);
digitalWrite (L_IN_Positive, LOW);
digitalWrite (L_IN_Negative, LOW);
digitalWrite (R_IN_Positive, HIGH);
digitalWrite (R_IN_Negative, LOW);
analogWrite (R_IN_Positive, 130);
analogWrite (R_IN_Negative, 0);
}
else if (SR == HIGH & SL == LOW) // car left front obstacles, left the status lights, turn right car
{
delay (1);
digitalWrite (L_IN_Positive, HIGH);
digitalWrite (L_IN_Negative, LOW);
analogWrite (L_IN_Positive, 130);
analogWrite (L_IN_Negative, 0);
digitalWrite (R_IN_Positive, LOW);
digitalWrite (R_IN_Negative, LOW);
}
else
{
delay (1);
digitalWrite (R_IN_Positive, LOW);
digitalWrite (R_IN_Negative, LOW);
digitalWrite (L_IN_Positive, LOW);
digitalWrite (L_IN_Negative, LOW);
}
}
}
/ ************************************************* *****************************************
* END
************************************************** **************************************** /

