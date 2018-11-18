/*
 * menu.c
 *
 *  Created on: 14 nov. 2018
 *      Author: 1836805
 */
#include <stdio.h>
#include <stdlib.h>
#include "menu.h"

int menu(){
	int userChoice;
	printf("Welcome to HeXart Care Heart Project \n");
	printf("1 - Print all the data from .csv file \n");
	printf("2 - Print data in ascending order \n");
	printf("3 - Print data in decreasing order \n");
	printf("4 - Search and print data for a particular time \n");
	printf("5 - Print average of pulse for a particular time range \n");
	printf("6 - Print the number of data line in memory \n");
	printf("7 - Print the highest and lowest pulse with associate time \n");
	printf("8 - Quit the app \n");
	printf("Please enter your choice : ");
	fflush(stdout);
	scanf("%d", &userChoice);
	return userChoice;
}
int choice4(){
	int time;
	printf("Please enter the time to find the data : ");
	fflush(stdout);
	scanf("%d", &time);
	return time;
}
void choice5(int *time1, int *time2){
	int time_1;
	int time_2;
	printf("Please enter the time range : ");
	fflush(stdout);
	scanf("%d", &time_1);
	printf(" to ");
	fflush(stdout);
	scanf("%d", &time_2);
	*time1 = time_1;
	*time2 = time_2;
}

