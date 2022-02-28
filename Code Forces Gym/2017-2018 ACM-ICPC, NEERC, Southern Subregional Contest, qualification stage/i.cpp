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
const int MAXN = 3e2 + 10;

ll n, m, q, p, noise[MAXN][MAXN], vis[MAXN][MAXN];
vector<string> mapa;

int mx[4] = {1, -1, 0, 0};
int my[4] = {0, 0, 1, -1};

bool valid(int x, int y){
	if (x < 0 or x >= n)
		return false;

	if (y < 0 or y >= m)
		return false;

	return mapa[x][y] != '*';
}

int cnt;

void bfs(int sx, int sy, ll mul){
	queue<tuple<ll, ll, ll>> fila;
	fila.push({q*mul, sx, sy});
	cnt++;

	vis[sx][sy] = cnt;

	ll px, py, ld;

	while (!fila.empty()){
		tie(ld, px, py) = fila.front();
		fila.pop();

		noise[px][py] += ld;

		if (ld == 0)
			continue;

		fr(k, 4){
			int x = px + mx[k];
			int y = py + my[k];

			if (valid(x, y) and vis[x][y] < cnt){
				vis[x][y] = cnt;
				fila.push({ld/2, x, y});
			}
		}
	}
}


signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin>>n>>m>>q>>p;

	mapa.resize(n);

	fr(i, n)
		cin>>mapa[i];

	fr(i, n)
		fr(j, m)
			if ('A' <= mapa[i][j] and mapa[i][j] <= 'Z')
				bfs(i, j, mapa[i][j] - 'A' + 1);

	int ans = 0;
	fr(i, n)
		fr(j, m)
			if (noise[i][j] > p)
				ans++;		

	cout<<ans<<endl;		
}