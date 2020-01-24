/*-------------------------------------------------------------------------
IPAM - Annee Academique 2015-2016
Bachelier en Informatique
Cours de Principes Algorithmiques et Programmation
Examen de Juin 2016
---------------------------------------------------------------------------
Remarque: ce fichier est intentionnellement sans caracteres accentues.
---------------------------------------------------------------------------

Enonce:
=======

                 "Tout est dans Pi!"
                 
Pi etant un nombre decimal illimite non periodique, ont peut supposer que toute
suite de chiffres peut se retrouver dans ses décimales.

Plus modestement, on vous demande d'ecrire un programme qui permettra de 
rechercher la presence d'une liste de suites de chiffres contenue dans un 
fichier texte dans le million des premières decimales de Pi, aussi
contenues dans un fichier texte.

Le fichier "pi1000000.txt" contient un million de decimales de Pi (les premieres
bien entendu). Votre programme ne pourra lire ce fichier qu'une seule fois lors 
de son execution. L'idee est que votre programme devrait pouvoir aussi etre utilise
avec des fichiers contenant un plus grand nombre de decimales de Pi (1 milliard,
1000 milliards,...).

Le fichier "Things2find.txt"  contient la liste des suites de nombres à 
chercher dans le fichier "pi1000000.txt", et:
	- chaque suite de chiffres est sur une et une seule ligne,
	- votre programme ne peut reposer sur des suppositions a propos
	  du nombre de lignes et/ou du nombre de caracteres par ligne,
	- vous pouvez, par contre, supposer que le nombre de caractères
	  par ligne est constant dans tout ce fichier,
	- vous minimiserez le nombre de lectures de ce fichier.

Les resultats de votre programme seront ecrits dans un fichier texte,
en indiquant pour chaque suite de chiffres trouvee, ladite suite,
et l'endroit ou commence cette suite dans le fichier "pi1000000.txt". 
A titre indicatif la suite "14159" se trouve a l'emplacement 3.
Voici, a nouveau a titre indicatif, les premieres  lignes de mon fichier
de reponse:
81066 find in place 3209
00042 find in place 4795
01123 find in place 7145
00000 find in place 17536
	
	
Votre copie d'examen sera constituee du code source de votre programme
et du fichier de sortie de votre programme.

Pour rappel:
 - la fonction getc() permet de lire un caractere dans un fichier texte,
 - essayez de modulariser votre code en utilisant fonctions et procedures.

---------------------------------------------------------------------------
Vous ecrirez  votre programme C dans ce fichier que vous renommerez comme 
suit:
NOM_Prenom_PAP_Examen_juin_2016.c

De plus vous indiquerez vos nom et prenom dans l'espace reserve ci-dessous.

Votre fichier de sortie sera nomme suivant le model suivant:
NOM_Prenom_Thingsfound.txt

Bon travail. 
-------------------------------------------------------------------------------
PS: Ne modifiez aucunement les commentaires de ce fichier, merci.
-------------------------------------------------------------------------------
 
 Nom:
 
 Prenom:
-------------------------------------------------------------------------------
Ecrivez votre programme C ci-dessous:
*/

#include<stdio.h>
#include<string.h>
main()
{
	char lecteur[50]; // Variable de lecture des fichiers
	int test;
	int inputsize=0; // Nombre de choses à trouver
	int stringsize=0; // Taille des choses à toruver
	int i, compteur;
	FILE *pifile, *inputf, *outputf; 
	
	int max(int x, int y); //Fonction maximum de deux nombres
	void shifstr(char *mystr); // Fonction de décalage
	
	// On ouvre le fichiers des choses à trouver
	inputf=fopen("Things2find.txt","r");
	
	// On lit ligne par ligne.
	// On compte le nombre lignes.
	// On "mesure" la taile des lignes.
	do
	{
		test=fscanf(inputf, "%s", lecteur);
		if(test>0) {
			inputsize++;
			stringsize= max(stringsize, strlen(lecteur));
		}
	}while(!feof(inputf));
	// On ferme et on ouvre de nouveau pour effectuer le recherche.
	fclose(inputf);
	inputf=fopen("Things2find.txt","r");
	
	// On déclare un tableau pour sotker les choses à trouver.
	// On connait maintenant le nombre de lignes et de colonnes nécessaires
	// pour ce tableau.
	char tofind[inputsize][stringsize+1]; // Tableau des choses à trouver
	char tocompare[stringsize]; // Variable de comparaison

	// On relit le fichier et on remplit le tableau avec ce que l'on lit.
	for(i=0; i<inputsize; i++) fscanf(inputf, "%s", tofind[i]);
	
	// On ouvre le fichier des décimales et le fichier de sortie.
	pifile=fopen("pi1000000.txt","r");
	outputf=fopen("Thingsfound.txt","w");
	
	// On remplit la variable de comparaison en lisant les premiers 
	// caractères du fichier des décimales.
	for(compteur=0;compteur<stringsize; compteur++) tocompare[compteur]=getc(pifile);
	
	/* A partir de ce point on répétera les deux étapes suivantes:
		1) On compare le contenu de la variable de comparaison
		   avec les lignes du tableau des choses à trouvers.
		   En cas de "match" (correspondance) on l'écrit dans
		   le fichier des choses trouvées.
		2) On décale vers la gauche les caractères de la variable
		   de comparaison d'une case, et on lit un nouveau caractère
		   dans le fichier des décimale que l'on place à la dernière
		   case de ladite variable.
		
	*/
	do
	{
		for(i=0; i<inputsize;i++)
			if(strcmp(tofind[i], tocompare)==0)
				fprintf(outputf,"%s find in place %i\n",tocompare, compteur-stringsize+1);
//				printf("%s find in place %i\n",tocompare, compteur-stringsize+1);
		shifstr(tocompare);
		fscanf(pifile, "%c",&tocompare[stringsize-1]);	
		compteur++;
	}while(!feof(pifile));
	
	fclose(pifile);
	fclose(inputf);
	fclose(outputf);
}

int max(int x, int y)
{
	int returnval=y;
	
	if(x>y) returnval=x;
	return returnval;
}

// Fonction qui décale d'une case tous les caractères d'un variable chaine
// vers la gauche.
void shifstr(char *mystr)
{
	int length,i;
	
	length=strlen(mystr);
	for(i=0; i<length-1; i++ ) mystr[i]=mystr[i+1];
}
