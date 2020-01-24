/*
	comprendre comme lire les grands fichiers.
*/

#include<stdio.h>
#include<string.h>

void main (){
	
	FILE *pi=fopen("pi1000000.txt","r");
	char listdepicomp[5];  
	int i;
	int compteur,test ; 

	do{ 	
		fgets(listdepicomp,6,pi);
		//fscanf(pi,"%s",listdepicomp);
		printf("%s\n",listdepicomp);
		
	}while(!feof(pi));
	
/*	while((test =fgetc(pi))!=EOF){
		printf("%c",test);
	}
*/
	fclose(pi);
	
}

