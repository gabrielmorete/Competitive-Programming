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
const int MAXN = 250 + 10;

vector<int> adju[MAXN], adjv[MAXN]; // adj da partição U
int matchu[MAXN], matchv[MAXN], coveru[MAXN], coverv[MAXN]; 
int dist[MAXN], q[MAXN];
int m, n;

bool bfs(){
	int st = 0, en = 0;
	for (int u = 1; u <= m; u++){
		if (matchu[u] == 0){
			dist[u] = 0; 
			q[en++] = u;
		}
		else dist[u] = INF;
	}
	dist[0] = INF;
	while (en > st){
		int u = q[st++];
		if (dist[u] >= dist[0]) 
			continue;
		for (int v : adju[u]){
			if (dist[matchv[v]] == INF){
				dist[matchv[v]] = dist[u] + 1;
				q[en++] = matchv[v];
			}
		}
	}

	return (dist[0] != INF);
}

bool dfs(int u){
	if (u == 0) return true;
	for (int v : adju[u]){
		if (dist[matchv[v]] == dist[u] + 1){
			if (dfs(matchv[v])){
				matchv[v] = u; 
				matchu[u] = v;
				return true;
			}
		}
	}
	dist[u] = INF;
	return false;
}

int hopcroftKarp(){
	memset(&matchu, 0, sizeof matchu);
	memset(&matchv, 0, sizeof matchv);
	int result = 0;
	while (bfs()){
		for (int u = 1; u <= m; u++){
			if (matchu[u] == 0 and dfs(u))
				result++;
		}
	}
	return result;
}

bool is_in[MAXN][MAXN];

int visu[MAXN], visv[MAXN];
void min_lex_matching(){
	hopcroftKarp(); // We will modify a initial matching, can be any algorithm	
	
	for (int v = 1; v <= m; v++){ // We want to minimize for the right side
		for (int j = 1; j <= m; j++)
			visu[j] = visv[j] = -1;

		queue<int> fila;
		fila.push(v + m); // Here, right vertices are shifted to differentiate
		visv[v] = 0;

		while (!fila.empty()){
			int vtx = fila.front();
			fila.pop();

			if (vtx <= m){ // On the left
				for (auto y : adju[vtx])
					if (y != matchu[vtx] and visv[y] < 0 and y >= v){ // y >= because of the lex restriction
						visv[y] = vtx; // I visited through vtx
						fila.push(y + m);
					}
			}
			else{
				vtx -= m;
				if (vtx >= v){ // It should be alternating, I can only use matching edge
					visu[matchv[vtx]] = vtx;
					fila.push(matchv[vtx]);
				}	
			}
		}

		// Now I will try a new matching, through a alternating cycle
		for (auto u : adjv[v]){
			if (u < matchv[v] and visu[u] > 0){ // It's better and I can match this
				int pv = matchu[u];

				matchu[u] = v;
				matchv[v] = u;

				while (pv != v){
					int pu = visv[pv];
					int aux = matchu[pu];
					
					matchv[pv] = pu;
					matchu[pu] = pv;
					pv = aux;
				}	

				break; // I got the smallest lex, leaving
			}
		}	
	}
}


void solve(){
	cin>>m>>n;

	frr(i, m)
		frr(j, m)
			is_in[i][j] = 0;

	frr(i, n){
		frr(j, m){
			int x;
			cin>>x;
			is_in[x][j] = 1;
		}
	}		

	cout<<m - n<<endl;


	frr(i, m){
		adju[i].clear();
		adjv[i].clear();
	}

	frr(i, m)
		frr(j, m)
			if (is_in[i][j] == 0){
				adju[i].pb(j);
				adjv[j].pb(i);	
			}

	for (int k = n; k < m; k++){
		min_lex_matching();	


		for (int i = 1; i < m; i++)
			cout<<matchv[i]<<' ';
		cout<<matchv[m]<<endl;

		frr(u, m)
			is_in[u][matchu[u]] = 1;

		frr(u, m){
			int p = 0;
			while (adju[u][p] != matchu[u])
				p++;
			adju[u].erase(adju[u].begin() + p);
		}	

		frr(v, m){
			int p = 0;
			while (adjv[v][p] != matchv[v])
				p++;
			adjv[v].erase(adjv[v].begin() + p);
		}	
	}
	gnl; // blank line after each test case
}


signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;
	while (T--)
		solve();
}