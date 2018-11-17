#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "menu.h"
#include "actions.h"
#include "data.h"

typedef struct data data;

typedef struct bpm bpm;

int getDataSize() {
	int size = 0;
	char buffer[5000];
	FILE *file;
	if ((file = fopen("Battement.csv", "r")) != NULL) {
		while (fscanf(file, "%s", buffer) != EOF) {
			size++;
		}
	}
	else {
		puts("cannot open file");
		fflush(stdout);
	}
	fclose(file);
	return size;
}

void getData(data *dt, int size) {
	FILE *file;
	int time = 0, pulse = 0;
	char str[20], *template = "%d;%d&";
	if ((file = fopen("Battement.csv", "r")) != NULL) {
		for (int i = 0; i < size; i++) {
			fscanf(file, "%s", str);
			sscanf(str, template, &time, &pulse);
			dt[i].time = time;
			dt[i].pulse = pulse;
		}
	}
	else {
		puts("cannot open file");
		fflush(stdout);
	}
	fclose(file);
}

int getUserInput(int min, int max) {
	int out, code = 0;
	char input[1] = "";
	while (code == 0 || (out < min && out > max)) {
		scanf("%s", input);
		code = strcmp(input, "");
		sscanf(input, "%d", &out);
	}
	return out;
}

void sortBy(bpm *rate, int size) {
	int mode, order;
	menuSortMode();
	mode = getUserInput(1, 2);
	sort(rate, size, mode);
	menuDisplayOrder();
	order = getUserInput(1, 2);
	displayData(rate, order, size);
}

float average(bpm *rate, int size) {
	int min, max;
	float avrg = 0.0;
	sort(rate, size, 1);
	min = rate[0].ms;
	max = rate[size - 1].ms;
	printf("Minimum time ? \n");
	min = getUserInput(min, max);
	printf("Maximum time ? \n");
	max = getUserInput(min, max);
	for (int i = 0; i < size; i++) {
		avrg += rate[i].bpm;
	}
	avrg /= (float) size;
	return avrg;
}

void fileOrder(bpm *rate, int size) {
	displayData(rate, 1, size);
}

void time() {

}

int getBeats(data *dt, int size) {
	int beats = 0;
	for (int i = 0; i < size; i++) {
		beats += dt[i].pulse;
	}
	return beats;
}

void getRate(data *dt, data *dt1, int size, int size1, bpm *rate) {
	int j = 0, beats = size1;
	for (int i = 0; i < size; i++) {
		if (dt[i - 1].pulse == 0 && dt[i].pulse == 1) {
			dt1[j].time = dt[i].time;
			dt1[j].pulse = dt[i].pulse;
			j++;
		}
	}
	for (int i = 0; i < beats - 1; i++) {
		rate[i].ms = dt1[i + 1].time - dt1[i].time;
		rate[i].bpm = (1.0 / (dt1[i + 1].time - dt1[i].time)) * 60000;
	}
}

void getExtremums(bpm *rate, bpm *out, int size) {
	sort(rate, size, 1);
	out[0].ms = rate[0].ms;
	out[0].bpm = rate[0].bpm;
	out[1].ms = rate[size - 1].ms;
	out[1].bpm = rate[size - 1].bpm;
}

void getMainMenuInput() {
	int size = getDataSize(), size1;
	float avrg;
	data dt[size];
	getData(dt, size);
	size1 = getBeats(dt, size);
	data dt1[size1];
	bpm rate[size1 - 1], extremums[2];
	getRate(dt, dt1, size, size1, rate);
	switch (getUserInput(1, 7)) {
	case 1:
		fileOrder(rate, size1 - 1);
		break;
	case 2:
		sortBy(rate, size1 - 1);
		break;
	case 3:
		time(rate);
		break;
	case 4:
		avrg = average(rate, size1 - 1);
		displayAverage(avrg);
		break;
	case 5:
		displayLines(size1 - 1);
		break;
	case 6:
		getExtremums(rate, extremums, size1 - 1);
		displayExtremums(extremums);
		break;
	case 7:
		break;
	}
}
