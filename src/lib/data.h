#ifndef MODULE4_SRC_DATA_H_
#define MODULE4_SRC_DATA_H_

#include "structureDef.h"

typedef struct data data;

typedef struct bpm bpm;

void divide(bpm *rate, bpm *rate1, bpm *rate2, int size1,
		int size2);

void merge(bpm *rate, bpm *rate1, bpm *rate2, int size1,
		int size2, int mode);

void sort(bpm *rate, int size, int mode);

int search(bpm *rate, int mode, int querry);

#endif /* MODULE4_SRC_DATA_H_ */
