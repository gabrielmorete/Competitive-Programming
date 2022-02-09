#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i,n) 	for(int i=0;i<n;i++)
#define frr(i,n)	for(int i=1;i<=n;i++)

#define ms(x,i)	memset(x,i,sizeof(x))
#define endl '\n'
#define dbg(x)	cout << #x << " = " << x << endl
#define all(x)	x.begin(),x.end()

#define gnl cout << endl
#define olar cout << "olar" << endl
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;
const int MOD = 1e9+7;
const int MAXN = 1e5 + 10;

vector<int> adju[MAXN];
int matchu[MAXN], matchv[MAXN];
int dist[MAXN], q[MAXN];

int m, n;
int r, c;

char grid[120][120];

int line[120][120];
int cols[120][120];

bool bfs(){
	int st = 0, en = 0;
	for(int u = 1; u <= m; u++){
		if(matchu[u] == 0){
			dist[u] = 0;
			q[en++] = u;
		}
		else dist[u] = INF;
	}
	dist[0]  = INF;

	while(en > st){
		int u = q[st++];
		if(dist[u] >= dist[0])
			continue;
		for(int v : adju[u]){
			if(dist[matchv[v]] == INF){
				dist[matchv[v]] = dist[u] + 1;
				q[en++] = matchv[v];
			}
		}
	}

	return (dist[0] != INF);
}

bool dfs(int u){
	if(u == 0) return true;
	for(int v : adju[u]){
		if(dist[matchv[v]] == dist[u] + 1){
			if(dfs(matchv[v])){
				matchv[v] = u;
				matchu[u] = v;
				return true;
			}
		}
	}
	dist[u] = INF;
	return false;
}

int HopcroftKarp(){
	memset(&matchu, 0, sizeof matchu);
	memset(&matchv, 0, sizeof matchv);
	int result = 0;
	while(bfs()){
		for(int u = 1; u <= m; u++){
			if(matchu[u] == 0 && dfs(u)){
				result++;
			}
		}
	}

	return result;
}

void clear(){
	fr(i, 2*r*c + 1) adju[i].clear();
}

int main(){
	fastio;

	int T;
	cin >> T;

	while(T--){
		cin >> r >> c;
		clear();

		frr(i, r){
			frr(j, c) grid[i][j] = '.';
		}

		int P; cin >> P;
		fr(i, P){
			int x, y; cin >> x >> y; 
			grid[x][y] = '*'; 
		}

		int W; cin >> W;
		fr(i, W){
			int x, y; cin >> x >> y; grid[x][y] = '#';
		}

		int l = 1;
		frr(i, r){
			int p = 1;
			
			while(p <= c){
				if(grid[i][p] == '#') p++;
				else{
					while(p <= c && grid[i][p] != '#'){
						line[i][p] = l;
						p++;
					}
					l++;
				}
			}
		}
		n = l - 1; // lado direito

		l = 1;
		frr(i, c){
			int p = 1;
			while(p <= r){
				if(grid[p][i] == '#') p++;
				else{
					while(p <= r && grid[p][i] != '#'){
						cols[p][i] = l;
						p++;
					}
					l++;
				}
			}
		}
		m = l - 1;// lado esquerdo
		
		frr(i, r){
			frr(j, c){
				if(grid[i][j] == '*'){
					adju[cols[i][j]].pb(line[i][j]);
				}
			}
		}

		cout << HopcroftKarp() << endl;
	}
}