#include<bits/stdc++.h> 
using namespace std;
char num[2123456]; 
int n,tam;

int maxcut(int ini, int fim){
	int p1,p2,sum,tot,aux; 
	p1=p2=ini;
	sum=0; 
	tot=0;
	while(p1<=fim && p2<=fim){ 
		sum+=num[p2]-48; 
		if(sum%3==0){
			aux=0;
			if(p1!=p2)
				aux=maxcut(p1+1,p2); 
			tot+=max(aux,1);	
			sum=0; 
			p2++; 
			p1=p2;
		} 
		else
			p2++;
		

	} 
	if(p1!=p2) 
		tot+=maxcut(p1+1,p2);  
	return(tot);
}

int main(){
	scanf(" %s",num); 
	tam=strlen(num);
	printf("%d\n",maxcut(0,tam-1)); 
	return 0;	
}	