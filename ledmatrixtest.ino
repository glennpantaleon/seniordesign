int latchPin = 12;  //Pin connected to ST_CP of 1st 74595
int clockPin = 13;  //Pin connected to SH_CP of 1st 74595
int dataPin = 11;   //Pin connected to DS of 1st 74595

int latchPin2 = 6;  //Pin connected to ST_CP of 2nd 74595
int clockPin2 = 7;  //Pin connected to SH_CP of 2nd 74595
int dataPin2 = 5;   //Pin connected to DS of 2nd 74595

void setup() {
  //set pins to output so you can control the shift register
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  
  pinMode(latchPin2, OUTPUT);
  pinMode(clockPin2, OUTPUT);
  pinMode(dataPin2, OUTPUT);
}

void loop() {
  
    /********** Send HIGH to all Anode pins of LED matrix **********/    
  
    // take the latchPin low so the LEDs don't change while you're sending in bits:  
    digitalWrite(latchPin, LOW);
    //Send 1 1 1 1 1 1 1 1 (255) to Q7 Q6 Q5 Q4 Q3 Q2 Q1 Q0 of 1st 74595
    shiftOut(dataPin, clockPin, MSBFIRST, 255);
    // shift out the bits:    
    digitalWrite(latchPin, HIGH);
    /********** Send LOW to all Cathode pins of LED matrix **********/    
    
    // take the latchPin low so the LEDs don't change while you're sending in bits:    
    digitalWrite(latchPin2, LOW);
    //Send 0 0 0 0 0 0 0 0 (0) to Q7 Q6 Q5 Q4 Q3 Q2 Q1 Q0 of 2nd 74595
    shiftOut(dataPin2, clockPin2, MSBFIRST, 0);
    // shift out the bits:  
    digitalWrite(latchPin2, HIGH);
}
