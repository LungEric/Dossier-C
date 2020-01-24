#include<stdio.h>
#include<string.h>
# define max 255

typedef struct {
	char name[max];
	char age ; 
}person;
	


/*---------------------------------------*/

void main(){

	FILE *fic=fopen("nom.csv","r");
	FILE *fic2=fopen("nom.txt","w");
	person l;
	char personne [max];
	char list[max];
	int i ;
	
	/*
	do{
		while(fgets(list,sizeof(list),fic) != NULL){
				fprintf(fic2,"%s\n",list);
		}
	}	
	while(!feof(fic));
	*/
	
	while(fgets(list,sizeof(list),fic) != NULL){
				fprintf(fic2,"%s\n",list);
		}
	fclose(fic);
	fclose(fic2);
	
	FILE *ficl=fopen("nom.txt","r");
	char *token ; 
	do{
		fscanf(ficl,"%s",list);
		printf("%d DATA IS: %s\n",i+1,list);
		token = strtok(list,";"); 
		strcpy(l.name,token);
		printf("Name : %s\n",l.name);
	//AGE faire attention car integer pas un string donc pas strcpy.
		token = strtok(NULL,"\n");
		sscanf(token, "%d", &l.age);
		printf("Age : %d\n",l.age);
		printf("\n",token);
		i++;
		printf("=========================\n");
	}	
	
	while(!feof(ficl));
	fclose(ficl);
}
