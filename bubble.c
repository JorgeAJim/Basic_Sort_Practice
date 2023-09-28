//bubble.c
//famous bubble sort
//implement the swap algorithm with pointers

#include <stdio.h>
#define MAX 9

//function prototypes
void printValues();
void sort();
void swap(int*, int*);

int values[] = {7, 3, 9, 4, 6, 1, 2, 8, 5};

int main(){

	printf("Before:  \n");
	printValues();
	sort();
	printf("After: \n");
	printValues();

	return(0);
} //end main


void printValues() {

	//print the values[] list
	//by iterating through the list
	int i = 0;
	for(i = 0; i < MAX; i++){

		printf("%d ", values[i]);	

	};
	
	printf("\n");

};


void sort(){

	//sort will be printing the values[] list as the values are being swap
	//into the correct order

	// use the basic bubble sort algorithm
	// to swap the array's individual values
	//
	// defien all needed variables for the nested for loops	
	int i = 0;
	int j = 0;
	//the first for loop, is used to loop the second for loop enough time
	for(i = 0; i < MAX - 1; i++){
		for(j = 0; j < MAX - 1; j++){
			// determine if the current index's value is bigger then the 
			// following index's value
			if(values[j] > values[j + 1]) {

				
				//if the preceding index is smaller than the leading index
				//then use the swap function to move them inside the array

				//the prototype for swap() is expecting address parameters to be given,
				//printf("%x and %x \n", &values[j], &values[j + 1]);
				//printf("%d and %d \n", values[j], values[j + 1]);
				swap(&values[j], &values[j+1]);	
				//printf("%d and %d \n", values[j], values[j + 1]);
				//printf("%x and %x \n", &values[j], &values[j + 1]);
				printValues();
			};

		};

	};


};



void swap(int* num1, int* num2){ 

	//What occurs in this function won't update the rest of the program!
	//What occurs is a passed value, and not a pass by pointer
	//rather than trying to switch the value of num1 to num2, swap should 
	//be swapping the values of *num1(the index value) with *num2
	//because if the addresses are swapped, it's a close instance, while if swap the 
	//addresses values it occurs throughout the program
	

	//create a variable that will temperarely hold an address
	//the temp variable is holding an address, does that mean it needs the star symbol?
	int temp = *num1;

	// swap the addresses
	*num1 = *num2;
	*num2 = temp;

};


