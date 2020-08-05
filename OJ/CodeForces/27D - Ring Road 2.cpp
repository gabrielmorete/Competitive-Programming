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
const int MAXN = 1e5 + 10;
const ll mod=1e9+7;

int n;
vi adj[MAXN], adjt[MAXN];
int stk[MAXN], st, scc[MAXN];
bool vis[MAXN], val[MAXN];

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
	fill(val, val + n, 0);
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

	for (int i = 0; i < n; i += 2){
		if (scc[i] == scc[i + 1]) // i = true | i + 1 = false
			return false;
		val[i/2] = scc[i] > scc[i + 1]; // scc[!a] < scc[a] => true
	}	
	return true;			
}

void add(int a, int b){
	adj[a].pb(b);
	adjt[b].pb(a);
}

bool check(int a, int b, int c, int d){
	if ((a < c and c < b) and (b < d))
		return true;
	if ((a < d and d < b) and (c < a))
		return true;
	if ((c < a and a < d) and (d < b))
		return true;
	if ((c < b and b < d) and (a < c))
		return true;
	return false;	
}

int32_t main(){
	fastio;
	vii v;
	int m;
	cin>>m>>n;
	int a, b;

	fr(i, n){
		cin>>a>>b;
		if (a > b)
			swap(a, b);
		v.pb({a, b});	
	}

	int c, d;
	fr(i, n){
		a = v[i].fst, b = v[i].snd;
		for (int j = i + 1; j < n; j++){
			c = v[j].fst, d = v[j].snd;
			if (check(a, b, c, d)){
				add(2 * i + 1, 2 * j); 
				add(2 * j + 1, 2 * i);
				add(2 * i, 2 * j + 1);
				add(2 * j, 2 * i + 1);
			}
		}
	}

	n *= 2;

	if (sat()){
		n /= 2;
		fr(i, n)
			cout<<(val[i]? 'i' : 'o');
		gnl;	
	}
	else
		cout<<"Impossible"<<endl;
}