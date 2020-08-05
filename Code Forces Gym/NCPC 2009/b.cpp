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
ll val[112345], sum[112345];
vi adj[112345];
int vis[112345];

void dfs(int v, int cnt){
	vis[v] = cnt;
	sum[cnt] += val[v];
	for (int x : adj[v]){
		if (vis[x] == 0)
			dfs(x, cnt);
	}
}


int main(){
	fastio;
	cin>>n>>m;
	fr(i, n)
		cin>>val[i];

	int a, b;
	fr(i, m){
		cin>>a>>b;
		adj[a].pb(b);
		adj[b].pb(a);
	}

	bool ok = 1;
	int cnt = 1;
	fr(i, n){
		if (vis[i] == 0){
			dfs(i, cnt);
			if (sum[cnt] != 0)
				ok = 0;
		}
	}

	if (ok)
		cout<<"POSSIBLE"<<endl;
	else
		cout<<"IMPOSSIBLE"<<endl;


}