#include<stdio.h>
#include<string.h>

void main (){
	
	int additionmatrice( int *matricea, int *matriceb ,int *taille) ; 
	int matricea[255][255];
	int matriceb[255][255];
	int i,j ; //count
	int taille ; 
	int addition[255][255];
	
	printf("Size of matrice : \n");
	scanf("%d",&taille) ;
	
	matricea[taille][taille];
	matriceb[taille][taille];
	
	printf("Enter %d numbers for matrice a : \n",taille*taille);
	for(i=0;i<taille;i++){
		for(j=0;j<taille;j++){
			scanf("%d",&matricea[i][j]);
		}
	}
	printf("You enter: \n");
	for(i=0;i<taille;i++){
		for(j=0;j<taille;j++){
			printf("%d =[%d][%d] \n",matricea[i][j],i,j);
		}
	}
	
	printf("Enter %d numbers for matrice b : \n",taille*taille);
	for(i=0;i<taille;i++){
		for(j=0;j<taille;j++){
			scanf("%d",&matriceb[i][j]);
		}
	}
	printf("You enter: \n");
	for(i=0;i<taille;i++){
		for(j=0;j<taille;j++){
			printf("%d =[%d][%d] \n",matriceb[i][j],i,j);
		}
	}
	
	printf("Addition de la matricea et matriceb: \n");
		for(i=0;i<taille;i++){
		for(j=0;j<taille;j++){
			addition[i][j]=matricea[i][j]+matriceb[i][j] ; 
		}
	}
	for(i=0;i<taille;i++){
		for(j=0;j<taille;j++){
			printf("%d = [%d][%d]\n",addition[i][j],i,j ); 
		}
	}
}

/*--------------------------------------*/

