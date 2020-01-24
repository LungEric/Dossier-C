#include<stdio.h>
#include<string.h>
#include<stdlib.h>


void sorting(int *l,int nb);
void swap(int *a,int *b) ; 
void main (){
	
	int i,nb ;
	int* liste = NULL;
	
	printf("Number:\n");
	scanf("%d",&nb);
	
	liste = calloc(nb,sizeof(int)); 
	
	printf("Enter element:\n");
	for(i=0;i<=nb;i++){
		
		scanf("%d",&liste[i]) ; 
		
	}
	for(i=0;i<=nb;i++){
		printf("%d\n",liste[i]); 
		
		
	}
	sorting(liste,nb);
	
	for(i=0;i<=nb;i++){
		printf("\nSorted: %d",liste[i]);	
	}
}

void sorting(int *l,int nb){
	int i,j ; 
	for(i=0 ;i<=nb;i++) {
		for(j=i+1;j<=nb;j++){
			if(l[i]>l[j]) {
				swap(&l[i],&l[j]); 
			}
		}
	}
}

void swap(int *a,int *b){
	int temp ;
	temp = *b ;
	*b = *a ;
	*a = temp ; 
	return ; 
}
