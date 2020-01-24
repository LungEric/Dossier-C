#include<stdio.h>
#define MAX 255
#include<string.h>
#include<stdlib.h>


/*----------------------------------------------*/

int main()
{
	FILE *fic=fopen("first.txt","r");
	FILE *fic2=fopen("third.txt","w");
	
	int i,j;
	char c;
	char f;
	int nbt=0;
	
	if(fic == NULL || fic2 == NULL){
		printf("Le fichier n'existe pas !");
	}
	
	printf("Letter to search : \n");
	scanf("%c",&f);
	
   while((c= fgetc(fic))!=EOF)
   {	
   		if (c == f){
   			nbt ++ ; 
		   }
		c = fputc(c,fic2);
   }
   printf("The letter : %c is %d times in the files\n",f,nbt); 
   printf("Files Merged.\n") ; 

	fclose(fic);
	fclose(fic2);
	
	return 0 ;	
	
}


