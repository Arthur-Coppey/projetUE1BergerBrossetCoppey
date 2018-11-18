# Programme C:
## Structures
### data  
Contient deux propriétés de type int :  
* `int time` : un temps en ms.
* `int pulse` : une variable binaire indiquant la présence ou l’absence d’une pulsation cardiaque.  

Cette structure est utilisée pour récupérer et stocker les données directement depuis le csv avant d’être traitées
### bpm
Contient deux propriétés, un float et un int :
* `int ms` : un écart entre deux pulsations.
* `float bpm` : un rythme cardiaque calculé grâce à la valeur de ms.  

Cette structure est utilisée pour stocker les informations du csv après traitement.
## Bibliothèques
### menu.h et menu.c
Cette bibliothèque contient les fonctions concernant l’affichage des résultats.  
Elle contient les fonctions :  
* `void menuMain()` : affiche le menu principal.  
* `void displayData(bpm *rate, int order, int size)` : affiche les données rentrées en paramètre `*rate` selon l’ordre donné en paramètre `order`, paramètre `size` passé pour le calculer moins de fois.  
* `void menuSortMode()` : affiche le menu de sélection du paramètre utilisé pour le tri (rythme cardiaque ou temps entre deux battements).
* `void menuDisplayOrder()` : affiche le menu de sélection de l’ordre d’affichage (croissant ou décroissant)
* `void displayExtremums(bpm *extremums)` : affiche les maximums et minimums obtenus par la fonction `getExtremums()` de actions.h
* `void displayAverage(float avrg)` : affiche la moyenne de rythme cardiaque obtenue par la fonction `average()` de actions.h
* `void displayLines(int lines, int ram)` : affiche le nombre de lignes de données en mémoire ainsi que la ram qu’elles occupent.
### data.h et data.c
Cette bibliothèque contient les fonctions relatives à la manipulation des données.  
Elle contient les fonctions : 
* `void divide(bpm *rate, bpm *rate1, bpm *rate2, int size1, int size2)` : cette fonction sert à diviser un tableau de données en deux, elle n’est utilisée que pour le tri fusion.
* `void merge(bpm *rate, bpm *rate1, bpm *rate2, int size1, int size2, int mode)` : cette fonction sert à fusionner deux tableaux de données triés, elle est utilisée pour le tri fusion.
* `void sort(bpm *rate, int size, int mode)` : cette fonction utilise les deux précédentes pour trier un tableau de données non triés selon un paramètre passé sous la variable `mode`.
* `int search(bpm *rate, int mode, int querry, int size)` : cette fonction permet de chercher un rythme cardiaque pour un temps donné
### actions.h et actions.c
Cette bibliothèque contient toutes les fonctions pour contrôler l’affichage et les calculs.  
Elle contient : 
* `int getUserInput(int min, int max)` : cette fonction est utilisée pour demander un nombre entre min et max à l’utilisateur sans accepter d’entrée invalide
* `int getDataSize()` : cette fonction lit le fichier .csv pour retourner le nombre de lignes qu’il contient, elle permet de déterminer la taille du tableau de données
* `void getData(data *dt, int size)` : cette fonction permet de récupérer les  données du .csv et les stocker dans un tableau de structure data
* `void sortBy(bpm *rate, int size)` : cette fonction permet de demander à l’utilisateur comment il veut trier les données. elle appelle la fonction de tri et la fonction d’affichage.
* `float average(bpm *rate, int size)` : cette fonction demande à l’utilisateur deux temps minimum et maximum et affiche la moyenne du rythme cardiaque entre ces deux temps.
* `void fileOrder(bpm *rate, int size)` : cette fonction affiche les données dans l’ordre stocké dans le .csv
* `void time(bpm *rate, int size)` : cette fonction demande un temps à l’utilisateur et affiche les rythmes cardiaques correspondants
* `void getExtremums(bpm *rate, bpm *extremums, int size)` : cette fonction obtient les extrema de rythmes cardiaques et les temps correspondants
* `void getMainMenuInput()` : cette fonction permet de récupérer l’entrée de l’utilisateur dans le menu principal et d’agir en conséquence
* `void getRate(data *dt, data *dt1, int size, int size1, bpm *rate)` : cette fonction est dédiée au traitement des données, elle transforme l'entrée brute depuis le fichier .csv en tableau de structures `bpm`
* `int getBeats(data *dt, int size)` : cette fonction est une des fonction de traitement des données, elle récupère le nombre de battements enregistrés
### structureDef.h
Cette bibliothèque contient les déclarations des structures de données data et bpm  
```c
struct data {
    int time;
    int pulse;
};
```

```c
struct bpm {
    int ms;
    float bpm;
};
```

