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

int n, q, to[MAXN][33], id[MAXN], dist_to_cycle[MAXN], dist_on_cycle[MAXN], sz[MAXN];

void dfs(int v){
	if (dist_to_cycle[v] != -1)
		return;

	dfs(to[v][0]);

	dist_to_cycle[v] = dist_to_cycle[to[v][0]] + 1;
	id[v] = id[to[v][0]];
}

int get(int v, int k){
	for (int i = 30; i >= 0; i--)
		if (k & (1<<i))
			v = to[v][i];

	return v;	
}


signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin>>n;
	frr(i, n)
		cin>>to[i][0];

	frr(j, 30)
		frr(i, n)
			to[i][j] = to[ to[i][j - 1] ][j - 1];

	frr(i, n){
		id[i] = i;
		dist_to_cycle[i] = dist_on_cycle[i] = -1;
	}		

	frr(i, n){
		int v = to[i][20]; // in cycle
		if (dist_to_cycle[v] == -1){ // found new cycle
			dist_to_cycle[v] = 0;
			dist_on_cycle[v] = 0;
			sz[v]++;

			int u = to[v][0];
			while (dist_to_cycle[u] == -1){
				sz[id[v]]++;
				id[u] = id[v];
				dist_to_cycle[u] = 0;
				dist_on_cycle[u] = dist_on_cycle[v] + 1;
				v = u;
				u = to[u][0];
			}

		}
	}

	frr(i, n)
		if (dist_to_cycle[i] == -1)
			dfs(i);

	frr(i, n)
		cout<<dist_to_cycle[i] + sz[id[i]]<<' ';
	gnl;		
}