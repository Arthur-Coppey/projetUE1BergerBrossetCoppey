#ifndef MODULE4_SRC_LIB_ACTIONS_H_
#define MODULE4_SRC_LIB_ACTIONS_H_

#include "structureDef.h"

typedef struct data data;

typedef struct bpm bpm;

int getUserInput(int min, int max);

int getDataSize();

void getData(data *dt, int size);

void sortBy(bpm *rate, int size);

float average(bpm *rate, int size);

void fileOrder(bpm *rate, int size);

void time();

void getExtremums(bpm *rate, bpm *extremums, int size);

void getMainMenuInput();

void getRate(data *dt, data *dt1, int size, int size1, bpm *rate);

int getBeats(data *dt, int size);

#endif /* MODULE4_SRC_LIB_ACTIONS_H_ */
