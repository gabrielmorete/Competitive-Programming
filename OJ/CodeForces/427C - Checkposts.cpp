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

const int INF = 0x3f3f3f3f;
const ll llINF = (long long)(1e18) + 100;   
const int MAXN = 100100;
const int MAXM = 1001000;
const ll mod=1e9+7;
const int LMAXN = 25;

int n, m;
int cst[MAXN], pre[MAXN], lo[MAXN], stk[MAXN], scc[MAXN];
int cnt, sn, id;
vi adj[MAXN];

void dfsRscc( int v) {
	pre[v] = lo[v] = cnt++;
	stk[sn++] = v;
	for (int x : adj[v]) {
		if (pre[x] == -1)
			dfsRscc( x);
		lo[v] = min( lo[v], lo[x]);
	}
	if (lo[v] == pre[v]) {
		int u;
		do {
			u = stk[--sn];
			scc[u] = id;
			lo[u] = INF;
		} while (u != v);
		id++;
	}
}

int tarjan() {
	frr(v, n)
		pre[v] = -1;
	frr(v, n)
		if (pre[v] == -1)
			dfsRscc( v);
	return id;			
}

ll freq[MAXN], mn[MAXN];

int main(){
	fastio;
	cin>>n;
	frr(i,n)
		cin>>cst[i];
	cin>>m;
	int a, b;
	frr(i,m) {
		cin>>a>>b;
		adj[a].pb(b);	
	}	

	tarjan();
	ms(mn, INF);
	ms(freq, 1);

	frr(v, n)
		if (cst[v] < mn[scc[v]]){
			mn[scc[v]] = cst[v];
			freq[scc[v]] = 1;
		}
		else if (cst[v] == mn[scc[v]])
			freq[scc[v]]++;
	ll ans = 1, val = 0;

	fr(i, id){
		val += mn[i];
		ans = (ans * freq[i])%mod;
	}
	cout<<val<<' '<<ans<<endl;

}