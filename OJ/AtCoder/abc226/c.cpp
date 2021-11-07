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

#define dbg(x)  cout << #x << " = " << x << endl
#define all(x)  x.begin(), x.end()

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

const int INF = 0x3f3f3f3f;
const ll llINF = (long long)(1e18) + 100;   
const int MAXN = 2e5 + 10;

ll n, t[MAXN], ans[MAXN];
vi adj[MAXN];

bool vis[MAXN];

ll dfs(ll v){
	ll sum = t[v];
	vis[v] = 1;

	for (auto x : adj[v])
		if (!vis[x])
			sum += dfs(x);

	return sum;	
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin>>n;
	
	ll k, x;
	frr(i, n){
		cin>>t[i];
		cin>>k;
		fr(j, k){
			cin>>x;
			adj[i].pb(x);
		}
	}

	cout<<dfs(n)<<endl;
}