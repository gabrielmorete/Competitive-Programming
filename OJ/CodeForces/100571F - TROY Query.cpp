#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fst first
#define snd second

#define fr(i,n)     for (int i = 0; i < n; i++)
#define frr(i,n)    for (int i = 1; i <= n; i++)

#define endl '\n'
#define gnl cout << endl
#define chapa cout << "oi meu chapa" << endl
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
//cout << setprecision(9)<<fixed;

#define dbg(x)  cout << #x << " = " << x << endl
#define all(x)  x.begin(),x.end()

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = (long long)(1e18) + 100;   
const int MAXN = 5e5 + 10;
const ll mod=1e9+7;

int n, m;
vi adj[MAXN], adjt[MAXN];
int stk[MAXN], st, scc[MAXN];
bool vis[MAXN];

void dfs1(int v){
	vis[v] = 1;
	for (int u : adj[v])
		if (!vis[u])
			dfs1(u);
	stk[st++] = v;	
}

void dfs2(int v, int cmp){
	scc[v] = cmp;
	for (int u : adjt[v])
		if (scc[u] == -1)
			dfs2(u, cmp);
}

bool sat(){
	fill(vis, vis + n, 0);
	fill(scc, scc + n, -1);
	st = 0;

	for (int i = 0; i < n; i++)
		if (!vis[i])
			dfs1(i);

	int v, cmp = 0;	
	while (st > 0){
		v = stk[--st];
		if (scc[v] == -1)
			dfs2(v, cmp++);
	}

	for (int i = 0; i < n; i += 2)
		if (scc[i] == scc[i + 1]) // i = true | i + 1 = false
			return false;
	return true;			
}

void add(int a, int b){
	adj[a].pb(b);
	adjt[b].pb(a);
}

map<ll, int> mapa;
typedef tuple<int, int, int> tup;
vector<tup> v;


bool test(int val){
	fr(i, n)
		adj[i].clear(), adjt[i].clear();

	int a, b, c;	
	fr(i, val){
		a = get<0>(v[i]);
		b = (n >> 2) + get<1>(v[i]); 
		c = get<2>(v[i]);
		a <<= 1; b <<= 1;

//		cout<<a<< ' ' << b << ' '<< c<<endl;

		if (!c){
			add(a + 1, b);
			add(b + 1, a);
			add(a, b + 1);
			add(b, a + 1);
		}
		else{
			add(a, b);
			add(b + 1, a + 1);
			add(a + 1, b + 1);
			add(b, a);
		}
	}

//	chapa;

	return sat();
}

int32_t main(){
	fastio;
	cin>>m; // clauses
	ll a, b, c, d;

	n = 0;
	fr(i, m){
		cin>>a>>b>>c>>d;
		if (!mapa.count(a))
			mapa[a] = n++;
		if (!mapa.count(b))
			mapa[b] = n++;
		if (c == d)
			v.pb({mapa[a], mapa[b], 1});
		else
			v.pb({mapa[a], mapa[b], 0});
	}

	n <<= 1; // lines and columns
	n <<= 1; // true and false

	int mn , mx, meio, ans;
	mn = ans = 1;
	mx = m;
	while (mn <= mx){
		meio = (mn + mx)/2;
		if (test(meio)){
			ans = meio;
			mn = meio + 1;
		}
		else
			mx = meio - 1;
	}

	frr(i, m)
		cout<<(i <= ans? "Yes" : "No")<<endl;
}