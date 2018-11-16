#include "param.h"
void readSequence();

void setup(){
  Serial.begin(9600);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);  
}

void loop(){
 Serial.println(analogRead(A0));
 readSequence();

}


void readSequence()
{
  int i, j, stepNumber, state, output;
  stepNumber = (sizeof(sequence)) / (sizeof(sequence[0]));
  for(i=0; i<stepNumber; i++){

          if(analogRead(A0) > 218){
            for (j = 0; j < 10; j++) {
              state = sequence[i][j][1];
              output = sequence[i][j][0];
              if ( state == 1) {
                digitalWrite (output, HIGH);
              }
              else {
                digitalWrite (output, LOW);
              }
            }
          delay(250);
        }
     }
  }
  
