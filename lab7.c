//Max Waldt
//Lab 7

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int biToDec(int binary){
	int output=0;
	int index=1; // position
	int remainder=0;
	while (binary != 0)
	{
		 remainder = binary % 10;
		output = output + remainder * index;
		index = index * 2;
		binary = binary / 10;
	}// end convert binary to decimal
	return output;
}

int main(){	
char cont[10];
int stopRun=0;
while (stopRun == 0){
	int inputInt=0;
	int transitionInt=0;
	char strOct[10];
	char input[10];
	char output[10];
	char hex[]="hexadecimal";
	char oct[]="Octal";
	char bi[] ="Binary";
	char dec[]="Decimal";

	printf("\n Base of Input Number: \nEnter b for %s, d for %s, h for %s or o for %s: \n",bi,dec,hex,oct);
	scanf("%s", &input);

	//binary input
	if(input[0]=='b' || input[0]== 'B')
	{
		printf("\n Please Input your %s in the format of 01011010\n", bi);
		scanf("%d", &inputInt);
		transitionInt = biToDec(inputInt);
		
		printf("\n Base of the output integer: d for %s, h for %s or o for %s: \n",dec,hex,oct);
		scanf("%s", &output);
		if(output[0]=='o' || output[0]=='O')
		{
			 printf("\n The Binary Number %d as an Octal Number is %o \n ", inputInt, transitionInt);
		}// Octal Output
		if (output[0]=='d' || output[0]=='D')
		{
			 printf("\n The Binary Number %d in Decimal is %d \n ", inputInt, transitionInt);
		}//Decimal Output
		if (output[0]=='h' ||output[0]=='H')
		{
			 printf("\n The Binary Number %d in hexadecimal is %x \n", inputInt, transitionInt);
		}//hexadecimal Output
	}// end of Binary input section

	//hex input
	if (input[0]=='h' || input[0]== 'H')// Start of hexadecimal
	{
		char binaryNumber[400];
		char hexaDecimal[100];
		char HexBU[100];
		int i=0;
		char answer[400]= " ";
		printf("\n Please Input your %s in the format of fedcba9\n", hex);
		scanf("%s", &hexaDecimal);
		strcpy(HexBU, hexaDecimal);
		while(hexaDecimal[i])
		{
			switch(hexaDecimal[i])
			{
				case '0': strcpy(binaryNumber,"0000");strcat(answer,binaryNumber); break;
				case '1': strcpy(binaryNumber,"0001");strcat(answer,binaryNumber); break;
				case '2': strcpy(binaryNumber,"0010");strcat(answer,binaryNumber); break;
				case '3': strcpy(binaryNumber,"0011");strcat(answer,binaryNumber); break;
				case '4': strcpy(binaryNumber,"0100");strcat(answer,binaryNumber); break;
				case '5': strcpy(binaryNumber,"0101");strcat(answer,binaryNumber); break;
				case '6': strcpy(binaryNumber,"0110");strcat(answer,binaryNumber); break;
				case '7': strcpy(binaryNumber,"0111");strcat(answer,binaryNumber); break;
				case '8': strcpy(binaryNumber,"1000");strcat(answer,binaryNumber); break;
				case '9': strcpy(binaryNumber,"1001");strcat(answer,binaryNumber); break;
				case 'A': strcpy(binaryNumber,"1010");strcat(answer,binaryNumber); break;
				case 'B': strcpy(binaryNumber,"1011");strcat(answer,binaryNumber); break;
				case 'C': strcpy(binaryNumber,"1100");strcat(answer,binaryNumber); break;
				case 'D': strcpy(binaryNumber,"1101");strcat(answer,binaryNumber); break;
				case 'E': strcpy(binaryNumber,"1110");strcat(answer,binaryNumber); break;
				case 'F': strcpy(binaryNumber,"1111");strcat(answer,binaryNumber); break;
				case 'a': strcpy(binaryNumber,"1010");strcat(answer,binaryNumber); break;
				case 'b': strcpy(binaryNumber,"1011");strcat(answer,binaryNumber); break;
				case 'c': strcpy(binaryNumber,"1100");strcat(answer,binaryNumber); break;
				case 'd': strcpy(binaryNumber,"1101");strcat(answer,binaryNumber); break;
				case 'e': strcpy(binaryNumber,"1110");strcat(answer,binaryNumber); break;
				case 'f': strcpy(binaryNumber,"1111");strcat(answer,binaryNumber); break;
				default:  printf("\nInvalid hexadecimal digit %c \n",hexaDecimal[i]); return 0;
			}
			i++;
		}
		int Hex_In_Binary;
		Hex_In_Binary = atoi(answer);//cast string as int	
		transitionInt = biToDec(Hex_In_Binary);
		// answer is a binary string that needs to be converted to decimal

		//hex output
		printf("\n Base of the output integer: d for %s, b for %s or o for %s: ",dec,bi,oct);
		scanf("%s", &output);
		if (output[0]=='o' || output[0]=='O')
		{
			 printf("\n The hexadecimal %s in Octal is %o \n", HexBU, transitionInt);
		}
		if (output[0]=='d' || output[0]=='D')
		{
			 printf("\n The hexadecimal %s in Decimal is %d \n", HexBU, transitionInt);
		}
		if (output[0]=='b' ||output[0]=='B')
		{
			printf("\n The hexadecimal %s in Binary is %s \n", HexBU, answer);
	}
	}

	//oct input
	if (input[0]=='o' || input[0] == 'O')// Octal input
	{
		char binaryNumber2[300];
		char octalNumber[100];
		char octBU[100];
		int i=0;
		char answer2[300]=" ";
		printf("\n Please Input your %s in the format of 067\n", oct);
		scanf("%s", &octalNumber);
		strcpy(octBU, octalNumber);
		while(octalNumber[i])
		{
			switch(octalNumber[i])
			{
				case '0': strcpy(binaryNumber2,"000");strcat(answer2,binaryNumber2); break;
				case '1': strcpy(binaryNumber2,"001");strcat(answer2,binaryNumber2); break;
				case '2': strcpy(binaryNumber2,"010");strcat(answer2,binaryNumber2); break;
 				case '3': strcpy(binaryNumber2,"011");strcat(answer2,binaryNumber2); break;
 				case '4': strcpy(binaryNumber2,"100");strcat(answer2,binaryNumber2); break;
				case '5': strcpy(binaryNumber2,"101");strcat(answer2,binaryNumber2); break;
				case '6': strcpy(binaryNumber2,"110");strcat(answer2,binaryNumber2); break;
				case '7': strcpy(binaryNumber2,"111");strcat(answer2,binaryNumber2); break;
				default:  printf("\nInvalid Octal digit %c \n",octalNumber[i]); return 0;
 			}
			i++;
		}
		int Oct_In_Binary;
		Oct_In_Binary = atoi(answer2);//cast string as Integer
		transitionInt = biToDec(Oct_In_Binary);
		printf("\n Base of the output integer: \n Enter d for %s, h for %s or b for %s: \n",dec,hex,bi);
		scanf("%s", &output);

		//oct output
		if (output[0]=='b' || output[0]=='B')
		{
			printf("\n Octal number %s in Binary is %d", octBU, answer2);
		}
		if (output[0]=='d' || output[0]=='D')
		{
			 printf("\n Octal number %s in Decimal is %d", octBU, transitionInt);
		}
		if (output[0]=='h' || output[0]=='H')
		{
			 printf("\n Octal number %s in Hexadecimal is %x", octBU, transitionInt);
		}
	}/*END OF OCTAL SECTION*/

	//decimal input
	if (input[0]=='d' || input[0] == 'D')
	{
		int decBU=0;
		printf("\nPlease Input your %s \n", dec);
		scanf("%d", &inputInt);
		decBU = inputInt;
		printf("\n Enter the Base of output: b for %s, h for %s or o for %s: \n",bi,hex,oct);
		scanf("%s", &output);

		//decimal output
		if (output[0]=='o' || output[0]=='O')
		{
			printf("\n The Decimal %d, in Octal is %o\n",decBU, decBU);
		}
		if (output[0]=='b' || output[0]=='B')
		{
			int remainder=0;
			int quotient=0;
			int binaryNumber[100];
			int i=1;
			int j;
			quotient = inputInt;
			while(quotient!=0)
			{
				binaryNumber[i]= quotient % 2;
				quotient = quotient / 2;
				i++;				
			}
			printf("\n The Decimal %d, in Binary is ", inputInt);
			for(j=i-1; j>0; j--)
			{	
				printf("%d",binaryNumber[j]);
			}
			printf("\n");
		}
		if (output[0]=='h' || output[0]=='H')
		{
			printf("\n The Decimal %d, in hexadecimal is %x\n",decBU,decBU);
		}
	}/*END OF DECIMAL SECTION*/

	printf("\tDo you wish to do another? (Y or N) ");
	scanf("%s", &cont);
	if(cont[0]=='y' || cont[0]=='Y')
	{
		printf("\n\n");
		stopRun = 0;
	}
	else
	{
		printf("\n Program terminated \n");
		stopRun = 1;
	}
}
return 0;
}
