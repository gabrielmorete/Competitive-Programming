#include<bits/stdc++.h> 
int M[30][30];
int main(){ 
	int n,i,j,max=0;
	char a,b;
	scanf("%d",&n); 

	scanf(" %c",&a);
	while(n>1){
		scanf(" %c",&b); 
		M[a-65][b-65]++; 
		a=b; 
		n--;
	}  
	for(i=0;i<30;i++) 
		for(j=0;j<30;j++) 
			if(M[i][j]>max){
				max=M[i][j];
				a=i+65; 
				b=j+65;
			} 

	printf("%c%c\n",a,b);
}