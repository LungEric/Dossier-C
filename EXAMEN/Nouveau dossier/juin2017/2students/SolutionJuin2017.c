/*-------------------------------------------------------------------------
IPAM - Annee Academique 2016-2017
Bachelier en Informatique
Cours de Principes Algorithmiques et Programmation
Examen de Juin 2017
---------------------------------------------------------------------------
Remarque: ce fichier est intentionnellement sans caracteres accentues.
---------------------------------------------------------------------------
En bref:
On vous demande d'?cire un programme qui permet de rechercher les 
mots palindromes dans un fichier texte.

En detail:
Un palindrome, du grec palin (? en arriere ?) et dromos (? course ?), 
aussi appele palindrome de lettres, est une figure de style designant 
un texte ou un mot dont l'ordre des lettres reste le meme qu'on 
le lise de gauche a droite ou de droite a gauche, comme "Bob", "ete" ou
"radar".
Un palindrome peut etre compose de plusieurs mots, comme dans 
"Esope reste ici et se repose" ou "Elu par cette crapule".
Un mot palindrome n'est evidemment compose que d'un seul mot. 
Nous ne nous occupons ici que des mots palindromes.

On vous demande d'ecrire un programme en C qui (en ordre croissant d'importance):
 - lira le nom du fichier ou rechercher les palindromes (un des fichiers 
   textes qui vous seront fournis), et recherchera les palindromes dans 
   les mots du fichier fourni en entree, et pour ce faire...
 - utilisera une fonction qui prendra en entree une chaine de caracteres
   et enverra en sortie un booleen qui permettra de savoir si le mot
   fourni est ou non un palindrome,
 - ecrira dans un  autre fichier, nomme "palindromes.txt"
   les palindromes qu'il aura trouv? dans le fichier fourni en entree,
 - affichera ? la fin les statistiques suivantes sur les mots trouves:
   nombre de mots, longeur mininum, longeur maximum, moyenne des
   longeurs de mots.

Trois fichiers vous sont fournis (nommes respectivement "dico_francais_1.txt",
"dico_francais_2.txt" et "dico_francais_3.txt") qui contiennent des listes de
mots de la langue francaise. Ces fichiers ne contiennent qu'un seul mot par ligne.
C'est donc parmi ces mots qu'il faut rechercher les palindromes.

--------------------------------------------------------------------------------
Vous ecrirez votre programme C dans ce fichier que vous renommerez comme suit :
NOM_Prenom_PAP_Examen_Juin_2017.c

De plus vous indiquerez vos nom et prenom dans l'espace reserve ci-dessous.

Bon travail. 
--------------------------------------------------------------------------------
PS: 
Ne modifiez aucunement les commentaires situes au dessus de la presente ligne,
merci.
--------------------------------------------------------------------------------
 
 Nom:
 
 Prenom:
--------------------------------------------------------------------------------
Ecrivez votre programme C ci-dessous:

*/
#include<stdio.h>
#include<string.h>
main()
{
	char lecteur[50], filename[50];
	int test;
	int inputsize=0;
	int stringsize=0;
	int i, compteur;
	int minp=32767, maxp=0, moyp=0, Np=0, longmot;
	FILE *inputf, *outputf;
	
	int palindrome (char *mystr);
	
	printf("Enrez le nom du fichier source : ");
	scanf("%s",filename);
	inputf=fopen(filename,"r");
	outputf=fopen("palindromes.txt","w");
	do
	{
		test=fscanf(inputf, "%s", lecteur); // On lit dans le fichier.
		if(test>0) {// Si la lecture s'est bien passee:
			if(palindrome(lecteur)){// Si le mot est un palindrome:
				fprintf(outputf,"%s\n", lecteur);//->on l'ecrit dans le fichier,
				Np++; // -> on incremente le compteur de palindromes,
				longmot= strlen(lecteur);//->on "mesure" la longueur du palindrome,
				minp=min(minp, longmot);//->on met a jour la longueur minimale des palindromes trouves,
				maxp=max(maxp, longmot);//->on met a jour la longueur maximale des palindromes trouves,
				moyp=moyp+ longmot;//->on ajoute la longueur trouvee pour le calcul de la longueur moyenne.
			}
		}
	}while(!feof(inputf)); // On s'arrete a la fin du fichier.
	
	// Affichage des stats:
	printf("Statistiques: \n");
	printf("Nombre de palindromes: %i\n", Np);
	printf("Longueur minimale des palindromes: %i\n", minp);
	printf("Longueur maximale des palindromes: %i\n", maxp);
	printf("Longueur moyenne des palindromes : %f\n", (float) moyp/Np); // calcul de la moyenne "a la volee". 
	
	fclose(inputf); // On ferme la boutique proprement.
	fclose(outputf);
}

int min (int x, int y) // Fonction du calcul du minimum de deux nombres.
{
	if(x<y) return x;
	else return y;
}

int max (int x, int y)// Fonction du calcul du minimum de deux nombres.
{
	if(x>y) return x;
	else return y;
}

int palindrome (char *mystr) // La chaine passee est-elle un palindrome (retour egale a 1) ou pas (retour egale a 0)
{ int retval = 0; // Par defaut on commence en supposant que mystr n'est pas un palindrome. On changera si necessaire.
  int L; // Longueur de la chaine
  int i=0; // Compteur
  
  L= strlen(mystr);
  // On boucle tant que le ieme caractere est egale au L-ieme caractere et tant qu'on a pas atteint le milieu de la chaine.
  while ((mystr[i]==mystr[L-1-i]) & (i<(L/2-1)))i++;
  // Si on a atteint le milieu de la chaine et que les deux caracteres contigus de ce milieu sont egaux => palindrome
  if(i==(L/2-1) & (mystr[i]==mystr[L-1-i])) retval=1;
  
  return retval;

}
