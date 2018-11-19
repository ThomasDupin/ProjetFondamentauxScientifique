/*
 * generationCode.c
 *
 *  Created on: 13 nov. 2018
 *      Author: 1836805
 */
#include <stdio.h>
#include <stdlib.h>
#include "generationCode.h"


void setupFile(int mode){
	FILE* file = NULL;
	file = fopen("C:\\Users\\1836805\\Desktop\\Projet Coeur\\programmation\\Coeur 2.3\\src\\mainArduino\\param.h", "w+");
	if(file != NULL){
		writeParamH(mode, file);
	}else{
		printf("Error can't open file");
		fflush(stdout);
	}
	fclose(file);
	printf("OUAIS OUAIS OUAIS");
	fflush(stdout);
}

void writeParamH(int mode, FILE* file){
	int x = 0;
	fprintf(file, "#ifndef PARAM_H_ \n");
	fprintf(file, "#define PARAM_H_ \n");
	switch(mode){
		case 1:
			fprintf(file, "#define mode 1 \n");
			fprintf(file, "#define x %d \n", x);
			break;
		case 2:
			printf("Type the value of x: ");
			fflush(stdout);
			scanf("%d", &x);
			fprintf(file, "#define mode 2 \n");
			fprintf(file, "#define x %d \n", x);
			break;
		case 3:
			fprintf(file, "#define mode 3 \n");
			fprintf(file, "#define x,%d \n", x);
			break;
		case 4:
			fprintf(file, "#define mode 4 \n");
			fprintf(file, "#define x %d \n", x);
			break;
	}
	fprintf(file, "#endif /* PARAM_H_ */");
	//fclose(file);
}
