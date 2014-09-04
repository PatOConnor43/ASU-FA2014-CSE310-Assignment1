// File: readarray.c
// Description: A list of integers is loaded as input and the integers are
//				into an array in the order that they are read.
// Author Information:
// Patrick O'Connor
// paoconno@asu.edu

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 80


int main(int argc, char* argv[]){

	//Variables
	int* array;							//Array for the integers
	char c;								//Current character on the line
	char* line;							//Current line that is read from input file
	char* charp;						//Pointer to c
	int i, j;							//i is used as an index for array, j is used in testing
	FILE* fp;							//Pointer to the input file

	//Allocates array and line on the heap
	array = (int*)malloc(MAX_SIZE*sizeof(int));
	line = (char*)malloc(MAX_SIZE*sizeof(char));

	//Initialize neccesary variables
	i = 0;
	j = 0;
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

	//Add a null terminator at the end of line just in case garbage gets put into line
	line[strlen(line) -1] = '\0';
	//printf("%s", line);						//Testing the value of line

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
		//printf("This is temp: %s\n", temp);	//Testing each value of temp
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
