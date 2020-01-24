#include<stdio.h>
#include<string.h>

void main(){
	
	int max(int x, int y);
	
	FILE *pi=fopen("pi1000000.txt","r");
	int test ; 
	int size =0; // Taille fichier
	int sizet =0;// Taille fichier a chercher 
	char compteur[255];
	int stringsize=0;
	do{
		test = fscanf(pi,"%s",compteur) ;
		if(test>0){
			size ++ ;
		}
	}while(!feof(pi));
	printf("la taille est de : %d\n",size);
	fclose(pi);
	
	/*--------------------------------------------------*/
	
	// Check size of the file.
	
	FILE *look=fopen("Things2find.txt","r");
	do{
		test = fscanf(look,"%s",compteur) ;
		if(test>0){
			sizet ++ ;
		}
	}while(!feof(look));
	printf("la taille est de things2found : %d\n",sizet);
	fclose(look);
	
	/*--------------------------------------------------*/
	
	// check thing to search and list of thing to search
/*	
	FILE *look2=fopen("Things2find.txt","r");
	char list [sizet][50] ; 
	int i=0; 
	do{
		fscanf(look2,"%s",list[i]) ;
		printf("les choses a chercher sont : %s\n",list[i]);
		i++;
	}while(!feof(look2));
	
	while(i<sizet){
		printf("les choses a chercher sont : %s\n",list[i]);
		i++;
	}

	fclose(look2);
*/	
	/*--------------------------------------------------*/
	// search file
	/*
	FILE *look3=fopen("Things2find.txt","r");
	FILE *pi2=fopen("pi1000000.txt","r");
	FILE *found=fopen("found.txt","w");
	char pilist[size];
	
	do{	
		printf("%s",list[i]);
		i++;
	}while(!feof(pi2));
	
	fclose(look3);
	fclose(pi2);
	fclose(found);
	
	*/
}

int max(int x, int y)
{
	int returnval=y;
	
	if(x>y) returnval=x;
	return returnval;
}

