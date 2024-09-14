
/*
*xyz robot
*
*/
int xyzrobot = 0;
String inString = "";  // string to hold input

int delayus = 500;//delayMicroseconds(delayus);

int dirPin1 = 16;
int stepPin1 = 15;
int enPin1 = 13;

int dirPin2 = 2;
int stepPin2 = 3;
int enPin2 = 4;

int dirPin3 = 19;
int stepPin3 = 18;
int enPin3 = 17;


void setup() {

  
    pinMode(dirPin1,OUTPUT);
    pinMode(stepPin1,OUTPUT);
    pinMode(enPin1,OUTPUT);
    pinMode(dirPin2,OUTPUT);
    pinMode(stepPin2,OUTPUT);
    pinMode(enPin2,OUTPUT);
    pinMode(dirPin3,OUTPUT);
    pinMode(stepPin3,OUTPUT);
    pinMode(enPin3,OUTPUT);

    digitalWrite(dirPin1,LOW);
    digitalWrite(stepPin1,LOW);
    digitalWrite(enPin1,HIGH);
    digitalWrite(dirPin2,LOW);
    digitalWrite(stepPin2,LOW);
    digitalWrite(enPin2,HIGH);
    digitalWrite(dirPin3,LOW);
    digitalWrite(stepPin3,LOW);
    digitalWrite(enPin3,HIGH);
    Serial.begin(9600);//set the baud rate to 9600 baud.

}


void loop() {
 while (Serial.available() > 0) {
    int inChar = Serial.read();
    if (isDigit(inChar)) {
      // convert the incoming byte to a char and add it to the string:
      inString += (char)inChar;
    }
    // if you get a newline, print the string, then the string's value:
    if (inChar == '\n') {
      xyzrobot = inString.toInt();
      inString = "";
    }
  }

  if(xyzrobot == 1){
     moveLeft(1);
  }
  if(xyzrobot == 2){
     moveRight(1);
  }
  if(xyzrobot == 3){
    moveUp(1); 
  }
  if(xyzrobot == 4){
    moveDown(1); 
  }
  if(xyzrobot == 5){
    moveAway(1);
  }
  if(xyzrobot == 6){
    moveTowards(1);
 }  
  delay(1); // Pause before next pass through loop

}


void moveLeft(int nSteps){
     digitalWrite(dirPin1,LOW);
     digitalWrite(enPin1,LOW);
     digitalWrite(dirPin3,HIGH);
     digitalWrite(enPin3,LOW);
     
     for(int index = 0;index < nSteps;index++){
       digitalWrite(stepPin1,HIGH);
       delayMicroseconds(delayus); 
       digitalWrite(stepPin1,LOW);
       delayMicroseconds(delayus); 
       digitalWrite(stepPin3,HIGH);
       delayMicroseconds(delayus); 
       digitalWrite(stepPin3,LOW);
       delayMicroseconds(delayus); 

     }          
     digitalWrite(enPin1,HIGH);   
     digitalWrite(enPin2,HIGH);   
}

void moveRight(int nSteps){
     digitalWrite(dirPin1,HIGH);
     digitalWrite(enPin1,LOW);
     digitalWrite(dirPin3,LOW);
     digitalWrite(enPin3,LOW);
    
     for(int index = 0;index < nSteps;index++){
       digitalWrite(stepPin1,HIGH);
       delayMicroseconds(delayus); 
       digitalWrite(stepPin1,LOW);
       delayMicroseconds(delayus); 
       digitalWrite(stepPin3,HIGH);
       delayMicroseconds(delayus); 
       digitalWrite(stepPin3,LOW);
       delayMicroseconds(delayus); 

     }          
     digitalWrite(enPin1,HIGH);   
     digitalWrite(enPin3,HIGH);   

}

void moveDown(int nSteps){
     digitalWrite(dirPin1,HIGH);
     digitalWrite(enPin1,LOW);
     digitalWrite(dirPin3,HIGH);
     digitalWrite(enPin3,LOW);
     
     for(int index = 0;index < nSteps;index++){
       digitalWrite(stepPin1,HIGH);
       delayMicroseconds(delayus); 
       digitalWrite(stepPin1,LOW);
       delayMicroseconds(delayus); 
       digitalWrite(stepPin3,HIGH);
       delayMicroseconds(delayus); 
       digitalWrite(stepPin3,LOW);
       delayMicroseconds(delayus); 
     }          
     digitalWrite(enPin1,HIGH);   
     digitalWrite(enPin3,HIGH);   

}

void moveUp(int nSteps){
     digitalWrite(dirPin1,LOW);
     digitalWrite(enPin1,LOW);
     digitalWrite(dirPin3,LOW);
     digitalWrite(enPin3,LOW);     
     for(int index = 0;index < nSteps;index++){
       digitalWrite(stepPin1,HIGH);
       delayMicroseconds(delayus); 
       digitalWrite(stepPin1,LOW);
       delayMicroseconds(delayus); 
       digitalWrite(stepPin3,HIGH);
       delayMicroseconds(delayus); 
       digitalWrite(stepPin3,LOW);
       delayMicroseconds(delayus); 
     }          
     digitalWrite(enPin3,HIGH);    
     digitalWrite(enPin1,HIGH);

}

void moveAway(int nSteps){
     digitalWrite(dirPin2,LOW);
     digitalWrite(enPin2,LOW);
     
     for(int index = 0;index < nSteps;index++){
       digitalWrite(stepPin2,HIGH);
       delayMicroseconds(delayus); 
       digitalWrite(stepPin2,LOW);
       delayMicroseconds(delayus); 
     }          
     digitalWrite(enPin2,HIGH);   
}

void moveTowards(int nSteps){
     digitalWrite(dirPin2,HIGH);
     digitalWrite(enPin2,LOW);
     
     for(int index = 0;index < nSteps;index++){
       digitalWrite(stepPin2,HIGH);
       delayMicroseconds(delayus); 
       digitalWrite(stepPin2,LOW);
       delayMicroseconds(delayus); 
     }          
     digitalWrite(enPin2,HIGH);   
}
