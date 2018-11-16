/*
 * donnees.h
 *
 *  Created on: 14 nov. 2018
 *      Author: 1836805
 */

#ifndef DONNEES_H_
#define DONNEES_H_

typedef struct Data{
	int time;
	int pulse;
}Data;

typedef Data *Datas;

Datas openFile();
Datas stockFile(FILE* file);
void automate(char tab[10],Datas data, int u);
void numberOfLine(int *numberLine);

#endif /* DONNEES_H_ */
