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
   accentuesdu francais :à,â,é,è,ê,î,ï,ô,ö,û, comptés respectivement pour
   a,a,e,e,e,i,i,o,o,u
- enfin on ne tiendra pas compte des autres caractères (ponctuations et 
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

