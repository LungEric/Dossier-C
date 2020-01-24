
#include<stdio.h>
#include<string.h>
#define MAX 255

void swap(int *a,int *b);
/*----------------------------------------*/

void main(){
	
	char a[MAX];
	int count[26] = {0},countU[26] = {0};
	int i=0,j=0 ;
	FILE *fic=fopen("Lettre.txt","w");
	
	printf("Enter a string:\n");
	scanf("%s",a);
	
	for(i=0;a[i] !='\0';i++){
		
		if(a[i]>='a' && a[i]<='z'){
			count[a[i]-'a']++; 
		}
		if(a[i]>='A' && a[i]<='Z'){
			countU[a[i]-'A']++; 
		}
	}
	
	printf("Lower Case:\n");
	 for (i = 0; i < 26; i++)
   {
      /** Printing only those characters
          whose count is at least 1 */
         printf("%c occurs %d times in the entered string.\n",i+'a',count[i]);
         fprintf(fic,"%c occurs %d times in the entered string\n",i+'a',count[i]); 
	}
	
	printf("Upper Case:\n");
	for (i = 0; i < 26; i++)
   {
      /** Printing only those characters
          whose count is at least 1 */
  	printf("%c occurs %d times in the entered string.\n",i+'A',count[i]);  
	  fprintf(fic,"%c occurs %d times in the entered string\n",i+'A',count[i]); 
	}

}

/*-------------------------------------------*/
void swap(int *a,int *b){
	
	int temp ; 
	
	temp = *a;
	*a = *b ;
	*b = temp ;
	
	return *a , *b; 
}
