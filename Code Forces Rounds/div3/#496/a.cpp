#include<bits/stdc++.h> 
using namespace std;
	int n,v[1001];

int main(){
	ios::sync_with_stdio(false);
  	cin.tie(0);
	int i,j,aux;
	cin>>n; 
	j=0; 
	for(i=0;i<n;i++){
		cin>>aux; 
		if(aux==1){ 
			j++;  
			v[j]=1;
		}	
		else 
			v[j]=aux;
	}
	cout<<j<<endl; 
	for(i=1;i<=j;i++) 
		cout<<v[i]<<" "; 
	cout<<endl;

	return 0;	
}	