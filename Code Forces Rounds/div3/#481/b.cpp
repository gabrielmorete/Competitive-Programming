#include<bits/stdc++.h> 
using namespace std; 
#define max 112
int n,freq[max],x;
char v[max];

int main(){
	int i,seg; 
	scanf("%d",&n); 
	scanf(" %s",v); 
	for(i=0;i<n;i++) 
		if(v[i]=='x') 
			freq[i]=1; 
	seg=0; 
	for(i=0;i<n;i++){
		if(freq[i]==1) 
			seg++; 
		else if(freq[i]==0 && seg!=0){
			if(seg>2) 
				x+=seg-2; 
			seg=0;
		}
	} 
	if(seg!=0){
		if(seg>2) 
				x+=seg-2;
	}		
	printf("%d\n",x);
		


	return 0;
}