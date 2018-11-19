*Le but du module 1 est de faire un premier lien entre le hardware et le software. *

**cardio.c :**
* `int menuCardio()` : Lance les fonctions ci dessous. Possède un timer `timecount` prenant la valeur de `millis()` et lance la détection du port A0 sur l'arduino en la stockant dans `sensoval`. Retourne `valDetect`. 
* `int hasChanged(float sensorva1)` : Lit A0 et compare sa valeur au temps t à une valeur seuil (définie à 218). Dès qu'une valeut dépasse ce seuil, la fonction renvoie 1 sinon elle renvoie 0. Dans `menuCardio`, on stock le return dans `beat`
* `int beatHasChanged(int beatbeforebis, int beat)` : Lit la valeur de `beat` et enlève les 1 et 0 superflus. On stocke les nouvelles informations dans `valDetect` dans `menuCardio()`.
* `void sendCom(int timecountbis, int beat)` : Récupère `timecount` et `beat` pour les envoyer sous forme de string via un Serial.print. On sépare les deux élements par un **;** et termine la chaîne de caractères par **&**.
