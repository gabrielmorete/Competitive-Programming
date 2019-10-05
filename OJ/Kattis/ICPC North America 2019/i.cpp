#include "bits/stdc++.h"
using namespace std;
 
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
 
#define fr(i,n) 	for(int i=0;i<n;i++)
#define frr(i,n)	for(int i=1;i<=n;i++)
 
#define ms(x,i)	memset(x,i,sizeof(x))
#define dbg(x)	cout << #x << " = " << x << endl
#define all(x)	x.begin(),x.end()

#define endl "\n" 
#define gnl cout << endl
#define olar cout << "olar" << endl
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL) 
 
typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;
 
const int INF = 0x3f3f3f3f;
const ll llINF = (long long)(1e18) + 100;  

typedef tuple<ll,ll,ll> tup;

bool station[555];

ll n, m, t, d;
vector<pll> adj[555];
ll dist[555];
ll fuel[555];


void dijkstra(){
	fr(i,555){
		dist[i] = llINF;
		fuel[i] = -1;
	}	

	set<tup> fila;
	dist[1] = 0;
	fuel[1] = d;
	fila.insert({0,-d,1});

	ll dst,ar,v;
	tup aux;
	while( !fila.empty()){
		aux = *fila.begin();
		fila.erase(fila.begin());
		dst = get<0>(aux); ar = -get<1>(aux); v = get<2>(aux);
		if( dist[v] < dst and fuel[v] > ar )
			continue;
		dist[v] = min( dist[v], dst);
		fuel[v] = max( fuel[v], ar);
		
		if( station[v]){
			ar = d;
			fuel[v] = d;
		}
		for( auto x : adj[v]){
			if( x.snd <= ar)
				fila.insert({dst + x.snd, -(ar-x.snd ), x.fst});
		}	

		if( v == n){
			return;
		}

	}
}


int main(){
	fastio;
	cin>>n>>m>>t>>d;

	ll x;
	station[1] = 1;
	fr(i,t){
		cin>>x;
		station[x] = 1;
	}

	ll y, k;
	fr(i,m){
		cin>>x>>y>>k;
		adj[x].pb({y,k});
		adj[y].pb({x,k});
	}

	dijkstra();

	if(dist[n] != llINF)
		cout<<dist[n]<<endl;
	else
		cout<<"stuck"<<endl;	
	 
}