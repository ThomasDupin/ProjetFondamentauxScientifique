/*
 * actions.c
 *
 *  Created on: 14 nov. 2018
 *      Author: 1836805
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "actions.h"
#include "donnees.h"

void choice(int userChoice, Datas data){
	int time, time1, time2;
	int pulse;
	int line = 0;
	numberOfLine(&line);
	switch(userChoice){
		case 1:
			printAllData(data);
			break;
		case 2:
			printInAscendingOrder(data);
			break;
		case 3:
			printInDecreasingOrder(data);
			break;
		case 4:
			time = choice4();
			pulse = search(data, time);
			printf("Pulse for %d = %d", time, pulse);
			fflush(stdout);
			break;
		case 5:
			choice5(&time1, &time2);
			searchRange(time1, time2, data);
			break;
		case 6:
			printf("Number of line :%d \n", line);
			break;
		case 7:
			searchMinMax(data);
			break;
		case 8:
			printf("---- End -----");
			fflush(stdout);
			free(data);
			exit(0);
			break;
	}
}
void printAllData(Datas data){
	int line = 0;
	numberOfLine(&line);
	for(int i = 0; i < line; i++){
		printf("%d - %d \n", data[i].pulse, data[i].time);
		fflush(stdout);
	}
}
void printInAscendingOrder(Datas data){
	int line = 0;
	numberOfLine(&line);
	Datas copyOfData;
	creatNewTab(data, copyOfData);
	int type;
	printf("1 - Pulse  \n");
	printf("2 - Time \n");
	printf("What type of value you want to sort: ");
	fflush(stdout);
	scanf("%d", &type);
	bubbleSort(copyOfData, type);
	for(int i = 0; i < line; i++){
		printf("%d - %d \n", copyOfData[i].pulse, copyOfData[i].time);
	}

}
void printInDecreasingOrder(Datas data){
	int line = 0;
	numberOfLine(&line);
	Datas copyOfData;
	creatNewTab(data, copyOfData);
	int type;
	printf("1 - Pulse \n");
	printf("2 - Time \n");
	printf("What type of value you want to sort: ");
	fflush(stdout);
	scanf("%d", &type);
	bubbleSort(copyOfData, type+2);
	for(int i = 0; i < line; i++){
		printf("%d - %d \n", copyOfData[i].pulse, copyOfData[i].time);
	}
}
void bubbleSort(Datas copyOfData, int type){
	int tmpTime;
	int tmpPulse;
	int line = 0;
	int sort = 1;
	numberOfLine(&line);
	switch(type){
		case 1:
			while(sort){
				sort = 0;
				for(int i = 0; i < line; i++){
					if(copyOfData[i].pulse > copyOfData[i+1].pulse){
						tmpTime = copyOfData[i].time;
						tmpPulse = copyOfData[i].pulse;
						copyOfData[i].pulse = copyOfData[i+1].pulse;
						copyOfData[i].time = copyOfData[i+1].time;
						copyOfData[i+1].pulse = tmpPulse;
						copyOfData[i+1].time = tmpTime;
						sort = 1;
					}
				}
			}
		break;
		case 2:
			while(sort){
				sort = 0;
				for(int i = 0; i < line; i++){
					if(copyOfData[i].time  > copyOfData[i+1].time){
						tmpTime = copyOfData[i].time;
						tmpPulse = copyOfData[i].pulse;
						copyOfData[i].pulse = copyOfData[i+1].pulse;
						copyOfData[i].time = copyOfData[i+1].time;
						copyOfData[i+1].pulse = tmpPulse;
						copyOfData[i+1].time = tmpTime;
						sort = 1;
					}
				}
			}
			break;
		case 3:
			while(sort){
				sort = 0;
				for(int i = 0; i < line; i++){
					if(copyOfData[i].pulse < copyOfData[i+1].pulse){
						tmpTime = copyOfData[i].time;
						tmpPulse = copyOfData[i].pulse;
						copyOfData[i].pulse = copyOfData[i+1].pulse;
						copyOfData[i].time = copyOfData[i+1].time;
						copyOfData[i+1].pulse = tmpPulse;
						copyOfData[i+1].time = tmpTime;
						sort = 1;
					}
				}
			}
			break;
		case 4:
			while(sort){
				sort = 0;
				for(int i = 0; i < line; i++){
					if(copyOfData[i].time < copyOfData[i+1].time){
						tmpTime = copyOfData[i].time;
						tmpPulse = copyOfData[i].pulse;
						copyOfData[i].pulse = copyOfData[i+1].pulse;
						copyOfData[i].time = copyOfData[i+1].time;
						copyOfData[i+1].pulse = tmpPulse;
						copyOfData[i+1].time = tmpTime;
						sort = 1;
					}
				}
			}
			break;
	}
}
int search(Datas data, int time){
	int i = 0;
	while(data[i].time != time){
		i++;
	}
	return data[i].pulse;
}
void searchRange(int time1, int time2, Datas data){
	int averagePulse;
	int i1 = searchTime(time1, data);
	int i2 = searchTime(time2, data);
	for(int i = i1; i < i2; i++){
		averagePulse = averagePulse + data[i].pulse;
	}
	averagePulse = averagePulse/(i2-i1);
	printf("Average of pulse of %d to %d is : %d", time1, time2, averagePulse);
}
void searchMinMax(Datas data){
	int min = 0;
	int max = 0;
	int tmp;
	int associateTimeMax, associateTimeMin = 0;
	int line = 0;
	numberOfLine(&line);
	for(int i = 0; i < line; i++){
		tmp = data[i].pulse;
		if(tmp > max){
			max = tmp;
			associateTimeMax = data[i].time;
		}
		if(tmp < min){
			min = tmp;
			associateTimeMin = data[i].time;
		}
	}
	printf("The lowest pulse is %d - %d \nThe highest pulse is %d - %d", min, associateTimeMin, max, associateTimeMax);
}
void creatNewTab(Datas data, Datas copyOfData){
	int line = 0;
	numberOfLine(&line);
	int i;
	for (i = 0; i < line; i++){
		copyOfData[i].time = data[i].time;
		copyOfData[i].pulse = data[i].pulse;
	}
}
int searchTime(int time, Datas data){
	int i = 0;
	while(data[i].time != time){
		i++;
	}
	return i;
}
