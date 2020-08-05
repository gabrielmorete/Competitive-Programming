#include "bits/stdc++.h"
using namespace std;

#define pb push_back
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
typedef vector<pii> vii;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = (long long)(1e18) + 100;   
const int MAXN = 2e5 + 10;
const ll mod=1e9+7;

int n, color[MAXN], pai[MAXN], memo[MAXN], ans[MAXN];
vi adj[MAXN];

int dfs(int v){
	int ans = (color[v]? 1 : -1);

	for (auto x : adj[v])
		if (x != pai[v]){
			pai[x] = v;
			ans +=  max(dfs(x), 0);
		}

	memo[v] = ans;

	return ans;	
}


void find_ans(int v){
	int aux;

	//cout<<v<<' '<<memo[v]<<endl;

	if (v != pai[v]) {
		aux = ans[pai[v]];

		if (memo[v] > 0)
			aux -= memo[v];
		
		ans[v] = memo[v] + max(aux, 0);
	}
	else
		ans[v] = memo[v];

	for (auto x : adj[v])
		if (x != pai[v])
			find_ans(x);
}

int32_t main(){
	fastio;

	cin>>n;
	frr(i, n)
		cin>>color[i];

	int a, b;	
	fr(i, n - 1){
		cin>>a>>b;
		adj[a].pb(b);
		adj[b].pb(a);
	}

	pai[1] = 1;
	dfs(1);

	find_ans(1);

	frr(i, n)
		cout<<ans[i]<<' ';
	gnl;
}