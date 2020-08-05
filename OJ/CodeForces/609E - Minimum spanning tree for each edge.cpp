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
//cout << setprecision(9)<<fixed;

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

#define int ll

const int INF = 0x3f3f3f3f;
const ll llINF = (long long)(1e18) + 100;   
const int MAXN = 200100;
const int MAXM = 1001000;
const ll mod=1e9+7;
const int LMAXN = 30;

typedef tuple<ll, int, int> tup;

int n, m;
vector<tup> edge, edg;

ll cost;
int id[212345], sz[212345];

int find(int a){
	return a == id[a] ? a : a = find(id[a]);
}

void merge(int a, int b){
	a = find(a);
	b = find(b);
	if (a == b)
		return;
	if (sz[a] < sz[b])
		swap(a, b);
	id[b] = a;
	sz[a] += sz[b];
}

vector<pll> adj[212345];

void kruskal(){
	frr(i, n){
		id[i] = i;
		sz[i] = 1;
	}

	sort(all(edge));

	for (auto x : edge)
		if (find(get<1>(x)) != find(get<2>(x))){
			merge(get<1>(x), get<2>(x));
			cost += get<0>(x);
		
			adj[get<1>(x)].pb({get<2>(x), get<0>(x)});
			adj[get<2>(x)].pb({get<1>(x), get<0>(x)});
		}
}

int  hgt[MAXN]; 
pll memo[MAXN][LMAXN]; 
bool vis[MAXN]; 

void dfs_lca(int v){
	vis[v] = 1; 

	for (auto x : adj[v]){
		if (vis[x.fst]) 
			continue;

		hgt[x.fst] = hgt[v] + 1; 
		memo[x.fst][0] = {v, x.snd}; 

		ll mx = x.snd;

		for (int i = 1; i < LMAXN; i++){ 
			mx = max( mx, (memo[memo[x.fst][i-1].fst][i-1]).snd);
			memo[x.fst][i] = {memo[memo[x.fst][i-1].fst][i-1].fst, mx};
		}	
		dfs_lca(x.fst);
	}
}

void build_lca(){
	for (int i = 0; i < LMAXN; i++) 
		memo[1][i]={1, 0};

	dfs_lca(1); 
}

pll find_lca(int a, int b){

	if (hgt[a] < hgt[b])
		swap(a, b); 

	ll mx = memo[a][0].snd;


	for (int i = LMAXN - 1; i >= 0 ; i--){
		if (hgt[memo[a][i].fst] >= hgt[b]){
			mx = max(mx, memo[a][i].snd);
			a = memo[a][i].fst;
		}	
	}

	if (a == b) 
		return {a, mx}; 

	for (int i = LMAXN - 1; i >= 0; i--){
		
		if (memo[a][i].fst != memo[b][i].fst){
			mx = max(mx, memo[a][i].snd);
			mx = max(mx, memo[b][i].snd);
			a = memo[a][i].fst;
			b = memo[b][i].fst;
		}
	}

	mx = max({mx, memo[a][0].snd, memo[b][0].snd});
	return {memo[a][0].fst, mx};
}

int32_t main(){
	fastio;
	cin>>n>>m;

	int a, b, c;

	fr(i, m){
		cin>>a>>b>>c;
		edge.pb({c, a, b});
		edg.pb({c, a, b});
	}

	kruskal();
	build_lca();

	for (auto x : edg){
		pll aux = find_lca(get<1>(x), get<2>(x));
		//cout<<aux.fst<<' '<<aux.snd<<endl;
		cout<<cost - aux.snd + get<0>(x)<<endl;
	}
}