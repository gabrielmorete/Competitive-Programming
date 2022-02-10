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

int n, m, ans, tme[3], posx[3], posy[3], vis[10][10];
int mx[4] = {1, -1, 0, 0};
int my[4] = {0, 0, -1, 1};

inline bool valid(int x, int y){
	return (0 <= x and x < n) and (0 <= y and y < m);
}

bool check_cicle(int x, int y, int vx, int vy){ // Checa se eu não separei o grafo em 2
	int nx = vx + mx[vis[vx][vy]];
	int ny = vy + my[vis[vx][vy]];

	if (nx == x and ny == y) // meu pai, não conta
		return false;

	x += mx[vis[vx][vy]];
	y += my[vis[vx][vy]];
	if (valid(x, y) and vis[x][y] == -1)
		return true; // achei ciclo

	return false;
}

void backtrack(int px, int py, int t){
	if (px == 0 and py == 1){
		if (t == m * n)
			ans++;
		return;
	}

	fr(i, 3)
		if (t == tme[i] and ((posx[i] != px) or (posy[i] != py))) // tempo de visita
			return;	

	// Otimização das bordas
	if (px == 0)
		for (int j = py + 1; j < m; j++)
			if (vis[px][j] == -1)
				return;	

	if (px == n - 1)
		for (int j = 0; j < py; j++)
			if (vis[px][j] == -1)
				return;

	if (py == 0)
		for (int i = 0; i < px; i++)
			if (vis[i][py] == -1)
				return;

	if (py == m - 1)
		for (int i = px + 1; i < n; i++)
			if (vis[i][py] == -1)
				return;

	for (int k = 0; k < 4; k++){
		int x = px + mx[k];
		int y = py + my[k];

		if (valid(x, y)){
			if (vis[x][y] == -1){
				vis[px][py] = k;
				backtrack(x, y, t + 1);
				vis[px][py] = -1;
			}
			else if (check_cicle(px, py, x, y))
				return;
		}
	}		
}


signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int cnt = 1;

	while (cin>>n>>m and n > 0){
		fr(i, n)
			fr(j, m)
				vis[i][j] = -1;

		fr(i, 3)
			cin>>posx[i]>>posy[i];

		tme[0] = (m * n) / 4;
		tme[1] = (m * n) / 2;	
		tme[2] = (3 * m * n) / 4;

		vis[0][0] = 1; // subiu

		ans = 0;
		backtrack(1, 0, 2);

		cout<<"Case "<<cnt++<<": "<<ans<<endl;
	}
}