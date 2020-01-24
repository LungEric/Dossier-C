#include<stdio.h>
#include<string.h>

/*
	 Faire un anagram;
*/

int main (){
	
	int i, j ;
	char a[50];	
	char b[50];
	char temp;
	int sizea =0 ;
	int sizeb =0 ; 
	
	printf("entrer 1 mot\n");
	scanf("%s",a);
	printf("entrer 2 mot\n");
	scanf("%s",b);
	
	sizea = strlen(a);printf("size a : %d\n",sizea);
	sizeb = strlen(b);printf("size b : %d\n",sizeb);
	
	if(sizea != sizeb){
		printf("ce ne sont pas des anagrams\n");
	}
	
	for(i=0;i<sizea-1;i++){
		for(j=i+1;j<sizea-1;j++){
			if(a[i]>a[j]){
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
			if(b[i]>b[j]){
				temp=b[i];
				b[i]=b[j];
				b[j]=temp;
			}
		}
	}
	
	for(i=0;i<sizea-1;i++){
		
		if(a[i] !=b[i]){
			printf("not anagram");
			return 0 ;
		}else{
			printf("is a anagram");
			return 0;
		}
	}
}
