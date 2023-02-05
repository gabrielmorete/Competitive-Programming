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

int n, m;
ll dist[MAXN];
vector<array<int, 3>> edges;

int vis[MAXN];

void dfs(int v){
	vis[v] = 1;
	for (auto x : edges)
		if (x[0] == v and vis[x[1]] == 0)
			dfs(x[1]);	
}


int bellman(){
	frr(i, n)
		dist[i] = llINF;

	dist[1] = 0;
	

	fr(i, n)
		for (auto x : edges)
			if (dist[x[0]] != llINF)
				dist[x[1]] = min(dist[x[1]], dist[x[0]] + x[2]);

	for (auto x : edges)
		if (dist[x[0]] != llINF and dist[x[1]] > dist[x[0]] + x[2]){
			dist[x[1]] = dist[x[0]] + x[2];
			dfs(x[0]);
		}

	if (vis[n]) return -1;
	return 0;
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin>>n>>m;

	fr(i, m){
		int a, b, c;
		cin>>a>>b>>c;
		edges.pb({a, b, -c});
	}

	int ans = bellman();

	if (ans == -1)
		cout<<-1<<endl;
	else
		cout<<-dist[n]<<endl;
}