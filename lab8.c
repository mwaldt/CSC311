/*Max Waldt
Lab 8
CSC 311
4/16/15
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	 char outprompt;
	 int *ip;
	 double *dp;

	 //Part 1
	 printf("Part 1\n\n");
	 int i1;
	 int i2;
	 double d1;
	 double d2;

	 printf("\nAddress of i1 = %p", &i1);
	 printf("\nAddress of i2 = %p", &i2);
	 printf("\nAddress of d1 = %p", &d1);
	 printf("\nAddress of d2 = %p", &d2);

	 //Part 2
	 printf("\n\nPart 2\n\n");
	 int *intptr1;
	 int *intptr2;
	 double *dubptr1;
	 double *dubptr2;

	 printf("\nAddress of i1 = %p", intptr1);
	 printf("\nAddress of i2 = %p", intptr2);
	 printf("\nAddress of d1 = %p", dubptr1);
	 printf("\nAddress of d2 = %p", dubptr2);

	 //Part 3
	 printf("\n\nPart 3\n\n");
	 intptr1 = &i1;
	 intptr2 = &i2;
	 dubptr1 = &d1;
	 dubptr2 = &d2;

	 printf("\nAddress of i1 = %d", intptr1);
	 printf("\nAddress of i2 = %d", intptr2);
	 printf("\nAddress of d1 = %d", dubptr1);
	 printf("\nAddress of d2 = %d", dubptr2);

	 //Part 4
	 printf("\n\nPart 4\n\n");
	 intptr1 = intptr2;
	 printf("\nValue of intptr1 = %d", intptr1);
	 dubptr1 = (double*)intptr1;
	 printf("\nValue of dubptr1 = %p", dubptr1);
	 printf("\nValue of intptr1 = %p");

	 //Part 5
	 printf("\n\nPart 5\n\n");
	 intptr1 = NULL;
	 printf("\n%d\n", intptr1);

	 //Part 6
	 printf("\n\nPart 6\n\n");
	 *intptr2 = 5;
	 printf("\nDereference inptr1: %d");
	 printf("\nSegmentation fault for intptr1");
	 //*intptr1 = 5;
	 //printf("\n%p\n", intptr1);

	 //Part 7
	 printf("\n\nPart 7\n\n");
	 *intptr2 = 100;
	 printf("\nValue of i1 = %d", i1);
	 printf("\nValue of i2 = %d", i2);

	 //Part 8
	 printf("\n\nPart 8\n\n");
	 printf("\nintptr2 + 1 = %d\n", (intptr2 + 1));
	 printf("\ndubptr2 + 1 = %d\n", (dubptr2 + 1));
	 printf("\nintptr2 + 1 = %d\n", *(intptr2 + 1));
	 printf("\ndubptr2 + 1 = %d\n", *(dubptr2 + 1));
	 printf("\nintptr2 - 1 = %d\n", (intptr2 - 1));
	 printf("\ndubptr2 - 1 = %d\n", (dubptr2 - 1));
	 printf("\nintptr2 - 1 = %d\n", *(intptr2 - 1));
	 printf("\ndubptr2 - 1 = %d\n", *(dubptr2 - 1));

	 //Part 9
	 printf("\n\nPart 9\n\n");
	 printf("\nSet intptr1 = &i1, check if intptr1 = intptr2");
	 intptr1 = &i1;
	 if (intptr1 == intptr2)
		  printf("\nintptr1 == intptr2\n");
	 else printf("\nintptr1 != intptr2\n");

	 printf("\nSet intptr1 = &i1, check if *intptr1 = *intptr2\n");
	 if (*intptr1 == *intptr2)
		  printf("\n* intptr1 == * intptr2\n");
	 else printf("\n* intptr1 != * intptr2\n");


	 printf("\nSet intptr1 = &i2, check if intptr1 = intptr2");
	 intptr1 = &i2;
	 if (intptr1 == intptr2)
		  printf("\nintptr1 == intptr2\n");
	 else printf("\nintptr1 != intptr2\n");

	 printf("\nSet intptr1 = &i1, check if *intptr1 = *intptr2\n");
	 if (*intptr1 == *intptr2)
		  printf("\n* intptr1 == * intptr2\n");
	 else printf("\n* intptr1 != * intptr2\n");


	 //Part 10
	 printf("\n\nPart 10\n\n");
	 printf("\nMalloc assign a pointer to pi or 3.1416");

	 double *ptr = (double*)malloc(sizeof(double));
	 double pi = 3.1416;
	 ptr = &pi;

	 printf("\nptr = %6.4f", ptr);
	 printf("\n*ptr = %6.4f", *ptr);

	 //Part 11
	 printf("\n\nPart 11\n\n");
	 printf("Deallocate ptr");
	 ptr = (double*)malloc(sizeof(double));
	 free((void*)ptr);
	 ptr = (double*)malloc(sizeof(double));
	 printf("\n*ptr = %6.4f", *ptr);
	 printf("\n\n");
	 return 0;
}
