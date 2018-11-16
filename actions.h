/*
 * actions.h
 *
 *  Created on: 14 nov. 2018
 *      Author: 1836805
 */

#ifndef ACTIONS_H_
#define ACTIONS_H_
#include "donnees.h"

void choice(int userChoice, Datas data);
void printAllData(Datas data);
void printInAscendingOrder(Datas data);
void bubbleSort(Datas copyOfData, int type);
void printInDecreasingOrder(Datas data);
int search(Datas data, int time);
int numberOfLineOfTab(Datas data);
void searchRange(int time1, int time2, Datas data);
void searchMinMax(Datas data);
void creatNewTab(Datas data, Datas newTab);

#endif /* ACTIONS_H_ */
