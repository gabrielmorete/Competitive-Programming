#include<bits/stdc++.h> 
using namespace std;

int resolve(long long v[],int n,int k){
	int i,j,salva,foi;
	if(k==n) 
		return 1; 
	for(i=0;i<n-1;i++){ 
		if(v[i]!=-1)
			for(j=0;j<n;j++) 
				if(v[j]!=-1){
					if(j<i&&v[j]*3==v[i]){ 
						salva=v[j]; 
						v[j]=-1;
						foi=resolve(v,n,k+1);
						if(foi==1){ 
							printf("%d ",salva );
							return 1;
						} 
						else
							v[j]=salva;
					} 
					if(j>i&&v[i]*2==v[j]){ 
					salva=v[j]; 
					v[j]=-1;
					foi=resolve(v,n,k+1);
					if(foi==1){ 
						printf("%d ",salva );
						return 1;
					} 
					else
						v[j]=salva;
				} 
			}
	}
}



int main(){
	int n,i; 
	long long v[110];
	scanf("%d",&n); 
	for(i=0;i<n;i++){
		scanf("%d",&v[i]);
	}
 	sort(v,v+n); 
 	resolve(v,n,0); 
 	printf("\n");
 	return 0;

}