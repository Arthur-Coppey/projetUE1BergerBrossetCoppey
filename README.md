# Arduino


# Générateur de param.h

## Structures

### led
Cette structure est utilisée pour stocker les informations à propos d'une led.  
Elle contient :
* `int id` : le port sur lequel la led est branché
* `int state` : 0 ou 1, l'état de la led : éteinte ou allumée

### step
Cette structure est utilisée pour stocker les informations à propos d'une étape d'affichage.  
Elle contient :
* `struct led *led` : un tableau de structures led définissant les leds allumées et celles éteintes
* `struct step *next` : un pointeur vers la prochaine structure step, qui contient les infos pour l'étape suivante
* `int index` : un entier indiquant le nombre correspondant à l'étape (0 pour la première, 1 pour la deuxième etc)

### sequence
Cette structure est utilisée pour stocker des informations sur une séquence d'affichage de leds.  
Elle contient :
* `int length` : la taille de la séquence, son nombre d'étapes
* `struct step *first` : un pointeur vers la première étape de la séquence

## Bibliothèques

### generateCode.h et generateCode.c
Cette bibliothèque contient toutes les fonctions de calcul et d'écriture de fichier.  
Elle contient :
* `int pushStepInSequence(struct sequence *seq, struct step *step)` : cette fonction enfile une étape une séquence
* `int newStep(struct sequence *seq, struct led leds[10])` : cette fonction transforme un tableau de led en step et appelle la fonction `pushStepInSequence()` pour enfiler cette étape dans la séquence
* `int showSequence(struct sequence *seq)` : fonction utilisée pendant le développement pour visualiser les séquences
* `int generateFile(struct sequence *seq)` : fonction générant un fichier param.h selon la structure qu'on lui passe en argument
* `int generateBlink()` : fonction générant la séquence pour faire clignoter toutes les leds ensemble et appelant `generateFile()` pour écrire param.h
* `int generateOneTwo()` : identique à celle précédente mais pour faire clignoter une led sur deux en alternance
* `int generateOneThree()` : indem pour une led sur trois
* `int generateOne(int id)` : génère la séquence pour ne faire clignoter qu'une seule led dont le port est passé en argument puis appelle `generateFile()`
* `int generateCaterpillar()` : génère la sequence pour que les leds s'allument "en chenille" et appelle `generateFile()`

### menu.h et menu.c
Cette bibliothèque contient les fonctions utilisées pour afficher les menus.  
Elle contient :
* `void showMenu()` : affiche le menu principal
* `int modeInput()` : récupère un chiffre entré par l'utilisateur
* `void customDisplayMenu()` : affiche le menu qui explique comment fonctionne les séquences personnalisées
* `void inputCustomDisplayStep(struct sequence *seq)` : récupère l'étape entrée par l'utilisateur et l'ajoute à la séquence
* `void showCustomDisplay(struct sequence *seq)` : affiche la séquence personnalisée actuelle
* `void menu()` : gère les appels des autres fonctions et les entrées de l'utilisateur

### structdef.h
Cette bibliothèque contient les définitions des structures pesonnalisées  
```c
struct led {
    int id;
    int state;
};

struct step {
    int index;
    struct led leds[10];
    struct step * next;
};

struct sequence {
    struct step * first;
    int length;
};
```
