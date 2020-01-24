/*-------------------------------------------------------------------------
IPAM - Annee Academique 2017-2018
Bachelier en Informatique
Cours de Principes Algorithmiques et Programmation
Examen de Juin 2018
---------------------------------------------------------------------------
Remarque: ce fichier est intentionnellement sans caracteres accentues.
---------------------------------------------------------------------------

Contexte
========
Il vous est demande de lire un fichier texte de type CSV (comma separated Values)
de structure fixe, d'en stocker sont contenu dans une structure dediee (cf. infra)
et ensuite d'en ecrire le contenu dans autre fichier apres traitement (cf.infra).

Details
=======
Un fichier CSV est un fichier texte contenant dans chaque ligne un ensemble 
d'informations separees par des virgules.
Dans notre cas le ou les  fichiers CSV a traiter sont supposes avoir TOUJOURS 
la structure  illustree ci dessous:

Jean,Dupond,1.80,80
Jacques,Durand,1.65,76

C'est a dire qu'ils contiendront toujours deux chaines de caracteres suivies de deux nombres.
La signifcation de ces valeurs etant la suivante :

Prenom,Nom,Taille,Poids

Vous devez supposer que le fichier ne contient pas d'erreurs et suit toujours ce format.
Un fichier d'exemple vous est fourni ( "mycsv.csv").

Chaque ligne du fichier doit etre subdivisee suivant les virgules et les differentes
valeurs doivent etre stockees en memoire OBLIGATOIREMENT via le type structure 
definit comme suit :

typedef struct{
char nom[80];
char prenom[80];
float taille;
float poids;
float bmi;
}record;

Cela signifie que les deux dernieres valeurs de la ligne doivent etre converties
en float (cf. infra).
La variable bmi (body mass index) de la structure est a calculer a parti du poids 
et de la taille de la facon suivante :
 	
	 BMI = POIDS/(TAILLE*TAILLE)
 
Le resultat sera ecrit dans un autre fichier CSV (nomme "completedcsv.csv")
suivant le format ci-apres 

Prenom,Nom, Poids, Taille, BMI

Ainsi les lignes  23 et 24 donneront comme 
resultat  (le nomre de decimale peut varier):

Jean,Dupond,80.0000,1.8000,24.6914
Jacques,Durand,76.0000,1.6500,27.9155


Pour vous aider vous trouverez ci-dessous quelques fonctions utiles
pour ce qui vous demande:
	- strtok : pour le decoupage des lignes suivant les virgules,
	- atof : pour la conversion des chaines contenant les poids et taille en nombre,
	- strcpy : pour la copie d'une chaine dans un autre,
	- strcat : pour la concatenation de chaines de caracteres 
	- snprintf : pour la conversion de nombres en chaines de caracteres.

Les conversions se feront obligatoirement via les fonction et procedure
suivantes :
	- record line2rec(char *ligne) : de ligne vers structure, 
  	- void rec2string (record myrec, char *mystring) : de structure vers ligne.


strtok (<string.h>)
==================
Description
-----------
La fonction C <char *strtok(char *str, const char *delim)> decoupe une chaine decoupe une 
chaine <str> en morceaux (tokens) sur base du delimiteur <delim>.
STRTOK = STRing TOKen 

Declaration
-----------
char *strtok(char *str, const char *delim) 

Parametres
----------
str - Le contenu de cette chaine sera modifie et decoupe en chines plus petites (tokens).
delim - C'est la chaine contenant le delimiteur.

Valeur Retournee
----------------
Cette fonction reourne un pointeur vers le premier token trouve dans la chaine. 
La valeur null est retournee si il n'y plus de token trouve.

Exemple
-------
#include <string.h>
#include <stdio.h>

int main () {
   char str[80] = "This is - www.tutorialspoint.com - website";
   const char s[2] = "-";
   char *token;
   
   // get the first token 
   token = strtok(str, s);
   
   //walk through other tokens
   while( token != NULL ) {
      printf( " %s\n", token );
    
      token = strtok(NULL, s); // Oui NULL
   }
   
   return(0);
}

L'execution de ce programe donne l'affichage suivant :

This is 
  www.tutorialspoint.com 
  website


atof() <stdlib.h>
=================
Description
-----------
La fonction C <double atof(const char *str)> convertit une chaine <str> en un nombre flottant (de type double).
ATOF = Alphabet TO Float.

Declaration
-----------
double atof(const char *str)

Parametres
----------
str - C'est la chaine contenant la representation du nombre a virgule flottante.

Valeur Retournee
----------------

Cette fonction retourne la valeur du nomre represente dans la chaine sous forme de double.
Si la chaine n'est pas une representation valable d'un nombre la valeur retournee est zero (0.0).

Exemple
-------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {
   float val;
   char str[20];
   
   strcpy(str, "98993489");
   val = atof(str);
   printf("String value = %s, Float value = %f\n", str, val);

   strcpy(str, "tutorialspoint.com");
   val = atof(str);
   printf("String value = %s, Float value = %f\n", str, val);

   return(0);
}

L'execution de ce programe donne l'affichage suivant :

String value = 98993489, Float value = 98993488.000000
String value = tutorialspoint.com, Float value = 0.000000

strcpy <string.h>
=================
Description
-----------
La fonction C <char *strcpy(char *dest, const char *src)> copie la chaine <srcW vers la chaine <dest>.
STRCPY = STRing CoPY

Declaration
-----------
char *strcpy(char *dest, const char *src)

Parametres
----------
dest - Chaine destination ou le contenu sera copie..

src - La chaine a copier.

Valeur Retournee
----------------

Exemple
-------
#include <stdio.h>
#include <string.h>

int main () {
   char src[40];
   char dest[100];
  
   strcpy(src, "This is tutorialspoint.com");
   strcpy(dest, src);

   printf("Final copied string : %s\n", dest);
   
   return(0);
}

L'execution de ce programe donne l'affichage suivant :

Final copied string : This is tutorialspoint.com

strcat <string.h>
=================
Description
-----------
La fonction C <*strcat(char *dest, const char *src)>  ajoute la chaine <src> a la fin de la chaine <dest>.

STRCAT = STRing ConCATenation

Declaration
-----------
char *strcat(char *dest, const char *src)

Parametres
----------
dest - Chaine de destination contenant une chaine de caractere, et suffisament grande pour contenir le resultat de la concatenation.

src - La chaine a ajouter.

Valeur Retournee
----------------


Exemple
-------
#include <stdio.h>
#include <string.h>

int main () {
   char src[50], dest[50];

   strcpy(src,  "This is source");
   strcpy(dest, "This is destination");

   strcat(dest, src);

   printf("Final destination string : |%s|", dest);
   
   return(0);
}

L'execution de ce programe donne l'affichage suivant :

Final destination string : |This is destinationThis is source|


snprintf <stdlib.h>
===================
Description
-----------
La fonction C <int snprintf ( char * dest, size_t n, const char * format, ... )>  ecrit le contenu d'une variable 
(designee ici par  <...>) sous forme de chaine de caractere dans la chaine <dest> suivant le format <format>.
Son comportement s'apparente ) printf mis a part que le resultat ne s'affiche pas dans la console mais est 
place dans la chaine <dest>.

Declaration
-----------
int snprintf ( char * dest, size_t n, const char * format, ... )

Parametres
----------
dest - Chaine de destination ou sera 
n - Taille neccessaire pour dest. La chaine generee aura une longueur n-1, pour laisser de la place pour le caractre nul de terminaison.
format - Une chaine constante de formatage utilisant le formatage utilise par printf.
... - Les arguments additionnelles. Typiquement les varaibles convertir en chaine et a placer dans dest.

Valeur Retournee 
----------------

Exemple
-------
#include <stdlib.h>

int main ()
{
  char str[16];
  float f = 123.456789;
  
  snprintf(str, sizeof(str), "%.2f", f);
  // Equivalent: snprintf(str, 16, "%.2f", f);
  
  printf(" Converted string : %s\n", str);
  
}

L'execution de ce programe donne l'affichage suivant :

Converted string : 123.46
-------------------------------------------------------------------------------
CONSIGNES OBLIGATOIRES DE FORMATAGE
-------------------------------------------------------------------------------
Vous ecrirez votre programme C dans ce fichier que vous renommerez en vous 
conformant au schema suivant:
NOM_Prenom_PAP_Evaluation_Mois_Annee.c

De plus vous indiquerez vos nom et prenom dans l'espace reserve ci-dessous.

Bon travail. 
-------------------------------------------------------------------------------
PS: Ne modifiez aucunement les commentaires ci-dessus dans ce fichier, merci.
-------------------------------------------------------------------------------
 
 Nom:
 
 Prenom:
-------------------------------------------------------------------------------
Ecrivez votre programme C ci-dessous:
*/
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
typedef struct{
char nom[80];
char prenom[80];
float taille;
float poids;
float bmi;
}record;


