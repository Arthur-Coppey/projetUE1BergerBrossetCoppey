#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include "data.h"

typedef struct data data;

typedef struct bpm bpm;

void divide(bpm *rate, bpm *rate1, bpm *rate2, int size1,
		int size2) {
	for (int i = 0; i < size1; i++) {
		rate1[i] = rate[i];
	}
	for (int i = 0; i < size2; i++) {
		rate2[i] = rate[i + size1];
	}
}

void merge(bpm *rate, bpm *rate1, bpm *rate2, int size1,
		int size2, int mode) {
	int i = 0, j = 0, k = 0, m;
	while (i < size1 && j < size2) {
		if (mode == 1) {
			if (rate1[i].ms < rate2[j].ms) {
				rate[k] = rate1[i];
				i++;
			} else {
				rate[k] = rate2[j];
				j++;
			}
		} else {
			if (rate1[i].bpm < rate2[j].bpm) {
				rate[k] = rate1[i];
				i++;
			} else {
				rate[k] = rate2[j];
				j++;
			}
		}
		k++;
	}
	if (i != size1) {
		for (m = i; m < size1; m++) {
			rate[k] = rate1[m];
			k++;
		}
	} else {
		for (m = j; m < size2; m++) {
			rate[k] = rate2[j];
			k++;
		}
	}
	for (i = 0; i < size1 + size2; i++) {
		printf("rate[%d].ms = %d; rate[%d].bpm = %f;\n", i, rate[i].ms, i,
				rate[i].bpm);
		fflush(stdout);
		getch();
	}
}

void sort(bpm *rate, int size, int mode) {
	int size1 = size / 2, size2 = size - (size / 2);
	bpm rate1[size1], rate2[size2];
	if (size > 1) {
		divide(rate, rate1, rate2, size1, size2);
		sort(rate1, size1, mode);
		sort(rate2, size2, mode);
		merge(rate, rate1, rate2, size1, size2, mode);
	}
}

int search(bpm *rate, int mode, int querry) {
	int size = sizeof(rate) / sizeof(bpm), index, res, min = 0, max = size
			- 1;
	if (mode == 1) {
		//search by time
		while (res != querry) {
			index = (min + max) / 2;
			res = rate[index].ms;
			if (res < querry) {
				max = index;
			} else if (res > querry) {
				min = index;
			}
		}
	} else {
		//search by rate
		while (res != querry) {
			index = (min + max) / 2;
			res = rate[index].bpm;
			if (res < querry) {
				max = index;
			} else if (res > querry) {
				min = index;
			}
		}
	}
	return index;
}
