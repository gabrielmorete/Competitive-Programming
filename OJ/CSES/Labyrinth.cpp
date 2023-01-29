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
 
int mx[4] = {1, -1, 0, 0};
int my[4] = {0, 0, -1, 1};
string ml = "DULR";
 
int n, m;
string mapa[MAXN];
int dist[MAXN][MAXN];
 
 
bool valid(int x, int y){
	return (0 <= x and x < n) and (0 <= y and y < m) and mapa[x][y] != '#';
}
 
 
string s;
 
void dfs(int x, int y){
	if (mapa[x][y] == 'B'){
		cout<<"YES"<<endl;
		cout<<s.size()<<endl;
		cout<<s<<endl;
		exit(0);
	}
 
	fr(k, 4){
		int px = x + mx[k];
		int py = y + my[k];
 
		if (valid(px, py) and dist[px][py] == dist[x][y] + 1){
			s.pb(ml[k]);
			dfs(px, py);
			s.pop_back();
		}
	}

	dist[x][y] = -1;
}
 
void bfs(){
	queue<pair<int, int>> fila;
	
	fr(i, n)
		fr(j, m)
			dist[i][j] = -1;
 
	fr(i, n)
		fr(j, m)
			if (mapa[i][j] == 'A'){
				fila.push({i, j});
				dist[i][j] = 0;
			}
 
	int x, y;
	while (!fila.empty()){
		tie(x, y) = fila.front();
		fila.pop();
 
		fr(k, 4){
			int px = x + mx[k];
			int py = y + my[k];
 
			if (valid(px, py) and dist[px][py] == -1){
				dist[px][py] = dist[x][y] + 1;
				fila.push({px, py});
			}
		}
	}

}
 
 
signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin>>n>>m;
 
	fr(i, n)
		cin>>mapa[i];
 
	bfs();	
 
	fr(i, n)
		fr(j, m)
			if (mapa[i][j] == 'A')
				dfs(i, j);
			
	cout<<"NO"<<endl;		
}

