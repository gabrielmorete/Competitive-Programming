#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i,n)     for(int i=0;i<n;i++)
#define frr(i,n)    for(int i=1;i<=n;i++)

#define ms(x,i) memset(x,i,sizeof(x))
#define dbg(x)  cout << #x << " = " << x << endl
#define all(x)  x.begin(),x.end()

#define gnl cout << endl
#define olar cout << "olar" << endl
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

#define MAX 1123456

int n,m,q,nset,id[MAX],sz[MAX],out[MAX],boolout[MAX],setsize[MAX]; 
pii edge[MAX];



int find(int p){
		if(id[p]==p) 
			return(p); 
		return(id[p]=find(id[p])); 
	} 

void unionn(int p,int q){
		p=find(p); 
		q=find(q);
		if(p==q)
			return; 
		if(sz[p]>sz[q]) 
			swap(p,q);//troca p e q
		id[p]=q;
		sz[q]+=sz[p];
	}  


int main(){
	fastio;
	int i,aux;	
	cin>>n>>m; 

	frr(i,n){
		id[i]=i; 
		sz[i]=1;
	} 
	
	frr(i,m) 
		cin>>edge[i].fst>>edge[i].snd; 
	
	cin>>q; 
	fr(i,q){
		cin>>aux;  
		out[i]=aux; 
		boolout[aux]=1;
	}  

	nset = n;
	frr(i,m) 
		if(boolout[i]==0){ 
			if(find(edge[i].fst) != find(edge[i].snd) ) 
				nset--; 

			unionn( edge[i].fst , edge[i].snd );
		}

	setsize[q]=nset;
	int a,b;
	
	for(i=q-1;i>=0;i--){
		a=find(edge[ out[i] ].fst); 
		b=find(edge[ out[i] ].snd); 
		unionn(edge[ out[i] ].fst,edge[ out[i] ].snd );
		if(a!=b) 
			setsize[i]=setsize[i+1]-1; 
		else 
			setsize[i]=setsize[i+1];
	} 

	fr(i,q) 
		cout<<setsize[i+1]<<' '; 
	cout<<endl;	

	return 0;
}