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
const int MAXN = 4e3 + 10;

int mx[4] = {1, -1, 0, 0};
int my[4] = {0, 0, -1, 1};

int n, m;
string mapa[MAXN];
bool vis[MAXN][MAXN];

bool valid(int x, int y){
	return (0 <= x and x < n) and (0 <= y and y < m) and mapa[x][y] == '.';
}


void dfs(int x, int y){
	vis[x][y] = 1;

	fr(k, 4){
		int px = x + mx[k];
		int py = y + my[k];

		if (valid(px, py) and !vis[px][py])
			dfs(px, py);
	}
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin>>n>>m;

	fr(i, n)
		cin>>mapa[i];

	int ans = 0;	
	fr(i, n)
		fr(j, m)
			if (valid(i, j) and vis[i][j] == 0){	
				dfs(i, j);
				ans++;
			}

	cout<<ans<<endl;		
}