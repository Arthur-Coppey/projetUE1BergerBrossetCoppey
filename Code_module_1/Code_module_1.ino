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
  //            MODULE DETECTION
  //*****************************************
  
  sensorval = analogRead(bus1);
  float comparesensorval = sensorval-sensorvalbefore;

  switch(comparesensorval){
  case(<0sdfsdf
    
  }


  if (sensorval > sensorvalbefore) {
    Serial.print(sensorval);
  } else {
    if (sensorval < sensorvalbefore) {
       return 0;
    } else {
      if (sensorvalbefore == -888) {
        sensorvalbefore = sensorval;
      }
    }
  }
  sensorvalbefore = sensorval;

  
}
