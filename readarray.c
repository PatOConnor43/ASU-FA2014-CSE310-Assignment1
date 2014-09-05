// File: readarray.c
// Description:
// A list of integers is loaded as input and the integers are
// into an array in the order that they are read.
// Author Information:
// Patrick O'Connor
// paoconno@asu.edu

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 80


int main(int argc, char* argv[]){

	//Variables
	int* array;				//Array for the integers
	char c;					//Current character on the line
	char* line;				//Current line that is read from input file
	char* charp;			//Pointer to c
	int i, j, count;		//index variables
	FILE* fp;				//Pointer to the input file

	//Allocates line on the heap
	line = (char*)malloc(sizeof(char));

	//Initialize neccesary variables
	i = 0;
	j = 0;
	count = 0;
	fp = fopen(argv[1], "r");
	c = fgetc(fp);
	charp = &c;
	strncpy(line, charp,1);

	//This while loop builds the contents of line, character by character
	while(c != EOF){
		c = fgetc(fp);
		charp = &c;
		strncat(line, charp, 1);
	}

	//Add a null terminator at the end of line just in case
	//garbage gets put into line
	line[strlen(line) -1] = '\0';
	//Testing the value of line
	//printf("%s\n", line);

	//Find how many integers are in the string
	charp = line;
	while(*charp != '\0'){
		if(*charp > 47 && *charp < 58){
			if(*(charp+1) < 48 || *(charp+1) > 57){
				count++;
			}
		}
		charp++;
	}

	//Allocate size of array
	array = malloc(count*sizeof(int));

	//Create a temporary char* that will hold each token from strtok function
	char* temp = strtok(line, " ");
	//Gets integer value from temp and puts it in the array
	array[i] = atoi(temp);
	i++;
	//Move temp to the next token
	temp = strtok(NULL, " ");

	//This while loop adds the remaining integer tokens to the array until
	//there are no more tokens
	while(temp != NULL){

		array[i] = atoi(temp);
		i++;
		//Testing each value of temp
		//printf("This is temp: %s\n", temp);
		temp = strtok(NULL, " ");
	}

	//Just testing that the array has correct values
	//for(j = 0; j < i; j++){
	//	printf("%d\n", array[j]);
	//}

	//free the heap variables
	free(array);
	free(line);
	fclose(fp);
	return 0;
}
