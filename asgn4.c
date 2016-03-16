/*Max Waldt
Assignment 4: File IO
CSC 311
5/5/15
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int full[100];
int fn[100];
int ln[100];
int a1[100];
int a2[100];
int temp[100];

int li = -1; //letter increment
int ri = 0;//recipients increment
int ci;//counter increment
int i = 0;
int n = 0;
int x = 0;

FILE *op;
FILE *rp;
FILE *lp;

int Out[5000];
int Rec[5000];
int Let[5000];

int main(int argc, char *argv[]){
	 if (argc != 4){
		  printf("Program requires 3 arguments to run,");
		  return 1;
	 }
	 else{
		  op = fopen(argv[1], "w");
		  lp = fopen(argv[2], "r");
		  rp = fopen(argv[3], "r");

		  int r = 0;
		  while ((x = fgetc(lp)) != EOF){
				Let[i] = x;
				i++;
		  }
		  //printf("%s", Let);

		  i = 0;
		  while ((r = fgetc(rp)) != EOF){
				Rec[i] = r;
				i++;
		  }
		  //printf("%s", Rec);

		  fclose(lp);
		  fclose(rp);

		  progrun();
		  progrun();
		  progrun();

		  fclose(op);
	 }
	 printf("\nTerminating Program...\n\n");
	 return 0;
}

void progrun(){
	 reset();
	 fullname();
	 firstname();
	 lastname();
	 address();
	 //tempbuff();
	 innerloop();
}

void reset(){
	 for (i = 0; i < 100; i++){
		  fn[i] = 0;
		  ln[i] = 0;
		  full[i] = 0;
		  a1[i] = 0;
		  a2[i] = 0;
		  temp[i] = 0;
	 }
}

void fullname(){
	 for (ri = 0; ri < 100; ri++){
		  li++;
		  if (Rec[li] != 10){ full[ri] = Rec[li]; }
		  else{ ri = 100; }
	 }
}

void firstname(){
	 for (ri = 0; ri<100; ri++){
		  li++;
		  if (Rec[li] != 10){ fn[ri] = Rec[li]; }
		  else{ ri = 100; }
	 }
}

void lastname(){
	 for (ri = 0; ri<100; ri++){
		  li++;
		  if (Rec[li] != 10){ ln[ri] = Rec[li]; }
		  else{ ri = 100; }
	 }
}

void address(){
	 for (ri = 0; ri<100; ri++){
		  li++;
		  if (Rec[li] != 10) { a1[ri] = Rec[li]; }
		  else { ri = 100; }
	 }
	 for (ri = 0; ri<100; ri++) {
		  li++;
		  if (Rec[li] != 10) { a2[ri] = Rec[li]; }
		  else { ri = 100; }
	 }
	 li++;
}

void tempbuff(){
	 for (ri = 0; ri < 100; ri++){
		  li++;
		  if (Rec[li] != 10){ temp[ri] = Rec[li]; }
		  if (Rec[li] == 0) { ri = 200; }
		  else { ri = 200; }
	 }
}

void innerloop(){
	 for (n = 0; n<5000; n++){
		  if (Let[n] == 0){ n = 5005; }
		  else if (Let[n] == 35){
				chkaddr();
				chkfull();
				chkfrst();
				chklast();
				n = n + 2;		 //increment beyond text block
		  }
		  else{ fprintf(op, "%c", Let[n]); }
	 }
	 fprintf(op, "%c", 10);
	 fprintf(op, "%c", 10);
}

void chkaddr(){
	 if (Let[n + 1] == 65){
		  for (ci = 0; ci<100; ci++){
				if (a1[ci] != 0){ fprintf(op, "%c", a1[ci]); }
				else { ci = 200; }
		  }
		  fprintf(op, "%c", 10);
		  for (ci = 0; ci<100; ci++){
				if (a2[ci] != 0){ fprintf(op, "%c", a2[ci]); }
				else { ci = 200; }
		  }
	 }
}

void chkfull(){
	 if (Let[n + 1] == 78){
		  for (ci = 0; ci<100; ci++) {
				if (full[ci] != 0) { fprintf(op, "%c", full[ci]); }
				else { ci = 200; }
		  }
	 }
}

void chkfrst(){
	 if (Let[n + 1] == 70){
		  for (ci = 0; ci<100; ci++) {
				if (fn[ci] != 0) { fprintf(op, "%c", fn[ci]); }
				else { ci = 200; }
		  }
	 }
}

void chklast(){
	 if (Let[n + 1] == 76){ //first name
		  for (ci = 0; ci<100; ci++) {
				if (ln[ci] != 0) { fprintf(op, "%c", ln[ci]); }
				else { ci = 200; }
		  }
	 }
}