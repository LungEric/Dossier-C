/*
-------------------------------------------------------------------------------
IPAM - Annee Academique 2015-2016
Bachelier en Informatique
Cours de Principes Algorithmiques et Programmation
Examen de Septembre 2016
-------------------------------------------------------------------------------
Remarque: ce fichier est intentionnellement sans caracteres accentues.
-------------------------------------------------------------------------------

Enonce:
=======

"Seuls les mots de passe qui n'ont aucune signification sont de bons mot de 
 passe!"
                 
Une attaque informatique classique pour craquer un mot de passe est 
l'attaque par dictionnaire. Le programme attaquant va essayer une liste 
de mots de passe se trouvant dans un fichier, appelé dictionnaire.

On trouve facilement sur le net ce genre de dictionnaires, certains pouvant
contenir jusqu'a 1.5 milliards de mots de passe!

On vous demande d'ecrire un programme qui verifie si les mots de passe 
d'une liste donnee se trouvent dans un dictionnaire donne.

Le fichier "10k_most_common.txt" contient une liste de 10.000 mots de 
passe les plus utilises. Si un mot de passe se trouve dans cette liste, 
c'est necesserairement un mauvais mot de passe (puisque directement 
craquable par une methode de base). 
Votre programme ne pourra lire ce fichier qu'une seule fois lors 
de son execution. L'idee est que votre programme devrait pouvoir aussi etre
utilise avec des dictionnaires contenant un plus grand nombre de mots de 
passe (1.5 milliard de pw ~ 9 Gb), dont la lecture multiple s'avère
etre une tres mauvaise idee ent erme de temps d'execution.

Le fichier "pass2chk.txt" contiendra la liste des mots de passe a verifier, et:
	- chaque mot de passe sera sur une et une seule ligne,
	- votre programme ne peut absolument pas reposer sur des suppositions a 
	  propos du nombre de lignes et/ou du nombre de caracteres par ligne,
	- vous minimiserez le nombre de lectures de ce fichier.

Les "mauvais mots de passe" seront ecrits dans un fichier texte, nomme 
badpasswords.txt", en indiquant pour chacun le mot lui-meme et la ligne 
du dictionnaire où il a ete trouve, ainsi que le mot du dictionnaire dans 
lequel on l'a trouve. Notez que si un mot de passe n'est
qu'une partie d'un mot du dictionnaire c'est aussi un mauvais de passe!

A titre indicatif les mots de passe "physics", "football", "shakira", et
"2017" se trouvent dans le fichier "pass2chk.txt" qui vous est fourni, et a 
nouveau a titre indicatif, le fichier de reponse contiendra les resultats 
suivants:

football found in line 10 in football 
physics found in line 5887 in physics 
football found in line 5901 in football1 
shakira found in line 9654 in shakira 

	
	
Votre copie d'examen sera constituee du code source de votre programme
et du fichier de sortie de votre programme.

Pour rappel:
  - essayez de modulariser autant que possible votre code en utilisant 
  	fonctions et procedures!

---------------------------------------------------------------------------
Vous ecrirez  votre programme C dans ce fichier que vous renommerez comme 
suit:
NOM_Prenom_PAP_Examen_sept_2016.c

De plus vous indiquerez vos nom et prenom dans l'espace reserve ci-dessous.

Votre fichier de sortie sera nomme suivant le model suivant:
NOM_Prenom_badpasswords.txt

Bon travail. 
-------------------------------------------------------------------------------
PS: Ne modifiez aucunement les commentaires de ce fichier, merci.
-------------------------------------------------------------------------------
 
 Nom:
 
 Prenom:
-------------------------------------------------------------------------------
Ecrivez votre programme C ci-dessous:
*/

