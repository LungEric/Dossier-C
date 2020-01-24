#include<stdio.h>
#include<string.h>

typedef struct person{
	
	int age;
	char n[255];
	
}person;

person add(person *p,int nb);
void display (person *p,int nb);
void printfiles (person *p,int nb);
person deleteperson(person *p,int nb);

int main(){
	
	person p[20];
	
	int i,nb ; 
	
	printf("Enter number :\n");
	scanf("%d",&nb);
	
	add(p,nb);
	display(p,nb);
	printfiles (p,nb);
	deleteperson(p,nb);
	
	return 0 ;

}

/*--------*/

person add(person *p,int nb){
	int i ;
	for(i=0;i<nb;i++){
		printf("Name [%d]:\n",i+1);
		scanf("%s",&p[i].n); 
		printf("Age [%d]:\n",i+1);
		scanf("%d",&p[i].age); 
	}
}

person deleteperson(person *p,int nb){
	int i ;
	char d[255];
	printf("Name to delete:\n");
	scanf("%s",d);
	
	for(i=0;i<nb;i++){
		if(strcmp(p[i].n,d)==0){
			printf("name found at [%d]\n",i+1);
			strcpy(p[i].n,"");
			p[i].age='\0';
		}
	}
	
	for(i=0;i<nb;i++){
		
		printf("Name [%d]: %s || Age [%d]: %d \n",i+1,p[i].n,i+1,p[i].age);
		
	}
}


void display (person *p,int nb){
	int i ;
	for(i=0;i<nb;i++){
		
		printf("Name [%d]: %s || Age [%d]: %d \n",i+1,p[i].n,i+1,p[i].age);
		
	}
}

void printfiles (person *p,int nb){
	int i ;
	FILE *fic=fopen("ListeDePersonne.txt","w");
	
	for(i=0;i<nb;i++){
		fprintf(fic,"\n==================\n");
		fprintf(fic,"|Nom [%d] : [%s] |\n",i+1,p[i].n);
		fprintf(fic,"|Age [%d] : [%d] |\n",i+1,p[i].age);
		fprintf(fic,"\n==================\n");
	}
	
	printf("Sucess for printing files.\n");
}
