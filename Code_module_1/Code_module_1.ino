//La deuxième partie de ce module est la programmation Arduino qui détecte, mesure et
//calcule le pouls à partir des informations envoyées par le récepteur IR. Le code devra être
//organisé en deux fichiers :
// main.c (qui contient le loop et le setup)
// cardio.c (et .h) qui contient les fonctions propres à la récolte des informations et aux
//calculs pour avoir le pouls.
//Ce module doit envoyer sur le port série deux valeurs (au format csv avec un « ; ») :
// le nombre de millisecondes depuis le démarrage du programme Arduino
// le pouls calculé à partir des informations récoltées par le récepteur IR.
//En attendant le montage et la mise au point du module Cardio, vous devez envoyer via le
//port série cette information à intervalles réguliers (avec le même format décrit ci-dessus)
//générée de façon aléatoire (avec des valeurs cohérentes pour un pouls).
//

#define bus1 A0

int sensorval;
float sensorvalbefore = -888;
unsigned long timer;
int detect = 0;
int detectbefore = 0;
int beat = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {

  //*****************************************
  //            MODULE TIMER
  //*****************************************

  // Serial.println(timer ); POUR VERIFIER
  timer = millis();


  //*****************************************
  //          MODULE DETECTION
  //*****************************************

  sensorval = analogRead(bus1);

  if (sensorval > sensorvalbefore) {
    detect = 1;
    // Serial.print(sensorval);
  } else {
    if (sensorval < sensorvalbefore) {
      detect = 0;
    } else {
      if (sensorvalbefore == -888) {
        sensorvalbefore = sensorval;
      }
    }
  }

  //****************************************
  //       MODULE REGULARISATION POULS
  //********************s********************

  if (detectbefore == 0 && detect == 1) {
    beat = 1;
  }


  //******************************************
  //             MODULE POULS
  //*******************************************


  int sensorvalue;

  while (timer % 5000 !=  0) {
    if (beat == 1) {
      sensorvalue++;
    }
  }
  if (timer%5000 == 0){
    int beats = sensorvalue *12;
    Serial.print(timer);
    Serial.print(beats);
    Serial.print(";");
  }

    

    //***** réinitialisation des variables*****

    sensorvalbefore = sensorval;
    detectbefore = detect;
    detect = 0;
    beat = 0;

  }
