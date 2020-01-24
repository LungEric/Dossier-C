#include<stdio.h>
#include<string.h>

char letters[]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z',
				'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
int indexcount[52];		
	int count [26];
		
void main(){
	
	void updatecount(char *car);
	int max(int x, int y);
	
	FILE *text=fopen("bigtext.txt","r");
	int test ; 
	int size =0; // Taille fichier
	int sizet =0;// Taille fichier a chercher 
	char compteur[255];
	int stringsize=0;
	int i ;
	
	do{
		test = fscanf(text,"%s",compteur);
		if(test>0){
			size ++ ; 
		}
	}while(!feof(text));
	printf("SIZE of file : %d",size);
	fclose(text);
	
	/*---------------------------------*/
	/*
		Vector for checking letters 
	*/
	
	FILE *rtext=fopen("bigtext.txt","r");
	FILE *wtext=fopen("occurrence.txt","w");
	
	do{
		fscanf(text,"%c",&compteur);
		if(!feof(rtext)) compteur= compteur + updatecount(compteur); 
		
	}while(!feof(rtext));
	
	fclose(rtext);
	fclose(wtext);
}

/*------------------------------------------------------------------*/

int max(int x, int y)
{
	int returnval=y;
	if(x>y) returnval=x;
	return returnval;
}

void updatecount(char *car){
	int count;
	int val=0;
	int found=0; 
	int i=0; 
	
	do{
		found=(car==letters[i]);
		if(!found)i++ ; 
	}while((i<52) && (!found)); 
	
	if(found){
		//count[indexcount[i]]=count[indexcount[i]]+1 ; 
		val = 1 ;	
	}
	return val ; 
}

