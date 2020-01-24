#include<stdio.h>
#include<string.h>

void search(char *c,char *) ; 

int main(){
	
	FILE* fic = fopen("mot.txt","r");
	FILE* fic2 = fopen("listemot.txt","w");
	
	char c[10][100];
	char l[100];
	int i=0 ;
	int nb = 7;
	int size [10]; 
	int taille = 0 ; 

	do{
		fscanf(fic,"%s",c[i]);
	    size[i] = strlen(c[i]) ; 
		printf(" %s and size %d \n",c[i], size[i]);
		fprintf(fic2,"%s and size : %d\n",c[i], size[i]) ;
		taille += i ; 
		printf(" taille liste :  %d \n",i);
		i++ ; 
	}while( (i<6) && !feof(fic)); // pas oublié de mettre la condition pour le compteur .
	
	
	char s[100];


/*	
	printf("Search word in list : \n");
	scanf("%s",s);
	search(c,s);
	
*/	
	return 0 ; 
}

void search(char *c,char *s){
	int i ; 
	for (i=0;i<7;i++){
		if(strcmp((char *)c[i],s)==0){
			printf("The word is found ") ;
			break; 
		}
		else{
			printf("Not found\n");
		}
	}	
}
