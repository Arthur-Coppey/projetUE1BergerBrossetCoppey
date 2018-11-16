#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "menu.h"
#include "generateCode.h"

void showMenu() {
	puts(
			"======================================================================");
	puts(
			"|| Below are the different available settings for the LED display : ||");
	puts(
			"||------------------------------------------------------------------||");
	puts(
			"|| 1:All LED blinking display                                       ||");
	puts(
			"|| 2:One LED out of two powered on                                  ||");
	puts(
			"|| 3:One LED out of three powered on                                ||");
	puts(
			"|| 4:One chosen LED powered on                                      ||");
	puts(
			"|| 5:Caterpillar display                                            ||");
	puts(
			"|| 6:Custom display                                                 ||");
	puts(
			"||------------------------------------------------------------------||");
	puts(
			"|| Please type the corresponding digit to set the display mode      ||");
	puts(
			"======================================================================");
	fflush(stdout);
}

int modeInput() {
	int mode = 0;
	char userInput[1];
	scanf("%s", userInput);
	sscanf(userInput, "%d", &mode);
	if (mode < 1 || mode > 6) {
		return -1;
	}
	return mode;
}

void customDisplayMenu() {
	struct sequence userSeq;
	int userReq = 1;
	userSeq.length = 0;
	while (userReq != 3) {
		if (userSeq.length >= 2) {
			system("cls");
			fflush(stdout);
			puts(
					"=================================================================");
			puts(
					"|| This menu lets you configure your own led display           ||");
			puts(
					"|| A custom display is based on a sequence. A sequence is      ||");
			puts(
					"|| divided into several steps. Each step contains informations ||");
			puts(
					"|| about the leds. The state [on/off] and the pin it is        ||");
			puts(
					"|| connected to must be specified for every led.               ||");
			puts(
					"||-------------------------------------------------------------||");
			puts(
					"|| 1:New step                                                  ||");
			puts(
					"|| 2:Show current sequence                                     ||");
			puts(
					"|| 3:Apply                                                     ||");
			puts(
					"=================================================================");
			fflush(stdout);
			userReq = modeInput();
		}
		if (userReq == 1) {
			system("cls");
			fflush(stdout);
			puts(
					"=================================================================");
			puts(
					"|| This menu lets you configure your own led display           ||");
			puts(
					"|| A custom display is based on a sequence. A sequence is      ||");
			puts(
					"|| divided into several steps. Each step contains informations ||");
			puts(
					"|| about the leds. The state [on/off] and the pin it is        ||");
			puts(
					"|| connected to must be specified for every led.               ||");
			puts(
					"||-------------------------------------------------------------||");
			puts(
					"|| syntax {led,led...led} led:\"[<pin>:<state on:1|off:0>]\"     ||");
			puts(
					"|| Please type your new step :                                 ||");
			puts(
					"=================================================================");
			fflush(stdout);
			inputCustomDisplayStep(&userSeq);
		} else if (userReq == 2) {
			system("cls");
			fflush(stdout);
			showCustomDisplay(&userSeq);
			getch();
		}
	}
	generateFile(&userSeq);
}

void inputCustomDisplayStep(struct sequence *seq) {
	struct led leds[10];
	char userInput[500];
	scanf("%s", userInput);
	sscanf(userInput,
			"{[%d:%d],[%d:%d],[%d:%d],[%d:%d],[%d:%d],[%d:%d],[%d:%d],[%d:%d],[%d:%d],[%d:%d]}",
			&leds[0].id, &leds[0].state, &leds[1].id, &leds[1].state,
			&leds[2].id, &leds[2].state, &leds[3].id, &leds[3].state,
			&leds[4].id, &leds[4].state, &leds[5].id, &leds[5].state,
			&leds[6].id, &leds[6].state, &leds[7].id, &leds[7].state,
			&leds[8].id, &leds[8].state, &leds[9].id, &leds[9].state);
	newStep(seq, leds);
}

void showCustomDisplay(struct sequence *seq) {
	int length = seq->length, i, j;
	struct step *stp;
	stp = malloc(sizeof(struct step));
	for (i = 0; i < length; i++) {
		if (i == 0) {
			stp = seq->first;
		} else {
			stp = stp->next;
		}
		printf("step %d\n", stp->index);
		for (j = 0; j < sizeof(stp->leds) / sizeof(stp->leds[0]); j++) {
			printf("\tled_%d:%d\n", stp->leds[j].id,
					stp->leds[j].state);
			fflush(stdout);
		}
	}
}

void menu() {
	int mode, port = 4;
	char usrIn[1];
	showMenu();
	mode = modeInput();
	if (mode == -1) {
		system("cls");
		puts("[ERROR] Wrong input");
		fflush(stdout);
	} else if (mode == 6) {
		customDisplayMenu();
	} else {
		switch (mode) {
		case 1:
			generateBlink();
			break;
		case 2:
			generateOneTwo();
			break;
		case 3:
			generateOneThree();
			break;
		case 4:
			system("cls");
			printf("Type the port number : ");
			fflush(stdout);
			scanf("%s", usrIn);
			sscanf(usrIn, "%d", &port);
			system("cls");
			generateOne(port);
			break;
		case 5:
			generateCaterpillar();
			break;
		}
	}
}
