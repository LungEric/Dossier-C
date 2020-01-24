#include<stdio.h>
#define MAX 255
#include<string.h>
#include<stdlib.h>


/*----------------------------------------------*/

int main()
{
	FILE *fic=fopen("mot.txt","r");
	FILE *fic2=fopen("listemot.txt","w");
	
	char m[MAX][MAX];
	char f;
	int i; 
	
	if(fic == NULL || fic2 == NULL){
		printf("Le fichier n'existe pas !");
	}
 	
 	do {
 		
 		fscanf(fic,"%c",m);

	 }while(!feof(fic));
	
	do {
		
		printf("%c \n",m:=);
		
	 }while(!feof(fic));

	fclose(fic);
	fclose(fic2);
	
	return 0 ;	
	
}

