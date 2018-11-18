/*
 * donnees.c
 *
 *  Created on: 14 nov. 2018
 *      Author: 1836805
 */
#include <stdio.h>
#include <stdlib.h>
#include "donnees.h"
#include "menu.h"
#include "actions.h"

Datas openFile(){
	FILE* file = NULL;
	file = fopen("C:\\Users\\1836805\\Desktop\\Projet Coeur\\programmation\\lectureTraitementDonnee\\Battements.csv", "r");
	Datas data = NULL;
	if(file != NULL){
		data = stockFile(file);
	}else{
		printf("Error can't read csv file \n");
		fflush(stdout);
	}
	fclose(file);
	return data;
}
Datas stockFile(FILE* file){
	int numberLine = 0;
	numberOfLine(&numberLine);
	char tab[15];
	Datas data = malloc(sizeof(Data)*numberLine);
	if(data == NULL){
		printf("ERROR !");
		fflush(stdout);
		exit(0);
	}
	for(int i = 0; i < numberLine; i++){
		fgets(tab, 15, file);
		fflush(stdout);
		automate(tab, data, i);
	}
	return data;
}
void numberOfLine(int *numberLine){
    FILE* file = NULL;
    int carac = 0;
    int compteur = 0;
    file = fopen("C:\\Users\\1836805\\Desktop\\Projet Coeur\\programmation\\lectureTraitementDonnee\\Battements.csv", "r");
    if (file !=NULL){
        do{
            carac = fgetc(file);
                if (carac == '$'){
                    compteur++;
                }
        }while(carac != EOF);
    }
    *numberLine = compteur;
    fclose(file);
}
void automate(char tab[10], Datas data, int u){
	char tabPulse[10];
	char tabTime[10];
	int i = 0, j = 0;
	while(tab[i] != ';'){
		tabPulse[i] = tab[i];
		i++;
	}
	i++;
	while(tab[i] != ('\n') && tab[i] != NULL){
		tabTime[j] = tab[i];
		i++;
		j++;
	}
	data[u].pulse = atoi(tabPulse);
	data[u].time = atoi(tabTime);
}
