#include<bits/stdc++.h> 
using namespace std;
int k,n[212345],soma[212345]; 
vector<int> v[212345]; 
map<int,pair<int,int> >M;


int main(){
	ios::sync_with_stdio(false);
  	cin.tie(0); 
  	int a,i,j,ok=1;
	cin>>k; 
	for(i=0;i<k;i++){
		cin>>n[i]; 
		for(j=0;j<n[i];j++){
			cin>>a;
			v[i].push_back(a);
			if(j==0) 
				soma[i]=a; 
			else 
				soma[i]+=a;
	} 
	 
	} 
	for(i=0;i<k&& ok==1;i++){
		for(j=0;j<n[i]&& ok==1;j++) 
			if( M.find(soma[i]-v[i][j]) == M.end()){
				M[soma[i]-v[i][j]]=make_pair(i,j);
			} 
			else if(M[soma[i]-v[i][j]].first!=i){
				ok=2;
				cout<<"YES"<<endl;
				cout<<i+1<<" "<<j+1<<endl; 
				cout<<M[soma[i]-v[i][j]].first+1<<" "<<M[soma[i]-v[i][j]].second+1<<endl;
			}
	}
	
	if(ok==1) 
		cout<<"NO"<<endl;
	return 0;	
}	