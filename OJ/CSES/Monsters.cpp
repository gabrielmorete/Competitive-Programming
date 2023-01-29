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
const int MAXN = 1e3 + 10;

int n, m;
string mapa[MAXN];

int mx[4] = {1, -1, 0, 0};
int my[4] = {0, 0, 1, -1};
string ml = "DURL";

int dist1[MAXN][MAXN], dist2[MAXN][MAXN];


bool valid(int x, int y){
	return (0 <= x and x < n) and ( 0 <= y and y < m) and (mapa[x][y] != '#');
}

void bfs1(){
	queue<pii> fila;
	fr(i, n)
		fr(j, m){
			dist1[i][j] = -1;
			if (mapa[i][j] == 'M'){
				fila.push({i, j});
				dist1[i][j] = 0;
			}
		}

	int x, y;
	while (!fila.empty()){
		tie(x, y) = fila.front();
		fila.pop();

		fr(k, 4){
			int px = x + mx[k];
			int py = y + my[k];
			if (valid(px, py) and dist1[px][py] == -1){
				fila.push({px, py});
				dist1[px][py] = dist1[x][y] + 1;
			}
		}
	}
}

void bfs2(){
	queue<pii> fila;
	fr(i, n)
		fr(j, m){
			dist2[i][j] = -1;
			if (mapa[i][j] == 'A'){
				fila.push({i, j});
				dist2[i][j] = 0;
			}
		}

	int x, y;
	while (!fila.empty()){
		tie(x, y) = fila.front();
		fila.pop();

		fr(k, 4){
			int px = x + mx[k];
			int py = y + my[k];
			if (valid(px, py) and dist2[px][py] == -1){
				fila.push({px, py});
				dist2[px][py] = dist2[x][y] + 1;
			}
		}
	}
}

string ans;
void dfs(int x, int y){
	// cout<<x<<' '<<y<<endl;
	// dbg(dist1[x][y]);
	// dbg(dist2[x][y]);

	if ((x == 0 or x == n - 1) or (y == 0 or y == m - 1)){
		cout<<"YES"<<endl;
		cout<<ans.size()<<endl;
		cout<<ans<<endl;
		exit(0);
	}

	fr(k, 4){
		int px = x + mx[k];
		int py = y + my[k];
		if (valid(px, py) and dist2[px][py] < dist1[px][py] and dist2[px][py] == dist2[x][y] + 1){
			ans.pb(ml[k]);
			dfs(px, py);
			ans.pop_back();
		}
	}

	dist2[x][y] = INF;
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin>>n>>m;

	fr(i, n)
		cin>>mapa[i];

	bfs1();
	bfs2();


	fr(i, n)
		fr(j, m)
			if (dist1[i][j] == -1)
				dist1[i][j] = INF;


	fr(i, n)
		fr(j, m)
			if (mapa[i][j] == 'A')
				dfs(i, j);

	
	cout<<"NO"<<endl;
}