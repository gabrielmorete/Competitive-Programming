#include<bits/stdc++.h> 
int v[1123456];
using namespace std;
int main(){
	int n,k,i,ok=1; 
	scanf("%d",&n); 
	scanf("%d",&k); 
	for(i=0;i<n;i++) 
		scanf("%d",&v[i]); 
	sort(v,v+n); 
	if(k==0){
		if(v[0]==1){ 
			printf("-1\n"); 
		} 
		else 
			printf("1\n");
	} 
	else{
	i=v[k-1]; 
	if(k-1<n-1)
		if(v[k]==i){ 
			printf("-1\n");
			ok=0;	
		} 
	if(ok==1) 
		printf("%d\n",i); 
		} 
	return 0;		
}