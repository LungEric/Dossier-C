#include<stdio.h>
#include<string.h>

void main()
{	
	int max(int x,int y);
	
	FILE *list=fopen("word.txt","r");
	FILE *search=fopen("wordsearch.txt","r");
	
	int i ;
	char l[1000][500]; // liste normal.
	char s[1000][500]; // Liste de search.
	int test, stringsize=0,listsize=0; 
	int searchsize=0; 

/*-------------------------------------------------------------------------------------------------*/	
	printf("List word:\n");
	do{
		
		test = fscanf(list,"%s",l[i]);
		if(test>0)
		{
			listsize++;
			stringsize=max(stringsize,strlen(l[i]));
			//printf("word[%d]:%s\n",i,l[i]);
		}
		i++;
	}while(!feof(list));
	printf("List info: \nListsize : %d\nStringsize : %d \n",listsize,stringsize);
	
	printf("SearchListword:\n");
	do{
		test = fscanf(search,"%s",s[i]);
		if(test>0)
		{
			searchsize++;
			//printf("word[%d]:%s\n",i,s[i]);
		}
		i++;
	}while(!feof(search));
	printf("SearchList info: \nListsize : %d\nStringsize : %d \n",searchsize,stringsize);
/*-------------------------------------------------------------------------------------------------*/
	fclose(list);
	fclose(search);
/*FERMER LE FICHEIER*/

	/*
		INFO :
	*/
	
	FILE *list2=fopen("word.txt","r");
	FILE *search2=fopen("wordsearch.txt","r");
	FILE *rep=fopen("reponse.txt","w");
	int count = 0 ; //coompte le nombre de mot trouvé , faut les 14.
	l[listsize][stringsize+1]; // liste normal.
	s[searchsize][stringsize+1]; // Liste de search.
	int j ;
	char mot[50];
	// Mettre tous les mots rechercher dans un tableau.0
	printf("SearchListword:\n");
	for(i=0;i<searchsize;i++) fscanf(search2,"%s",s[i]);
	
	do{
		for(i=0;i<searchsize;i++){
			if(strcmp(s[i],mot)==0){
				printf("word:%s at list[%d] found at %d\n",s[i],i,count);
				fprintf(rep,"word:%s at list[%d] found at %d\n",s[i],i,count);
			}
		}
		fscanf(list2,"%s",mot);
		printf("word:%s\n",mot);
		count++;	
	}while(!feof(list2));
	
	fclose(list2);
	fclose(search2);
	
}

int max(int x,int y){
	
	if(x>y) {
		return x;
	}
	return y ; 
}
