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
vi adj[112345];
int in[112345], pre[112345], lo[112345], stk[112345], scc[112345];
int clk, sn, id;

void dfsRscc( int v){
	pre[v] = lo[v] = clk++;
	stk[sn++] = v;
	for (int x : adj[v]){
		if (pre[x] == -1)
			dfsRscc( x);
		lo[v] = min( lo[v], lo[x]);
	}
	if (lo[v] == pre[v]){
		int u;
		do {
			u = stk[--sn];
			scc[u] = id;
			lo[u] = INF;
		} while (u != v);
		id++;
	}
}

int tarjan(){
	frr(i,n)
		pre[i] = -1;
	clk = sn = id = 0;
	frr(i,n)
		if (pre[i] == -1)
			dfsRscc( i);
	return id;			
}



void solve(){
	cin>>n>>m;
	frr(i,n){
		adj[i].clear();
		in[i] = 0;
	}
	in[0] = 0;
	int a, b;
	fr(i,m){
		cin>>a>>b;
		adj[a].pb(b);
	}

	int ans = 0;
	tarjan();
	frr(v,n)
		for (int x : adj[v])
			if (scc[v] != scc[x])
				in[scc[x]]++;
	fr(i,id)
		if (in[i] == 0)
			ans++;		

	cout<<ans<<endl;	
}

int main(){
	fastio;
	int t;
	cin>>t;
	while (t--)
		solve();

}