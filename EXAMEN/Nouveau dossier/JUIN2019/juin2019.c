/*-------------------------------------------------------------------------
IPAM - Annee Academique 2018-2019
Bachelier en Informatique
Cours de Principes Algorithmiques et Programmation
Examen de Juin 2019
---------------------------------------------------------------------------
Remarque: ce fichier est intentionnellement sans caracteres accentues.
---------------------------------------------------------------------------
En bref:
--------
On vous demande d'ecrire un programme qui permet d'encoder un 
fichier en Base64, format utilise pour l'encodage MIME (
Multipurpose Internet Mail Extensions) servant a joindre en pur 
texte n'importe quel type de fichier a un mail. Cet encodage 
est aussi utilise dans certaines pages web.

En detail :
-----------

L'idee de base de l'encodage en Base64 est d'utiliser uniquement 64 
caracteres pour encoder n'importe quel type de fichier. Les caracteres
utilises sont: 
	- les 26 lettres majuscules de l'alphabet latin (ASCII)
	- les 26 lettres minuscules de l'alphabet latin (ASCII)
	- les 10 chiffres
	- et pour completer les caracteres '+' et '/'


Le tableau de caracteres :	

index | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10| 11| 12| 13| 14| 15|
-----------------------------------------------------------------------
char  |'A'|'B'|'C'|'D'|'E'|'F'|'G'|'H'|'I'|'J'|'K'|'L'|'M'|'N'|'O'|'P'|
=======================================================================
index | 16| 17| 18| 19| 20| 21| 22| 23| 24| 25| 26| 27| 28| 29| 30| 31|
-----------------------------------------------------------------------
char  |'Q'|'R'|'S'|'T'|'U'|'V'|'W'|'X'|'Y'|'Z'|'a'|'b'|'c'|'d'|'e'|'f'|
=======================================================================
index | 32| 33| 34| 35| 36| 37| 38| 39| 40| 41| 42| 43| 44| 45| 46| 47|
-----------------------------------------------------------------------
char  |'g'|'h'|'i'|'j'|'k'|'l'|'m'|'n'|'o'|'p'|'q'|'r'|'s'|'t'|'u'|'v'|
=======================================================================
index | 48| 49| 50| 51| 52| 53| 54| 55| 56| 57| 58| 59| 60| 61| 62| 63|
-----------------------------------------------------------------------
char  |'w'|'x'|'y'|'z'|'0'|'1'|'2'|'3'|'4'|'5'|'6'|'7'|'8'|'9'|'+'|'/'|

Les informations du fichier a convertir sont lues octets par octets sous
forme de char. Comme ces octets sont codes sur 8 bits (2^8=256 char differents)
mais que les 64 caracteres de la table ci-dessus peuvent etre codes sur 
6 bits (2^6=64 char differents) il faut lire des groupes de 3 caracteres,
qui groupes formeront un ensemble de 3x8=24 bits qui peuvent donc etre
subdivises en 4 caracteres codes sur 6 bits : 24bits=4x6.


Ainsi par exemple dans le fichier exemple joint "toconvert1.txt" on
trouve la phrase:

Man is distinguished, not only by his reason, but by this singular passion
from other animals, which is a lust of the mind, that by a perseverance of
delight in the continued and indefatigable generation of knowledge, exceeds
the short vehemence of any carnal pleasure.


Si on considere les 3 premiers caracteres de cette phrase: 'M', 'a' et 'n',
ceux-ci sont encodes en ASCII par les valeurs 77, 97, et 110 (cad qu'on les
trouvent respectivement aux emplacement 77, 97 et 110 de la table ASCII).

Ces trois valeurs d'encodage (sur 8 bits) 77, 97 et 110 valent en binaire
01001101, 01100001, et 01101110. Ces trois valeurs concatenees donne
donc la chaine binaire a 24 bits 010011010110000101101110.

Celle-ci redecoupee en portions de 6 bits donne donc les portions suivantes 
010011, 010110, 000101 et 101110, dont les valeurs d?cimales valent respectivement 
19, 22, 5 et 46.
Ces quatre valeurs correspondant dans la table de converion aux caracteres 
T,W,F et u.

En base 64 le mot "Man" est donc encode par "TWFu".

Le tableau ci-dessous donne une vue synoptique du processus:
-------------------------------------------------------------
Text (ASCII)|       M       |         a     |        n
-------------------------------------------------------------
Octets      |      77       |        97     |      110 
-------------------------------------------------------------
8-Bits      |0 1 0 0 1 1 0 1|0 1 1 0 0 0 0 1|0 1 1 0 1 1 1 0
-------------------------------------------------------------
6-Bits      |0 1 0 0 1 1|0 1 0 1 1 0|0 0 0 1 0 1|1 0 1 1 1 0
-------------------------------------------------------------
Base64      |    19 	|    22     |   5       |    46
-------------------------------------------------------------
Character   |     T 	|     W     |   F       |     u
-------------------------------------------------------------

Ainsi la phrase ci-dessus est encodee en base64 (cf fichier 
"Solconverted1.txt"):

TWFuIGlzIGRpc3Rpbmd1aXNoZWQsIG5vdCBvbmx5IGJ5IGhpcyByZWFzb24sIGJ1dCBieSB0aGlz
IHNpbmd1bGFyIHBhc3Npb24gZnJvbSBvdGhlciBhbmltYWxzLCB3aGljaCBpcyBhIGx1c3Qgb2Yg
dGhlIG1pbmQsIHRoYXQgYnkgYSBwZXJzZXZlcmFuY2Ugb2YgZGVsaWdodCBpbiB0aGUgY29udGlu
dWVkIGFuZCBpbmRlZmF0aWdhYmxlIGdlbmVyYXRpb24gb2Yga25vd2xlZGdlLCBleGNlZWRzIHRo
ZSBzaG9ydCB2ZWhlbWVuY2Ugb2YgYW55IGNhcm5hbCBwbGVhc3VyZS4=


Six fichiers vous sont fournis:
 - le fichier a convertir "toconvert0.txt" et sa solution "Solconverted0.txt",
 - le fichier a convertir "toconvert1.txt" et sa solution "Solconverted1.txt",
 - le fichier a convertir "toconvert2.txt" et sa solution "Solconverted2.txt",

Seul le premier fichier ne necessite pas de "padding" (cf. bonus).
 
Le programme qui vous est demande prendra en entree le nom du fichier a convertir,
le nom du fichier convertit et effectuera la conversion.

Bonus
-----
Bien que la chose soit importante dans une application reelle la conversion de 
la fin du fichier est un bonus dans cet examen.

Comme le nombre d'octets d'un fichier n'est pas necessairement un multiple de
3, une technique de remplissage (padding) est utilisee pour les derniers caracteres.

Par exemple si on n'a (plus) que 2 caracteres a ecrire, ceux-ci occupant 2x8=16 bits, 
on aura un probleme pour la conversion en blocs de 6 bits

Les valeurs manquantes sont remplacees par des valeurs nulles d'un point de vue 
numerique et le caractere de padding "=" (non present dans la table ci-dessus)
est utilise dans l'ecriture finale.


Ainsi si il manque un caractere pour avoir un multiple de 3 on aurait la 
situation suivante si les deux derniers caracteres sont 'M' et 'a':

-------------------------------------------------------------
Text (ASCII)|       M       |         a     |         
-------------------------------------------------------------
Octets      |      77       |        97     |       
-------------------------------------------------------------
8-Bits      |0 1 0 0 1 1 0 1|0 1 1 0 0 0 0 1|0 0 0 0 0 0 0 0
-------------------------------------------------------------
6-Bits      |0 1 0 0 1 1|0 1 0 1 1 0|0 0 0 1 0 0|0 0 0 0 0 0
-------------------------------------------------------------
Base64      |    19     |    22     |     4     |(Padding)  
-------------------------------------------------------------
Character   |     T 	|     W     |   E       |    =
-------------------------------------------------------------

Si par contre si il manque deux caracteres pour avoir un 
multiple de 3 on aurait la situation suivante
si le dernier caractere est 'M':

-------------------------------------------------------------
Text (ASCII)|       M       |               |         
-------------------------------------------------------------
Octets      |      77       |               |       
-------------------------------------------------------------
8-Bits      |0 1 0 0 1 1 0 1|0 0 0 0 0 0 0 0|0 0 0 0 0 0 0 0
-------------------------------------------------------------
6-Bits      |0 1 0 0 1 1|0 1 0 0 0 0|0 0 0 0 0 0|0 0 0 0 0 0
-------------------------------------------------------------
Base64      |    19     |    16     |  (Padding)|(Padding)  
-------------------------------------------------------------
Character   |     T     |    Q 	    |    =      |    =
-------------------------------------------------------------


--------------------------------------------------------------------------------
Vous ecrirez votre programme C dans ce fichier que vous renommerez comme suit :
NOM_Prenom_PAP_Examen_Juin_2019.c

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
	// Tableau de conversion (arrangee visuellement par lignes de 16 char
	char base64[64]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P',//16 char
					 'Q','R','S','T','U','V','W','X','Y','Z','a','b','c','d','e','f',//32 char
					 'g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v',//48 char
					 'w','x','y','z','0','1','2','3','4','5','6','7','8','9','+','/'};//64 char
	
	// Lecteur de fichier et lecteur de nom de fichier
	char lecteur, filename[50];//="toconvert1.txt";
	// Pointeurs de fichiers
	FILE *inputf, *outputf;
	// Entier long pour la conversion : 
	//  	3 char de 8 bits ? stocker = 24 bits => long=32 bits, il y a assez de place!
	long converter=0;
	// Compteur de boucles et compteur de lectures
	int i, countlect;
	// Diviseur pour la conversion
	int div;
	// Remarque : bien que la resolution ci-apres n'aie pas ete ecrite comme dans cette optique
	//			  le probleme pose revient a lire un nombre exprime en base 256 (oui!) 
	//			  et a l'ecrire en base 64.
	
	
	// hop hop hop on ouvre ces fichiers
	printf("Enrez le nom du fichier source : ");
	scanf("%s",filename);
	inputf=fopen(filename,"r");
	printf("Enrez le nom du fichier cible : ");
	scanf("%s",filename);
	outputf=fopen(filename,"w");
	
	// Tant qu'il reste quelque chose a lire	
	while(!feof(inputf))
	{
		converter=0; // Tout va passer a travers ce nombre
		div=64*64*64; // 3 char ascii = 24 bits = 4*8 bits, et 8 bits = 64 valeurs max
		countlect=0; // on va compter les lectures de caracteres (utile pour le padding)
		for (i=0;i<3;i++)// On lit trois char ascii
		{
			lecteur=getc(inputf); // on lit un char
			if(!feof(inputf)) //si la lecture est un vrai char...
			{
				// on utilise la valeur ascii du char lu et on pousse vers la 
				// gauche les valeurs deja lues de 256=2^8
				converter=converter*256+lecteur;
				countlect++;// Ok on a lu 1 char
			}				
			else
			{
				// On pousse simplement la ou les valeurs deja lues vers la gauche
				// ce qui revient a remplir de zeros les parties basses (a droite) du lecteur
				// ce qui est necessaire pour le padding).
				converter=converter*256; 
			}
		}
		// Le nombre char a ecrire et le nombre de paddings dependent directement
		// du nombre de lecture 
		if(countlect>0) // on verifie que l'on a bien fait des lecture (cas EOF)
		{
			// 3 lectures = 4 char a ecrire (cas de la majorite du fichier)
			// 2 lectures = 3 char a ecrire (cas de fin de fichier)
			// 1 lecture  = 2 char a ecrire (cas de fin de fichier)
			for(i=0;i<(4-(3-countlect));i++)
			{
					// converter/div donne la place du 1er char dans le tableau base64
				putc(base64[converter/div] ,outputf);//on l'ecrit
				converter = converter%div; // on elimine la valeur de ce char dans converter
				div=div/64; // on a un char de moins a gerer 
			}			
			// 3 lectures = 0 padding a ecrire (cas de la majorite du fichier)
			// 2 lectures = 1 padding a ecrire (cas de fin de fichier)
			// 1 lecture  = 2 padding a ecrire (cas de fin de fichier)
			for(i=0;i<(3-countlect);i++)
			{
				putc('=',outputf);
			}						
		}
	}	
	// on ferme proprement la boutique 
	fclose(inputf);
	fclose(outputf);	
}
