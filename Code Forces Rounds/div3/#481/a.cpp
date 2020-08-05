#include<bits/stdc++.h> 
using namespace std; 
#define max 1123
int n,v[max], freq[max],x;


int main(){
	int i; 
	scanf("%d",&n); 
	for(i=0;i<n;i++) 
		scanf("%d",&v[i]); 
	for(i=n-1;i>=0;i--){
		if(freq[v[i]]==0){ 
			freq[v[i]]=1; 
			x++; 
		} 
		else{
			v[i]=-1;
		}	
	} 
	printf("%d\n",x); 
	for(i=0;i<n;i++) 
		if(v[i]!=-1) 
			printf("%d ",v[i]); 
	printf("\n");	


	return 0;
}