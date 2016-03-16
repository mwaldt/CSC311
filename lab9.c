/*Max Waldt
Lab 9: Strings
CSC 311
4/23/15
*/
#include <stdio.h>
#include <stdlib.h>

char concat[200];
char reverse[200];

int my_strlen(char s[]){
	 int i = 0;
	 for (i = 0; s[i] != '\0'; ++i);
	 return i;
}

int my_strcpy(char s[], char t[]){
	 int slen = my_strlen(s);
	 int tlen = my_strlen(t);
	 if (slen >= tlen){
		  int i;
		  for (i = 0; t[i] <= tlen; i++){
				s[i] = t[i];
		  }
		  return 1;
	 }
	 else{ return -1; }
}

void my_strcat(char *catS, char *catT){
	 int i = 0;
	 while (*catS != '\0')
	 {
		  concat[i] = *catS;
		  i++;
		  catS++;
	 }

	 while (*catT != '\0')
	 {
		  concat[i] = *catT;
		  i++;
		  catT++;
	 }
	 concat[i] = '\0';
}

void my_strreverse(char *revS){
	 int n = 0;
	 int x = 0;
	 int i;
	 int num = 0;
	 char temp[100];

	 for (i = 0; x<100; x++)
	 {
		  reverse[x] = '\0';
		  temp[x] = ' ';
	 }

	 while (*revS != '\0')
	 {
		  temp[i] = *revS;
		  revS++;
		  i++;
	 }

	 while (num <= i)
	 {
		  reverse[n] = temp[i];
		  n++;
		  i--;
	 }
}


int main(void){
	 char string1[100];
	 char string2[100];
	 char string3[100];
	 char* strptr;
	 char* revS = string3;
	 int length = 0;

	 printf("Lab 9 - Strings");

	 printf("\nEnter a string:\n");
	 scanf("%s", string1);

	 // 1. length test
	 length = my_strlen(string1);
	 printf("\nLength of the word: %d", length);

	 // 2. copy test
	 printf("\n\nCopy the string");
	 int a = my_strcpy(string2, string1);
	 if (a == 1){ printf("\nCopy successful"); }
	 else { printf("\nCopy failed"); }

	 // 3. concatination
	 printf("\n\nConcatination");
	 printf("\nEnter a string:\n");
	 scanf("%s", string3);
	 printf("\nConcatination of %s and %s", string1, string3);
	 my_strcat(string1, string3);
	 printf("\n%s", concat);



	 // 4. reverse
	 printf("\n\nReverse of string: %s", string3);
	 my_strreverse(revS);
	 printf("\nReversed: %s", reverse);

	 printf("\n");
	 return 0;
}
