#include<bits/stdc++.h> 
using namespace std; 
vector<int> v[1123456]; 
int componente[1123456],freq[1123456],n,m,valor,total;

void BFS(int x){
	queue<int>fila; 
	int i,termo;
	fila.push(x); 
	 

	while(!fila.empty()){
		termo=fila.front(); 
		fila.pop();  
		for(i=0;i<v[termo].size();i++){
			int u=v[termo][i]; 
			if(componente[u]==-1){ 
				componente[u]=componente[x];
				fila.push(u);
			}
		}
	}

} 

int main(){ 
	int i;
	cin>>n>>m; 
	for(i=0;i<n;i++) 
		componente[i]=-1; 
	for(i = 0;i < m;i++){
		int a, b;
		cin>>a>>b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	valor=0; 
	for(i=1;i<=n;i++){ 
		if(componente[i]==-1){ 
			valor++; 
			componente[i]=valor;
			BFS(i);
		}
	}  
	for(i=1;i<=valor;i++) 
		freq[i]=1;
	for(i=1;i<n;i++){
		if(v[i].size()!=2) 
			freq[componente[i]]=0;
	} 
	for(i=1;i<=valor;i++) 
		if(freq[i]==1) 
			total++;
	
	cout<<total<<endl;
	return 0;
}