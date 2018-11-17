#ifndef MODULE4_SRC_LIB_MENU_H_
#define MODULE4_SRC_LIB_MENU_H_

#include "structureDef.h"

typedef struct data data;

typedef struct bpm bpm;

void menuMain();

void displayData(bpm *rate, int order, int size);

void menuSortMode();

void menuDisplayOrder();

void displayExtremums(bpm *extremums);

void displayAverage(float avrg);

void displayLines(int lines);

#endif /* MODULE4_SRC_LIB_MENU_H_ */
