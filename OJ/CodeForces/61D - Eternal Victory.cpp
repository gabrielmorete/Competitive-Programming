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
int n;
vii adj[112345];
ll mx = 0;

bool vis[112345];
void dfs(int v, ll dst){
	vis[v] = 1;

	for(auto x : adj[v]){
		if(vis[x.fst])
			continue;
		dfs( x.fst, dst + ((ll) x.snd));
	}

	if(adj[v].size() == 1){
		mx = max(mx, dst);
		return;
	}

}

int main(){
	fastio;
	cin>>n;

	int a, b, c;
	ll sum = 0;
	fr(i, n- 1){
		cin>>a>>b>>c;
		adj[a].pb({b, c});
		adj[b].pb({a, c});

		sum += ((ll) c)*2ll;
	}

	dfs( 1, 0);
	cout<<sum - mx<<endl;

}