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
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
//cout << setprecision(9)<<fixed;

#define dbg(x)  cout << #x << " = " << x << endl
#define all(x)  x.begin(),x.end()

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

const int INF = 0x3f3f3f3f;
const ll llINF = (long long)(1e18) + 100;   
const int MAXN = 1e5 + 10;
const ll mod = 1e9 + 7;

int n, m;
char mapa[55][55];

int mx[4] = {-1, 1, 0, 0};
int my[4] = {0, 0, 1, -1};

bool valid(int x, int y){
	if (x < 0 or y < 0)
		return false;
	if (x >= n or y >= m)
		return false;
	return mapa[x][y] != '#';
}

int dist[55][55];
void bfs(){
	fr(i, n)
		fr(j, m)
			dist[i][j] = -1;
	
	queue< pii > fila;
	fila.push({n - 1, m - 1});
	dist[n - 1][m - 1] = 0;

	int x, y;
	pii aux;
	while (!fila.empty()){
		aux = fila.front();
		fila.pop();
		
		fr(k, 4){
			x = aux.fst + mx[k]; 
			y = aux.snd + my[k];
			if (valid(x, y) and dist[x][y] == -1){
				dist[x][y] = dist[aux.fst][aux.snd] + 1;
				fila.push({x, y});
			}				
		}
	}		
}

void solve(){
	cin>>n>>m;
	int g = 0;

	fr(i, n)
		fr(j, m){
			cin>>mapa[i][j];
			if (mapa[i][j] == 'G')
				g++;
		}
	if (g == 0){
		cout<<"yes"<<endl;
		return;
	}

	int x, y;
	// colocar paredes ao redor
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++){
			if (mapa[i][j] == 'B'){
				fr(k, 4){
					x = i + mx[k]; 
					y = j + my[k];
					if (valid(x, y) and mapa[x][y] == '.')
						mapa[x][y] = '#';
				}
			}
		}

	bfs();
	
	bool ok = 1;
	fr(i, n)
		fr(j, m){
			if (mapa[i][j] == 'G' and dist[i][j] == -1)
				ok = 0;	
			if (mapa[i][j] == 'B' and dist[i][j] != -1)
				ok = 0;
		}
	if (ok)
		cout<<"yes"<<endl;
	else
		cout<<"no"<<endl;		
}

int32_t main(){
	fastio;
	int T;
	cin>>T;
	while (T--)
		solve();
}