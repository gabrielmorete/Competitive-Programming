#include<bits/stdc++.h> 
using namespace std;
int n,k,v[123],dif; 
map<int,int>freq;
int main(){
	ios::sync_with_stdio(false);
  	cin.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){ 
		cin>>v[i]; 
		if(freq[v[i]]==0){
			freq[v[i]]=i; 
			dif++;
		}
	}
	if(dif>=k){
		cout<<"YES"<<endl; 
		dif=0;
		for(int i=1;dif<k;i++){
			if(freq[v[i]]!=0){
				cout<<freq[v[i]]<<" "; 
				dif++; 
				freq[v[i]]=0; 
			}
		} 
		cout<<endl;
	} 
	else 
		cout<<"NO"<<endl;
	return 0;	
}	