/*-------------------------------------------------------------------------
IPAM - Annee Academique 2016-2017
Bachelier en Informatique
Cours de Principes Algorithmiques et Programmation
Examen de Septembre 2017
---------------------------------------------------------------------------
Remarque: ce fichier est intentionnellement sans caracteres accentues.
---------------------------------------------------------------------------
En bref:
On vous demande d'ecire un programme qui compte la frequences des 
lettres dans un fichier donne.

En details:
On vous demande d'ecrire un programme en C qui :
 - lira le nom du fichier pour lequel il devra compter la frequence des 
   lettres (un fichier exemple vous sera fourni), frequence 
   exprimee comme un nombre compris entre 0 et 1.   
 - comptera les lettres qu'elles soient en minuscules ou en majuscules,
 - creera et utilisera une fonction "void updatecount(char letter)" 
   qui prendra en entree le caractere lu dans le fichier et mettra 
   a jour la frequence de la lettre en question,
 - ecrira les resultats dans un  autre fichier, nomme "counts.csv"
   dont la premiere ligne contiendra les differentes lettres separees par 
   des points-virgules, et la seconde ligne les frequences separees aussi par 
   des points-virgules.
 - par souci de simplification on ne tiendra compte que des caracteres 
   accentuesdu francais :?,?,?,?,?,?,?,?,?,?, compt?s respectivement pour
   a,a,e,e,e,i,i,o,o,u
- enfin on ne tiendra pas compte des autres caract?res (ponctuations et 
  chiffres).

La fonction  toupper peut evetuellement etre de bon interet dans 
ce cas puisqu'elle permet la conversion de n'importe quelle 
lettre (mais, attention, non accentuee) en majuscule:
Syntaxe :
int toupper(int c);
Librairei necessaire :
#include <ctype.h>

--------------------------------------------------------------------------------
Vous ecrirez votre programme C dans ce fichier que vous renommerez comme suit :
NOM_Prenom_PAP_Examen_Septembre_2017.c

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

// Une solution acceptable:

#include<stdio.h>
//#include<ctype.h>
long int count[26]; // Compteurs de lettres
// On cree un vecteur contenant toutes les lettres a chercher:
char letters[]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z',
				'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',
				'?','?','?','?','?','?','?','?','?','?','?','?'};	
// On cree un index de compteurs : ainsi dans le vecteur letters les caract?res 
// 'A', 'a', '?', '?' doivent partager le meme compteur, on va sotcker la place du 
// compteur de chaque caractere dans cette variable : 
int indexcounter[64];
int i; // compteur de boucles
int updatecount(char letter); // fonction d'upadate du compteur

main()
{
	char lecteur; // pour lire le fichier d'input
	//int test;
	int i, compteur=0; // compteur de lettres 
	FILE *inputf, *outputf; // Pour les fichiers
	
	// intitialisation des compteurs a zero 
	for(i=0;i<26; i++) count[i]=0;
	// initialisation des numeros de compteurs pour les lettres non accentuees
	// On utilise un modulo car La lettre majuscule qui se trouve en place i 
	//se trouve aussi en minuscule en place i+26:
	for(i=0;i<52 ;i++) indexcounter[i]=i % 26; 
	// initialisation des compteurs pour les lettres accentu?e (cas sp?ciaux)
	indexcounter[52]=indexcounter[53]= 0; // ? et ? => A
	indexcounter[54]=indexcounter[55]=indexcounter[56]=indexcounter[57]=4; // ?,?,? et ? => E
	indexcounter[58]=indexcounter[59]=8; //? et ? => I
	indexcounter[60]=indexcounter[61]= 14;//	? et ? => O
	indexcounter[62]=indexcounter[63]=20;   // ? et ? => U	

	//For tests
	//for (i=0; i<64; i++ ) printf("%c : %i\n", letters[i], indexcounter[i]);
	
	// On ouvre le fichier des choses ? trouver
	//inputf=fopen("test.txt","r");
	inputf=fopen("bigtext.txt","r");
	outputf=fopen("countresults.csv","w");
	for(i=0;i<26;i++)count[i]=0;
	
	// On boucle sur les caracteres du fichier d'input:	
	do
	{
		fscanf(inputf, "%c",&lecteur);// on lit un caractere

		// si on n'a pas atteint la fin du fichier (i.e. on a lu un vrai caractere)
		// on appelle la fonction d'update du compteur qui renvoie en plus 1 si on trouve 
		// une lettre et 0 sinon (dans le cas des chiffres et ponctuations).
		if(!feof(inputf)) compteur= compteur + updatecount(lecteur);
		
	}while(!feof(inputf));
	
	// On ecrit dans le fichier de resultat:
	// Les  caracteres
	for(i=0;i<26;i++) fprintf(outputf,"%c;", letters[i]);
	fprintf(outputf,"\n");
	// Les compteurs divises par le nombre de lettres lues dans le fichier
	for(i=0;i<26;i++) fprintf(outputf,"%f;", (float)count[i]/compteur);		
	// On ferme la boutique proprement:
	fclose(inputf);
	fclose(outputf);
}

// Fonction d'update des compteurs:
int updatecount(char car) // la variable 'car' contient un caractere, et peut etre une lettre
{
	int i=0; // Compteur de boucle
	int found=0; // Flag pour la recherche de lettres
	int retval=0; // valeur de retour : 1 si car est une lettre, 0 sinon
	
	// On boucle sur le tableau des lettres pour trouver la place
	// de car dans celui-ci
	do
	{
		found=(car==letters[i]); // si egalite => le booleen est mis a vrai, on a trouve une lettre
		if(!found)i++; // si pas trouve => on continue
	}while((i<64)&(!found)); // tant que pas trouve et qu'on n'a pas epuise le tableau

	if(found) //si on a trouve une lettre 
	{
		// i est la place dans le tableau des lettres
		// on se sert de i pour trouver dans indexcounter la place du compteur 
		// correspondant dans count:
		count[indexcounter[i]]=count[indexcounter[i]]+1;
		// On a trouve une lettre :
		retval=1;
	}
	return retval;
}



