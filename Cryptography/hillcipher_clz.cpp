//4.Hill Cipher
#include<stdio.h>
#include<string.h>
#include<math.h>
#define MAX 100

int main()
{
	char A[26];
	int i,j,m,n,k,index=0;
	for(i=0;i<26;i++){
		A[i]=65+i;//65-90 A-Z, 97-122 a-z
		
	}
	printf("Enter total number of rows and columns of key matrix: \n");
	scanf("%d%d",&m,&n);
	int key[m][n];
	printf("Enter the elements of key matrix:\n");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf("%d",&key[i][j]);
		}
	}
	if(m!=n)
	{
		printf("Given matrix can not be used as key matrix.\n");
		return 0;
	}
	
	char plain[MAX],cipher[MAX];
	// char plain, cipher;
	printf("\nEnter plaintext (without space): \n");
	scanf("%s",plain);
	strupr(plain);
	int p=strlen(plain),q=1;
	int b[p][q];
	int res[p][q];
	
	if(p%n!=0){
		printf("The given plaintext cannot be encrypted through given keymatrix.\n");
		return 0;
	}
	for(i=0;i<p;i++){
			for(k=0;k<26;k++)
			if(plain[i]==A[k]){
				b[i][0]=k;
			}
	}
	int p1=0;
	while(p1!=p) {
	 for(i=0; i<m; i++) {
        for(j=0; j<q; j++) {
            res[i+p1][j] = 0;
            for(k=0; k<n; k++) {
                res[i+p1][j] += key[i][k] * b[k+p1][j];
            }
        }
        res[i+p1][0]=res[i+p1][0]%26;
	 }
     p1=p1+n;  //p1+2
	}
	
	int position;
	printf("\nResultant:\n");
	for(i=0;i<p;i++){
		for(j=0;j<q;j++){
			position=res[i][j];
			cipher[index++]=A[position];
			printf("%d  ->  %c",res[i][j],A[position]);
		}
		printf("\n");
	}
	cipher[index++]='\0';
	printf("\nTHE CIPHER TEXT IS: \n%s",cipher);
	return 0;
}