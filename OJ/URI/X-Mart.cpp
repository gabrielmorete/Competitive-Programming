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

	for (int i = 2; i < n; i++)
		if (!vis[i])
			dfs1(i);

	int v, cmp = 0;	
	while (st > 0){
		v = stk[--st];
		if (scc[v] == -1)
			dfs2(v, cmp++);
	}

	for (int i = 2; i < n; i += 2)
		if (scc[i] == scc[i + 1])
			return false;
	return true;			
}

void add(int a, int b){
	adj[a].pb(b);
	adjt[b].pb(a);
}

int32_t main(){
	fastio;
	int c, p;

	cin>>c>>p;

	while (c != 0){
		int a, b;

		n = 2 * p + 2;

		fr(i, n)
			adj[i].clear(), adjt[i].clear();

		fr(i, c){
			cin>>a>>b;
			a = 2 * a;
			b = 2 * b;

			if (a == 0 and b > 0){
				add(b, b + 1); // !b = 2 * b; b = 2 * b + 1
			}
			else if (b == 0 and a > 0){
				add(a, a + 1);
			}
			else{
				add(a, b + 1);
				add(b, a + 1);
			}
		
			cin>>a>>b;
			a = 2 * a;
			b = 2 * b;

			if (a == 0 and b > 0){
				add(b + 1, b); // !b = b; b = b + 1
			}
			else if (b == 0 and a > 0){
				add(a + 1, a);
			}
			else{
				add(a + 1, b);
				add(b + 1, a);
			}
		}

		if (sat())
			cout<<"yes"<<endl;
		else
			cout<<"no"<<endl;

		cin>>c>>p;
	}
}