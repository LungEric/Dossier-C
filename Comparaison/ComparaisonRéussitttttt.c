#include<stdio.h>
#include<string.h>


void main(){
	
	FILE *fic=fopen("mot.txt","r");
	FILE *comp=fopen("liste.txt","r");
	char list[255];
	char cp[255];
	int i , j , compteur ;
	int test=0 ; // Tester la taille et savoir si le fichier existe.
	int sizecomp=0 , sizefic=0 , stringsize=0; // Vérifier la taille des fichiers.
	// Taille du fichier comp
	

	do{
		test = fscanf(comp,"%s",cp);
		if(test>0){
			sizecomp ++ ;
		}
	}while(!feof(comp));
	printf("size of comp: %d\n",sizecomp);
	
		// Taille du fichier fic
	do{
		test = fscanf(fic,"%s",list);
		if(test>0){
			sizefic ++ ;
			stringsize=max(stringsize,strlen(list));
		}
	}while(!feof(fic));
	printf("size of fic : %d\n",sizefic);
	printf("stringsize : %d\n",stringsize);
	/* 	
			INFORMATION:
		size of comp : 17
		size of fic : 609
		stringsize : 11
	*/
	fclose(comp);
	fclose(fic);

	// Partie ou je vais comparer .
	FILE *output=fopen("reponse.txt","w"); 
	FILE *outcsv=fopen("reponse.csv","w");
	FILE *fic2=fopen("mot.txt","r");				// Reouvrir le fichier mais pas avec meme nom de variable sinon on redefinit.
	FILE *comp2=fopen("liste.txt","r");
	
	char lv[sizefic][stringsize+1]; // initialisation du fichier liste.
	char lc[sizecomp][stringsize+1]; // initialisation du fichier liste de comparaison.
	
	char lecteur[50];
	int count = 0;
	
	//int Str_compare(char *liste,char *liseverifier);
	//int cmpw(char *pw, char *ref);
	
	// Check if working. + inistialisation de la liste des mots a comparer.
	/*for(i=0;i<=sizefic;i++) fscanf(fic2,"%s",lv[i]);*/
	for(i=0;i<=sizecomp;i++) fscanf(comp2,"%s",lc[i]);
	
	/*	
	for(i=0;i<sizecomp;i++) printf("compar file : %s\n",lc[i]);
	for(i=0;i<sizefic;i++) printf("file == %s\n",lv[i]);	
	*/
	
	printf("================================================\n");	
	printf("We gonna compare:\n");	
	printf("================================================\n");	
	/*
	Explication WTF : faire un boucle ou on fscanf la liste de base et une boucle for pour la liste dans lequel il faut rechercher et boucler en meme temps 
	le compteur c'est la place de la variable dans la liste. Tandis que le i => c'est la place dans la liste à chercher. !!!
	*/
	do{
		for(i=0;i<sizecomp;i++){
				if(strcmp(lc[i],lecteur)==0){
				fprintf(output,"word %s found %d at : %d\n",lc[i],i,compteur);
				fprintf(outcsv,"word:%s;found:%d;position:%d\n",lc[i],i,compteur);
				printf("word %s found %d at : %d\n",lc[i],i,compteur);
			}
		}
		fscanf(fic2,"%s",lecteur);
		printf("compare : %s\n",lecteur);
		compteur ++ ; 
	}while(!feof(fic2));
	
	//for(i=0 ; i<sizefic;i++)  
	
	fclose(comp2);
	fclose(fic2);
	fclose(output);
	
}
/*
int Str_compare(char *liste,char *liseverifier)
{
	int flag = 0; 
	int i= 0;
	for( i=0; liste[i]!='\0' && liseverifier[i]!='\0'; i++)
	{
		if(liste[i]!=liseverifier[i])
		flag=1;
		return flag;
	}
	return flag;
}
*/
int max(int x, int y)
{
	int returnval=y;
	
	if(x>y) returnval=x;
	return returnval;
}


