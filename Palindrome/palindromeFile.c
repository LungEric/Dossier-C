#include<stdio.h>
#include<string.h>

void main()
{	
	FILE *palindrome=fopen("palindrome.txt","r");
	
	int i ;
	char pal[1000][500]; // liste normal.
	int test, stringsize=0,listsize=0; 
	int isPalindrome(char *a) ;

/*-------------------------------------------------------------------------------------------------*/	

	printf("List word:\n");
	do{
		
		test = fscanf(palindrome,"%s",pal[i]);
		if(test>0)
		{
			listsize++;
			stringsize=max(stringsize,strlen(pal[i]));
			//printf("word[%d]:%s\n",i,pal[i]);
		}
		i++;
	}while(!feof(palindrome));
	printf("List info: \nListsize : %d\nStringsize : %d \n",listsize,stringsize);
	fclose(palindrome);
	
/*-------------------------------------------------------------------------------------------------*/

	pal[listsize][stringsize];
	FILE *palindrome2=fopen("palindrome.txt","r");
	FILE *rep=fopen("reponse.txt","w");
	FILE *rep2=fopen("reponse.csv","w");
	printf("List word:\n");
	do{
		fscanf(palindrome,"%s",pal[i]);
		if(isPalindrome(pal[i]))
		{
			printf("word[%d]:%s is palindrome\n",i,pal[i]);
			fprintf(rep,"word[%d]:%s is palindrome\n",i,pal[i]);
			fprintf(rep2,"word[%d]; %s \n",i,pal[i]);
		}
		i++;
	}while(!feof(palindrome));
	
	fclose(palindrome2);
	fclose(rep);
	
}

/*-----------------------------------------------------------------------------------------------------*/
int max(int x,int y){
	
	if(x>y) {
		return x;
	}
	return y ; 
}
/*--------------------------------------------------------------------------------------------------------*/
int isPalindrome(char *a) 
{ 
    // Start from leftmost and rightmost corners of str 
    int l = 0; 
    int h = strlen(a) - 1; 
    // Keep comparing characters while they are same 
    while (h > l) 
    { 
        if (a[l++] != a[h--]) 
        { 
            return 0; 
        } 
    } 
    return 1 ;
} 
