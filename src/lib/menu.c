#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "menu.h"

typedef struct data data;

typedef struct bpm bpm;

void menuMain() {
	system("cls");
	puts("=========================================================");
	puts("|| This program lets you manipulate data collected     ||");
	puts("|| by the first module and display it according to     ||");
	puts("|| your preferences as well as search in it.           ||");
	puts("||-----------------------------------------------------||");
	puts("|| Please type in the digit corresponding to what you  ||");
	puts("|| want the program to do                              ||");
	puts("||-----------------------------------------------------||");
	puts("|| 1:Display data in recorded order                    ||");
	puts("|| 2:Display data by time or heart rate in increasing  ||");
	puts("||   or decreasing order                               ||");
	puts("|| 3:Search and display for a particular time          ||");
	puts("|| 4:Display average heart rate for a given time range ||");
	puts("|| 5:Display the number of lines stored in memory      ||");
	puts("|| 6:Search and display max and min heart rate with    ||");
	puts("||   associated time                                   ||");
	puts("|| 7:Close the program                                 ||");
	puts("=========================================================");
	fflush(stdout);
}

void displayData(bpm *rate, int order, int size) {
	system("cls");
	puts("==================");
	puts("|| time | pulse ||");
	puts("||--------------||");
	if (order == 1) {
		for (int i = 0; i < size; i++) {
			printf("|| %d\t| %f\t||\n", rate[i].ms, rate[i].bpm);
		}
	} else {
		for (int i = 0; i < size; i++) {
			printf("|| %d\t| %f\t||\n", rate[size - i].ms, rate[size - i].bpm);
		}
	}
	puts("==================");
	puts("press a key to continue");
	fflush(stdout);
	getch();
}

void menuSortMode() {
	system("cls");
	puts("======================================================");
	puts("|| Choose the value you want the program to sort by ||");
	puts("||--------------------------------------------------||");
	puts("|| 1:time                                           ||");
	puts("|| 2:heartrate                                      ||");
	puts("======================================================");
	fflush(stdout);
}

void menuDisplayOrder() {
	system("cls");
	puts("=========================================================");
	puts("|| Choose the order you want the program to display by ||");
	puts("||-----------------------------------------------------||");
	puts("|| 1:increasing order                                  ||");
	puts("|| 2:decreasing order                                  ||");
	puts("=========================================================");
	fflush(stdout);
}

void displayExtremums(bpm *extremums) {
	system("cls");
	puts("===================================");
	puts("|| min           || max          ||");
	puts("||---------------||--------------||");
	printf("|| %d ms\t|| %d ms\t||\n", extremums[0].ms, extremums[1].ms);
	printf("|| %f bpm\t|| %f bpm\t||\n", extremums[0].bpm, extremums[1].bpm);
	puts("===================================");
	puts("press a key to continue");
	fflush(stdout);
	getch();
}

void displayAverage(float avrg) {
	system("cls");
	puts("======================================");
	puts("|| The average heart rate for these ||");
	printf("|| time boundaries is %f     ||\n", avrg);
	puts("======================================");
	puts("press a key to continue");
	fflush(stdout);
	getch();
}

void displayLines(int lines) {
	system("cls");
	puts("==========================================");
	printf("|| There are %3d lines stored in memory ||\n", lines);
	puts("==========================================");
	puts("press a key to continue");
	fflush(stdout);
	getch();
}
