/*Max Waldt
ASSGN 3: Carry Operations
CSC 311
4/9/15
*/
#include <stdio.h>

int main(){
	 
	 //Data members
	 int input1;
	 int input2;
	 int result;
	 int carryCount = 0;
	 int carryOver = 0;
	 int index = 0;
	 int input1MinusMod;
	 int input1Moded;
	 int input2MinusMod;
	 int input2Moded;

	 //Prompts + reading
	 printf("Input 2 integers, one at a time for operation int1 + int2. Will count number of carry operations\n");
	 printf("Input first int: ");
	 scanf("%d", &input1);
	 printf("\nInput second int: ");
	 scanf("%d", &input2);
	 
	 //Get Results of add
	 result = input1 + input2;
	 printf("\nResult of operation: %d", result);
	 printf("\n------------\n");

	 do{

		  if (input1 > 0) { input1Moded = input1 % 10; }
		  else{ input1Moded = 0; }

		  if (input2 > 0) { input2Moded = input2 % 10; }
		  else{ input2Moded = 0; }

		  if ((input1Moded + input2Moded + carryOver) > 9){
				carryCount++;
				carryOver = 1;
		  }
		  else{ carryOver = 0; }


		  if (input1 > 0) { input1 = (input1 - input1Moded) / 10; }
		  else{ input1 = 0; }

		  if (input2 > 0) { input2 = (input2 - input2Moded) / 10; }
		  else{ input2 = 0; }

		  result = (result - (result % 10)) / 10;

	 } while (result > 0);

	 printf("\nThe nubmer of carry operations is %d", carryCount);
	 printf("\n\n\n");
}
