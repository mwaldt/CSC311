/*Max Waldt
Lab 10: Strings
CSC 311
5/7/15
*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(void){
	 char in;
	 int spccnt = 0;
	 int digcnt = 0;
	 int lwcnt = 0;
	 int upcnt = 0;
	 printf("Lab 10\n\n");
	 printf("\nEnter characters, digits, or white space characters, enter 'z' to end\n");
	 while ((in = getchar()) != 'z'){
		  //part1
		  //read in input until 'z' is entered
		  if (in == 'z') break;
		  //part2
		  //count whitespace
		  if (isspace(in) || in == '\n' || in == '\t'){ spccnt++; }
		  //count digits
		  if (isdigit(in)){ digcnt++; }
		  //count uppercase
		  if (isupper(in)){ upcnt++; }
		  //count lowercase
		  if (islower(in)){ lwcnt++; }

		  //Part3
		  //print out input, all upper changed to lower and lower changed to upper
		  if (isupper(in)){ in = tolower(in); }
		  else if (islower(in)){ in = toupper(in); }
		  putchar(in);

		  //if (getchar() == 'z'){ break; }
	 }
	 printf("\nNumber of the whitespace characters: %d\n", spccnt);
	 printf("\nNumber of the digits: %d\n", digcnt);
	 printf("\nNumber of the lowercase characters: %d\n", lwcnt);
	 printf("\nNumber of the uppercase characters: %d\n", upcnt);
	 printf("\n");
	 return 0;
}
