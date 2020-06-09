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

int mx[4] = {1, -1, 0, 0};
int my[4] = {0, 0, 1, -1};
int n, m;

bool valid(int x, int y){
	if (x < 0 or y < 0)
		return false;
	if (x >= n or y >= m)
		return false;
	return true;
}

int dist[200][200];

void solve(){
	cin>>n>>m;

	queue<pii> fila;

	string s;

	fr(i, n){
		cin>>s;
		fr(j, m){
			dist[i][j] = -1;

			if (s[j] == '1'){
				dist[i][j] = 0;
				fila.push({i, j});
			}
		}
	}

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
	
	fr(i, n){
		fr(j, m)
			cout<<dist[i][j]<<' ';
		gnl;	
	}
}

int32_t main(){
	fastio;
	int T;
	cin>>T;
	while (T--)
		solve();
}