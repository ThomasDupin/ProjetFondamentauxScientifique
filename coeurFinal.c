/*
 ============================================================================
 Name        : coeurFinal.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	int mode = console();
	setupFile(mode);
	return EXIT_SUCCESS;
}
