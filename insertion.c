//insertion.c
//Date: 1/20/2022
//
//Ask the user for an input that will be saved universaly
//Check user input
//Generate an array with random numbers
//Use an insertion sort algorithm to sort the array




#include <stdio.h>
// stdlib.h is the libary that hols rand() which generates a random number
#include <stdlib.h>
#include <time.h>

//function prototypes
void fillArray();
void printValues();
void sort();
void swap(int*, int*);

//the array's lenght will be determine by an user input of between 2 - 10
int size;

//create an array that will later be filled with random numbers
//the array has to allocated enough room for the expected random numbers
//size will hold the expected amount of numbers
int randArray[100];


int main(){

	printf("Please choose a number between 2 - 15: ");
	scanf("%d", &size);

	
 
	//for user input checking, there needs to be a while loop
	//however, it would be easier to forcefully pick a value for the user
	//for the second approach, there needs to be a away to alter the universal arrayLenght variable
	
	int* pSize = &size;

	if(*pSize < 2){
	
		printf("You choosed too low of a number. We will use the lowest number of 2 instead \n");
		//change the address of arrayLenght's value
		*pSize = 2;

	} 
	else if(*pSize > 10){

		printf("You choosed a number that is too high. We will use the highest number, 15, instead \n");
		*pSize = 15; 
		
	};


	

	printf("The lenght of your array is %d \n", size);

		
	fillArray();
	printf("Before: \n");
	printValues();
	sort();
	printf("After: \n");
	printValues();

	return(0);


};

//fill the array with random numbers
void fillArray(){

	//Note: might need "seed random"
	
	srand( time(NULL));
	

	int i = 0;
	for(i = 0; i < size; i++){
		
		randArray[i] = (rand() % 200) + 1;
	}



};


void printValues(){

	//print the arrays elements
	
	int i = 0;

	for(i = 0; i < size; i++){

		printf("%d ", randArray[i]);

	}

	printf("\n");


}

void sort(){

	//sort using an insertion sort algorithm
	
	int i = 0;
	int j = 0;
	//key holds the current element that is being compared to everything that came before
	int key;
	

	// i needs to start at the second element, because it's the first to be compared to the left sided elements
	for(i = i; i < size; i++){
		
		key = randArray[i];
		//so if i is the first element we look at, j will have to be the element that came before it
		//so j will always be minus 1 to i
		j = i - 1;
		
		//a while loop is required, because it the i element will need to compared to everything that came before it
		//until it can't find a value smaller than it. This won't take up the entire lenght of the array, it's unkown 
		//when the loop will find that smaller value.

		//so, this while loop will run if the j has already been compared to everything up to the 0th index AND it did find a smaller value
		while(j >= 0 && randArray[j] > key){

			swap(&randArray[j + 1], &randArray[j]);
			printValues();			

			//j has to change so that the while condition can eventually be false and the loop ends
			j = j - 1;

		}



	}	



}


void swap(int* num1, int* num2){

	//what is being swapped?
	//The answer is i
	//i is being given the value of j, because j is greater than what comes after which is i
	//meaning that i should be taking the place of j
	//i is num1 and j is num2
	
	int temp = *num1;	
	*num1 = *num2;
	*num2 = temp; 


}





