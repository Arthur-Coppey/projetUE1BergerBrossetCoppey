#include "cardio.h"
#include "Arduino.h"
#include "stdlib.h"
#define threshold 218

float sensorva1;
float sensorvalbefore = -888;
int beatbefore  = 0;


int hasChanged(float sensorva1)
{

  if (sensorva1 >= threshold) {
    return 1;
  }
  else {
    return 0;
  }
}

int beatHasChanged(int beatbeforebis, int beat) {
  if (beatbefore == 0 && beat == 1) {
    return 1;
  }
  else {
    if (beatbefore == 0 && beat == 0) {
      return 2;
    } else {
      return 0;
    }
  }
}

void sendCom(int timecountbis, int beat) {
  String myString = String(timecountbis);
  String myString2 = String(beat);
 // Serial.print(String( myString + ";" + myString2 + "&"));
  // Serial.print(myString2);
}

int menuCardio() {
  long timecount;
  timecount = millis();
  sensorva1 = analogRead(A0);
  int beat = 0;
  beat = hasChanged(sensorva1);
  int valDetect = beatHasChanged (beatbefore, beat);
  if (valDetect == 2) {
    sensorvalbefore = sensorva1;
    beatbefore = beat;
    valDetect = 0;
    return valDetect;
  }
  else {
    sendCom(timecount, valDetect);
    sensorvalbefore = sensorva1;
    beatbefore = beat;
    return valDetect;
  }
}
