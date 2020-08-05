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
#define chapa cout << "oi meu chapa" << endl
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;  
const int MAXN = 100100;
const ll mod=1e9+7;
const int LMAXN = 20;

typedef tuple<ll,ll,ll> tup;

ll n,m,k;
vll ans;
vector<tup> adj[312345];
bool vis[312345];

void dijikstra(){
	set<tup> fila;

	fila.insert({0,1,0});

	tup aux;

	while(!fila.empty()){

		aux=*fila.begin();
		fila.erase(fila.begin());

		if(vis[get<1>(aux)])
			continue;

		vis[get<1>(aux)]=1;
		
		if(ans.size()<k && get<1>(aux)!=1)
			ans.pb(get<2>(aux));
		
		for(auto x:adj[get<1>(aux)])
			fila.insert( {get<0>(aux)+get<1>(x),get<0>(x),get<2>(x) } );

	}


}


int main(){
	fastio;
	cin>>n>>m>>k;

	ll x,y,w;

	frr(i,m){
		cin>>x>>y>>w;
		adj[x].pb({y,w,i});
		adj[y].pb({x,w,i});
	}

	dijikstra();

	cout<<ans.size()<<endl;
	for(auto x:ans)
		cout<<x<<' ';
	gnl;


}