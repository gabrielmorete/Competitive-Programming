#include "bits/stdc++.h"
using namespace std;

bool vis[1010];
int m, dlt, in[1010], out[1010];
vector<int> adj[1010];

void dfs(int v){
	vis[v] = 1;
	dlt += max(0, in[v] - out[v]);
	for (auto x : adj[v])
		if (!vis[x])
			dfs(x);
}

void solve(){
	for (int i = 1; i <= 1000; i++){
		adj[i].clear();
		in[i] = out[i] = 0;
		vis[i] = 0;
	}

	cin>>m;

	for (int i = 1; i <= m; i++){
		int x, y;
		cin>>x>>y;
		in[y]++;
		out[x]++;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}	

	int ans = m;

	for (int i = 1; i <= 1000; i++)
		if (!vis[i] and !adj[i].empty()){
			ans++; // Sum 1 for each connected component

			dlt = 0; // in[i] - out[i];
			dfs(i);

			ans += max(0, dlt - 1); // Cost to make the digraph eulerian
		}

	cout<<ans<<endl;
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;
	while (T--)
		solve();
}