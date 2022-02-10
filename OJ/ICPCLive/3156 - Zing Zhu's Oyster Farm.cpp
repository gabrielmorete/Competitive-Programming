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
const int MAXN = 1e3 + 5;

bool adj[MAXN][MAXN][4], vis[MAXN][MAXN];

vector<array<int, 4>> hori, vert;

// U, D, L, R
int mx[4] = {-1, 1, 0, 0};
int my[4] = {0, 0, -1, 1};


bool valid(int x, int y){
	return (0 <= x and x < MAXN) and (0 <= y and y < MAXN);
}


int n, hgt;

// 1 NÂO PODE

void bfs(){
	memset(vis, 0, sizeof vis);
	queue<pii> fila;

	fila.push({0, 0});
	vis[0][0] = 1;

	int px, py;
	while (!fila.empty()){
		tie(px, py) = fila.front();
		fila.pop();

		fr(k, 4){
			int x = px + mx[k];
			int y = py + my[k];

			if (valid(x, y) and !adj[px][py][k] and !vis[x][y]){ // É !AJD MESMO
				fila.push({x, y});
				vis[x][y] = 1;
			}
		}
	}
}


signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	while (cin>>n and n > 0){
		memset(adj, 0, sizeof adj);
		hori.clear();
		vert.clear();

		fr(i, n){
			int x1, x2, y1, y2, h;

			cin>>x1>>y1>>x2>>y2>>h;

			x1 += 501; x2 += 501; y1 += 501; y2 += 501;

			if (x1 == x2)
				hori.pb({x1, min(y1, y2), max(y1, y2), h});
			if (y1 == y2)
				vert.pb({y1, min(x1, x2), max(x1, x2), h});
		}

		cin>>hgt;

		for (auto a : hori){// 1 é que NÂO PODE
			if (a[3] < hgt)
				continue;

			int x = a[0];
			for (int y = a[1]; y < a[2]; y++){ // U, D, L, R
				adj[x][y][0] = 1; // nao sobe
				adj[x - 1][y][1] = 1; // não desce
			}
		}

		for (auto a : vert){
			if (a[3] < hgt)
				continue;
		
			int y = a[0];
			for (int x = a[1]; x < a[2]; x++){// U, D, L, R
				adj[x][y][2] = 1; // não vai pra esquerda
				adj[x][y - 1][3] = 1;// não vai pra direita
			}
		}

		bfs();

		int ans = 0;
		fr(i, MAXN)
			fr(j, MAXN)
				if (!vis[i][j])
					ans++;
		
		cout<<ans<<endl;		
	}
}