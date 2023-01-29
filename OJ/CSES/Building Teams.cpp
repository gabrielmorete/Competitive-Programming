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
const int MAXN = 4e5 + 10;

int n, m, vis[MAXN];
vi adj[MAXN];

void dfs(int v, int c){
	vis[v] = c;

	for (auto x : adj[v]){
		if (vis[x] == 0)
			dfs(x, 3 - c);
		else if (vis[x] == c){
			cout<<"IMPOSSIBLE"<<endl;
			exit(0);
		}
	}
}


signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin>>n>>m;

	fr(i, m){
		int a, b;
		cin>>a>>b;
		adj[a].pb(b);
		adj[b].pb(a);
	}

	frr(i, n)
		if (vis[i] == 0)
			dfs(i, 1);

	frr(i, n)
		cout<<vis[i]<<' ';
	gnl;
}