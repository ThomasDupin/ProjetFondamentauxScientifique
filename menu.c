/*
 * menu.c
 *
 *  Created on: 13 nov. 2018
 *      Author: 1836805
 */
#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
int console(){
	int mode;
	printf("Welcome \n");
	printf("1 - All the led are on \n");
	printf("2 - One led on x is on \n");
	printf("3 - One led by one \n");
	printf("4 - Snake mode \n");
	printf("Type the number of the mode to choose it : ");
	fflush(stdout);
	scanf("%d", &mode);
	printf("\n");
	return mode;
}

