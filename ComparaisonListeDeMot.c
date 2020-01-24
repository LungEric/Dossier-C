#include<stdio.h>


void main()
{	
	FILE *fic=fopen("verif.txt","r");
	FILE *text=fopen("text.txt","r");
	FILE *found=fopen("foundword.txt","w");
	int i,j ; 
	int test ; 
	char list1[100][100];
	char l2[100][100];
	/**/
	
	printf("LISTE 1\n\n"); 
	do{
		fscanf(fic,"%s",list1[i]);
		printf("%s\n",list1[i]); 
		i++ ; 
		
	}while(!feof(fic));
	
	
	/*
	printf("LISTE 2\n\n"); 	
	do{
		fscanf(text,"%s",l2[i]);
		printf("%s\n",l2[i]);
		i++;
	}while(!feof(text));
	*/
	fclose(fic);
	fclose(text);
}
