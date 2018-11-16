/*
 * main.c
 *
 *  Created on: 14 nov. 2018
 *      Author: 1836805
 */
#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "donnees.h"

int main(){
	Datas data = NULL;
	openFile(data);
	printf("OUI");
	fflush(stdout);
	int userChoice = menu();
	choice(userChoice, data);
	return 0;
}

