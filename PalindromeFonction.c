#include<stdio.h>
#include<string.h>

/*
	TEST : Un palindrome .
*/
void palindrome(char *string) ; 

/*---------------------------------------*/

int main(){
 		
   char string[100];
    int i, length;
    int nbstring =0, stsize =0 , test; // calcul du taille de la liste = test , nbre de string et taille des strings 
    int flag ; 
    
    printf("enter a string:\n");
   	scanf("%s",string);
   
   palindrome(string);
   printf("the flag : %d",flag);
    
    return 0;
}

/*---------------------------------------*/

void palindrome(char *string){
	
	int size = 0;
	int i, flag=0;
	char s[255] ; 
	char reverse ;
	
	/* Taille du string */
	
	size = strlen(string);
	
	strcpy(reverse,string);
	strrev(reverse);
	
	for(i=0;i<size;i++){
		
		
		if(strcmp(string,reverse)==0){
			flag = 1 ; 
		}
	}
	
	return flag; 
}
