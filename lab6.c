/*Max Waldt
Lab 6: Intro to C
CSC 311
4/2/15
*/
#include <stdio.h>

int main(){
	 //part 1
	 int input1;
	 int input2;
	 int input3;
	 int result;
	 int fiveDigit;
	 int intAtIndex;
	 int intMag = 10000;
	 int index = 0;
	 char intPrints[6];


	 printf("Input 3 integers, one at a time for operation int1*int2 - int3\n");
	 printf("input first int: ");
	 scanf("%d", &input1);
	 printf("\ninput second int: ");
	 scanf("%d", &input2);
	 printf("\ninput third int: ");
	 scanf("%d", &input3);
	 result = input1 * input2 - input3;
	 printf("\nResult of operation: %d", result);

	 //part 2
	 printf("\n\n--------\nThis is a C Program");
	 printf("\n--------\nThis is\n a C Program");
	 printf("\n--------\nThis\nis\na\nC\nProgram");
	 printf("\n--------\nThis\tis\ta\tC\tProgram");

	 printf("\n--------\n*****\n****\n***\n**\n*");

	 //part 3
	 printf("\n\nInput a 5 digit integer: ");
	 scanf("%d", &fiveDigit);
	 printf("\n\n");
	 for(index = 0; index < 5; index ++){
		  intAtIndex = fiveDigit / intMag;
		  fiveDigit = fiveDigit - intMag*intAtIndex;
		  intMag = intMag /10; 
		  printf("%d", intAtIndex);
		  printf(" "); 
	}
	printf("\n");
}
