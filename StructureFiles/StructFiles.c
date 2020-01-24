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
	
	/*copier les fichiers dans un fichier txt*/
	do{
		while(fgets(list,sizeof(list),fic) != NULL){
				fprintf(fic2,"%s\n",list);
		}
	}	
	while(!feof(fic));

	fclose(fic);
	fclose(fic2);
	
	/*2 lire txt */
	
	FILE *ficl=fopen("nom.txt","r");
	char *token ; 
	//char s[50]; 
	// Separate the ";" .
	do{
		fscanf(ficl,"%s",list);
		printf("%d DATA IS: %s\n",i+1,list);
		
		// For copy name : WORKED , YESSS BABY
		token = strtok(list,";"); 
		strcpy(l.name,token);
		printf("Name : %s\n",l.name);
		
		// For copy AGE :  WOOOOORKED , BABY 
		token = strtok(NULL,"\n");
		sscanf(token, "%d", &l.age);
		printf("Age : %d\n",l.age);
		
		//printf("token ==  %s\n",token);
		/*	
		while(token != NULL){
			//	printf("%s\n",token); // print all values out to check if its worked
			//fprintf(ficage,"%s",s);
      		token = strtok(NULL, s);
		}
		*/
		printf("\n",token);
		i++;
		printf("=========================\n");
	}	
	while(!feof(fic));
	
	fclose(ficl);
}

/*---------------------------------------*/

