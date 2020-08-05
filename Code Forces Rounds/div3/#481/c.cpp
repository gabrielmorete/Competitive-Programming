#include<bits/stdc++.h> 
using namespace std; 
#define max 1123456
long long n,m,soma[max],x;

int main(){
	int i,j; 
	scanf("%I64d",&n); 
	scanf("%I64d",&m);  
	
	scanf("%I64d",&soma[0]);
	for(i=1;i<n;i++){
		scanf("%I64d",&soma[i]); 
		soma[i]+=soma[i-1];
	}  
	j=0;
	for(i=0;i<m;i++){
		scanf("%I64d",&x); 
		while(j<n){ 
			if(j==0){
				if(x<=soma[j]){
				printf("%d %I64d\n",j+1,x);
				break;
				} 
				else 
					j++;
			} 
			else if(j==n-1) {
				printf("%d %I64d\n",j+1,x-soma[j-1] ); 
				break;
			}
			else if(x>=soma[j-1] && x<=soma[j]){
				printf("%d %I64d\n",j+1,x-soma[j-1]); 
				break;
			} 
			else 
				j++;
		}
	}
	return 0;
}