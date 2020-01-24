#include<stdio.h>


void main()
{
	int i,j ;
	char m[255];
	char l[]={'a','b','c','e','f','g','h','i','j','k ','l','m','n','p','s','r','w','x','y','z'};
	int count []= {0};
	
	printf("entrer un mot\n");
	scanf("%s",m);
	int size = 0;
	size = strlen(m);
	printf("size : %d\n",size);	
	
	for (i=0;i<size;i++){
		printf("la lettre [%c] est a la position [%d]\n",m[i],i);
		for(j=0;j<=26;i++){
			if(m[i]==l[j]){
				count[l[i]];
				printf("count [%c] = [%d] ",m[i],count) ; 
			}
		}
	}	
	
	/*
		
	*/
}
