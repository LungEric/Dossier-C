#include<stdio.h>

int main(){
	
	FILE* fic = fopen("mot.txt","r");
	FILE* fic2 = fopen("listemot.txt","w");
	
	char c[255];
	char l[100];
	int i=0 ;
	
	do{
	
		l[i]= fscanf(fic,"%s",c);
		i++;
			
	}while(!feof(fic));
	
	do{ 
		printf("[%d] => %s",i,l[i]);
		i++;
	}while(!feof(fic));
}
