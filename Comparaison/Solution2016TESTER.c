#include<stdio.h>
#include<string.h>
main()
{
	char lecteur[50];
	int test;
	int inputsize=0;
	int stringsize=0;
	int i, compteur;
	FILE *pwfile, *inputf, *outputf;
	
	int max(int x, int y);
	void shiftstr(char *mystr);
	int cmpw(char *pw, char *ref);
	//////
	inputf=fopen("liste.txt","r");
	//////
	do
	{
		test=fscanf(inputf, "%s", lecteur);
		if(test>0) {
			inputsize++;
			stringsize= max(stringsize, strlen(lecteur));
		}
	}while(!feof(inputf));
		
	fclose(inputf);
	
	////////////
	inputf=fopen("liste.txt","r");
	///////////
	char tochck[inputsize][stringsize+1];

	for(i=0; i<inputsize; i++) fscanf(inputf, "%s", tochck[i]);
	
	pwfile=fopen("mot.txt","r");
	outputf=fopen("reponse.txt","w");
	
	fscanf(pwfile, "%s", lecteur);	
	compteur=1;
	
	do
	{
		for(i=0; i<inputsize;i++)
			//if(strcmp(tochck[i], lecteur)==0) // version simple (full pw only)
			if(cmpw(tochck[i], lecteur)==1)// version +fine : on compare aux parties des pw du dico
				fprintf(outputf,"%s found in line %i in %s \n",tochck[i], compteur, lecteur);
//				printf("%s find in place %i\n",tocompare, compteur-stringsize+1);
		fscanf(pwfile, "%s", lecteur);	
		compteur++;
	}while(!feof(pwfile));

	fclose(pwfile);
	fclose(inputf);
	fclose(outputf);
}

int cmpw(char *pw, char *ref)
{
	int lpw, lref,i, retval=0;
	void shiftstr(char *mystr);
	lpw=strlen(pw);
	//printf("lpw(%s)=%d\n",pw,lpw);
	lref=strlen(ref);
	//printf("lref(%s)=%d\n",ref,lref);
	if(lpw<=lref){
		char tocompare[lpw+1];
		for (i=0; i<lpw;i++) tocompare[i]=ref[i];
		tocompare[lpw]='\0';
		for(i=lpw-1;i<=lref;i++){
			if(strcmp(tocompare,pw)==0) {
				retval=1;
				return retval;
			}
			else {
				shiftstr(tocompare);
				tocompare[lpw-1]=ref[i+1];
				tocompare[lpw]='\0';
			}
		}
	}
	return retval;
}

int max(int x, int y)
{
	int returnval=y;
	
	if(x>y) returnval=x;
	return returnval;
}

void shiftstr(char *mystr)
{
	int length,i;
	length=strlen(mystr);
	for(i=0; i<length-1; i++ ) mystr[i]=mystr[i+1];
}
