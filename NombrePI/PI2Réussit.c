#include<stdio.h>
#include<string.h>

void main (){
	int max (int x,int y) ; 
	FILE *thing=fopen("Things2find.txt","r");
	int test ; 
	int stringsize=0;//taille des chaines
	int size=0 ; // taille de liste
	char listdepi[100]; 
	printf("=======================================\n"); 
	printf("PART 1 : Search Size of list and string size \n");
	printf("=======================================\n");
	do{
		test = fscanf(thing,"%s",listdepi);
		if(test >0){
			size ++ ;
			stringsize = strlen(listdepi); 
			printf("%s = lenght : %d \n",listdepi,strlen(listdepi));
		}
	}while(!feof(thing));
	printf("size : %d\n stringsize: %d\n",size,stringsize); 
	fclose(thing);
	/*------------------------------------------------------------------------------------*/
	printf("=======================================\n"); 
	printf("PART 2 : WHERE A PUT THING TO SEARCH\n");
	printf("=======================================\n");  
	FILE *thing2=fopen("Things2find.txt","r");
	char t2[size][stringsize+1]; // taille de liste des choses a chercher
	int i ; 
	/*
		Faire copier dans un tableau mais pas de fclose sinon on faire le stream , juste ouvrir et le mettre dans le tableau.
	*/
	for(i=0;i<size;i++)	fscanf(thing2,"%s",t2[i]);
	for(i=0;i<size;i++)	printf("[%d] is %s\n",i,t2[i]);
	
	/*------------------------------------------------------------------------------------*/
	printf("=======================================\n"); 
	printf("PART 3 : WHERE A PUT THING The pi file\n");
	printf("=======================================\n");  
	
	FILE *pi=fopen("pi1000000.txt","r");
		FILE *wpi=fopen("solution.txt","w");

	char listdepicomp[size];  
	int j;
	int compteur=0; 

	do{ 
		for(i=0;i<size;i++){	
			if(strcmp(t2[i],listdepicomp)==0){
				printf("%s est en position : %d\n",t2[i],compteur);
				fprintf(wpi,"%s is at %d\n",t2[i],compteur);
			}
		}
		fgets(listdepicomp,6,pi); // faire size +1 donc 6 car sinon lit seulement 4 chiffre (ex:1245).
		// printf("%s is at %d position.\n",listdepicomp,compteur); //Verification que sa marche baby.
		compteur ++ ;
	}while(!feof(pi));

	fclose(pi);
	fclose(wpi);
}

