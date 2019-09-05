#include<bits/stdc++.h> 

int main(){
	int n,k; 
	scanf("%d",&n); 
	scanf("%d",&k); 
	while(k>0){
		if(n%10==0) 
			n=n/10; 
		else 
			n--; 
		k--;
	}
	printf("%d\n",n); 
	return(0);
}