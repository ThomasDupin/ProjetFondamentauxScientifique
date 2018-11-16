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
			break;
		case 5:
			time1 = 0;
			time2 = 0;
			choice5(&time1, &time2);
			searchRange(time1, time2, data);
			break;
		case 6:
			printf("Number of line :%d \n", numberOfLineOfTab(data));
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
	for(int i = 0; i < numberOfLineOfTab(data); i++){
		printf("%s - %s \n", data[i].pulse, data[i].time);
	}
}
void printInAscendingOrder(Datas data){
	int line = numberOfLineOfTab(data);
	Datas copyOfData = NULL;
	creatNewTab(data, copyOfData);
	int type;
	printf("1 - Pulse");
	printf("2 - Time");
	printf("What type of value you want to sort: ");
	fflush(stdout);
	scanf("%d", &type);
	bubbleSort(copyOfData, type);
	for(int i = 0; i < numberOfLineOfTab(copyOfData); i++){
		printf("%s - %s \n", copyOfData[i].pulse, copyOfData[i].time);
	}

}
void bubbleSort(Datas copyOfData, int type){
	int tmpTime;
	int tmpPulse;
	switch(type){
		case 1:
			for(int i = 0; i < numberOfLineOfTab(copyOfData); i++){
				if(copyOfData[i].pulse > copyOfData[i+1].pulse){
					tmpTime = copyOfData[i].time;
					tmpPulse = copyOfData[i].pulse;
					copyOfData[i].pulse = copyOfData[i+1].pulse;
					copyOfData[i].time = copyOfData[i+1].time;
					copyOfData[i+1].pulse = tmpPulse;
					copyOfData[i+1].time = tmpTime;
				}
			}
		break;
		case 2:
			for(int i = 0; i < numberOfLineOfTab(&copyOfData); i++){
				if(copyOfData[i].time  > copyOfData[i+1].pulse){
					tmpTime = copyOfData[i].time;
					tmpPulse = copyOfData[i].pulse;
					copyOfData[i].pulse = copyOfData[i+1].pulse;
					copyOfData[i].time = copyOfData[i+1].time;
					copyOfData[i+1].pulse = tmpPulse;
					copyOfData[i+1].time = tmpTime;
				}
			}
			break;
		case 3:
			for(int i = 0; i < numberOfLineOfTab(&copyOfData); i++){
				if(copyOfData[i].pulse < copyOfData[i+1].pulse){
					tmpTime = copyOfData[i].time;
					tmpPulse = copyOfData[i].pulse;
					copyOfData[i].pulse = copyOfData[i+1].pulse;
					copyOfData[i].time = copyOfData[i+1].time;
					copyOfData[i+1].pulse = tmpPulse;
					copyOfData[i+1].time = tmpTime;
				}
			}
			break;
		case 4:
			for(int i = 0; i < numberOfLineOfTab(&copyOfData); i++){
				if(copyOfData[i].time > copyOfData[i+1].time){
					tmpTime = copyOfData[i].time;
					tmpPulse = copyOfData[i].pulse;
					copyOfData[i].pulse = copyOfData[i+1].pulse;
					copyOfData[i].time = copyOfData[i+1].time;
					copyOfData[i+1].pulse = tmpPulse;
					copyOfData[i+1].time = tmpTime;
				}
			}
			break;
	}
}
void printInDecreasingOrder(Datas data){
	int line = numberOfLineOfTab(data);
	Datas copyOfData = NULL;
	creatNewTab(data, copyOfData);
	int type;
	printf("1 - Pulse");
	printf("2 - Time");
	printf("What type of value you want to sort: ");
	fflush(stdout);
	scanf("%d", &type);
	bubbleSort(copyOfData, type+2);
	for(int i = 0; i < numberOfLineOfTab(copyOfData); i++){
		printf("%s - %s \n", copyOfData[i].pulse, copyOfData[i].time);
	}
}
int search(Datas data, int time){
	int i = 0;
	while(data[i].time != time){
		i++;
	}
	return data[i].pulse;
}
int numberOfLineOfTab(Datas data){
	int i = 0;
	while(data[i].time != '\n'){
		i++;
	}
	return i;
}
void searchRange(int time1, int time2, Datas data){
	int averagePulse;
	for(int i = data[time1].time; i < data[time2].time; i++){
		averagePulse = averagePulse + data[i].pulse;
	}
	averagePulse = averagePulse/(time2-time1);
	printf("Average of pulse of %d to %d is : %d", time1, time2, averagePulse);
}
void searchMinMax(Datas data){
	int min = 0;
	int max = 0;
	int tmp;
	int associateTimeMax, associateTimeMin;
	for(int i = 0; i < numberOfLineOfTab(data); i++){
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
	printf("The lowest pulse is %d - %d \n The highest pulse is %d - %d", min, associateTimeMin, max, associateTimeMax);
}
void creatNewTab(Datas data, Datas newTab){
	int length = numberOfLineOfTab(data);
	int i;
	for (i = 0; i < length; ++i){
		newTab[i].time = data[i].time;
		newTab[i].pulse = data[i].pulse;
	}
}
