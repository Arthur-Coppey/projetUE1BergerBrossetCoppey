#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "generateCode.h"

int pushStepInSequence(struct sequence *seq, struct step *stp) {
	struct step *tmp = seq->first;
	int i = 0;
	if (seq->length == 0) {
		stp->next = tmp;
		seq->first = stp;
	} else {
		while (i < seq->length - 1 && tmp != NULL) {
			tmp = tmp->next;
			i++;
		}
		stp->next = tmp->next;
		tmp->next = stp;
	}
	stp->index = seq->length;
	seq->length++;
	return 1;
}

int newStep(struct sequence *seq, struct led leds[10]) {
	struct step *stp;
	if ((stp = malloc(sizeof(struct step))) != NULL) {
		for (int i = 0; i < 10; i++) {
			(*stp).leds[i].id = (leds)[i].id;
			(*stp).leds[i].state = (leds)[i].state;
		}
		pushStepInSequence(seq, stp);
		return 1;
	}
	return 0;
}

int showSequence(struct sequence *seq) {
	int i = 0;
	struct step *stp = seq->first;
	//printf("michel");
	//fflush(stdout);
	while (stp != NULL && i < seq->length) {
		for (int j = 0; j < 10; j++) {
			printf("%d : led_%d : %d\n", stp->index, stp->leds[j].id,
					stp->leds[j].state);
			fflush(stdout);
		}
		stp = stp->next;
		i++;
	}
	/*if (length < 1) {
		return 0;
	}
	for (i = 0; i < length; i++) {
		if (i == 0) {
			stp = seq->first;
		} else {
			stp = stp->next;
		}
		for (j = 0; j < 10; j++) {
			printf("%d:led_%d:%d\n", stp->index, stp->leds[j].id,
					stp->leds[j].state);
			fflush(stdout);
		}
	 }*/
	return 1;
}

int generateFile(struct sequence *seq) {
	FILE *file;
	struct step *stp;
	stp = malloc(sizeof(struct step));
	if ((file = fopen("param.h", "w")) == NULL) {
		return 0;
	} else {
		system("cls");
		printf("generating param\n");
		fflush(stdout);

		fprintf(file,
				"#ifndef MODULE2_SETTINGS_SRC_PARAM_H_\n#define MODULE2_SETTINGS_SRC_PARAM_H_\n");
		for (int i = 0; i < seq->length; i++) {
			if (i == 0) {
				stp = seq->first;
			} else {
				stp = stp->next;
			}
			for (int j = 0;
					j < sizeof(seq->first->leds) / sizeof(seq->first->leds[0]);
					j++) {
				fprintf(file, "int led_%d_%d[2] = {%d,%d};\n", i, j,
						stp->leds[j].id, stp->leds[j].state);
			}
			fprintf(file, "int *step_%d[%d] = {", i,
					sizeof(seq->first->leds) / sizeof(seq->first->leds[0]));
			for (int j = 0;
					j < sizeof(seq->first->leds) / sizeof(seq->first->leds[0]);
					j++) {
				if (j > 0) {
					fprintf(file, ",");
				}
				fprintf(file, "led_%d_%d", i, j);
			}
			fprintf(file, "};\n");
		}
		fprintf(file, "int ** sequence[%d] = {", seq->length);
		for (int i = 0; i < seq->length; i++) {
			if (i > 0) {
				fprintf(file, ",");
			}
			fprintf(file, "step_%d", i);
		}
		fprintf(file, "};\n");
		fprintf(file, "#endif /* MODULE2_SETTINGS_SRC_PARAM_H_ */\n");
		fflush(file);
		printf("param file generated, please compile arduino code again");
		fclose(file);
		getch();
		fflush(stdout);
	}
	return 1;
}

int generateBlink() {
	struct sequence seq;
	struct led leds[10];
	seq.length = 0;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 10; j++) {
			leds[j].id = j + 4;
			leds[j].state = i;
		}
		newStep(&seq, leds);
	}
	generateFile(&seq);
	return 0;
}

int generateOneTwo() {
	struct sequence seq;
	struct led leds[10];
	seq.length = 0;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 10; j++) {
			leds[j].id = j + 4;
			leds[j].state = (j + i) % 2;
		}
		newStep(&seq, leds);
	}
	generateFile(&seq);
	return 0;
}

int generateOneThree() {
	struct sequence seq;
	struct led leds[10];
	seq.length = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 10; j++) {
			leds[j].id = j + 4;
			leds[j].state = ((j + i) % 3) % 2;
		}
		newStep(&seq, leds);
	}
	generateFile(&seq);
	return 0;
}

int generateOne(int id) {
	struct sequence seq;
	struct led leds[10];
	seq.length = 0;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 10; j++) {
			leds[j].id = j + 4;
			leds[j].state = i * (leds[j].id == id);
		}
		newStep(&seq, leds);
	}
	generateFile(&seq);
	return 0;
}

int generateCaterpillar() {
	struct sequence seq;
	struct led leds[10];
	seq.length = 0;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if ((i <= j && j < i + 3) || (10 <= i + 3 && j < (i + 3) % 10)) {
				leds[j].state = 1;
			} else {
				leds[j].state = 0;
			}
			leds[j].id = j + 4;
		}
		newStep(&seq, leds);
	}
	generateFile(&seq);
	return 0;
}
