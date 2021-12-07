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

int mx[4] = {1, -1, 0, 0};
int my[4] = {0, 0, 1, -1};

int n, m, lx, ly;
vector<string> mapa;	


bool valid(int x, int y){
	if (x < 0 or y < 0)
		return false;
	if (x >= n or y >= m)
		return false;

	return mapa[x][y] != '#';
}

void solve(){
	cin>>n>>m;

	mapa.resize(n);
	fr(i, n)
		cin>>mapa[i];

	fr(i, n)
		fr(j, m)
			if (mapa[i][j] == 'L'){
				lx = i;
				ly = j;
			}

	vii viz;
	queue<pii> fila;

	fr(k, 4)
		if (valid(lx + mx[k], ly + my[k]))
			viz.pb({lx + mx[k], ly + my[k]});

	for (auto e : viz){
		int x, y;
		tie(x, y) = e;

		int nfree = 0;

		fr(k, 4)
			if (valid(x + mx[k], y + my[k]) and mapa[x + mx[k]][y + my[k]] == '.')
				nfree++;

		if (nfree <= 1){
			mapa[x][y] = '+';

			fr(k, 4)
				if (valid(x + mx[k], y + my[k]) and mapa[x + mx[k]][y + my[k]] == '.')
					fila.push({x + mx[k], y + my[k]});
		}

	}	

	int x, y;
	while (!fila.empty()){
		tie(x, y) = fila.front();
		fila.pop();

		if (mapa[x][y] != '.')
			continue;

		int nfree = 0;
		fr(k, 4)
			if (valid(x + mx[k], y + my[k]) and mapa[x + mx[k]][y + my[k]] == '.')
				nfree++;
	
		if (nfree <= 1){
			mapa[x][y] = '+';

			fr(k, 4)
				if (valid(x + mx[k], y + my[k]) and mapa[x + mx[k]][y + my[k]] == '.')
					fila.push({x + mx[k], y + my[k]});
		}	
	}		

	fr(i, n)
		cout<<mapa[i]<<endl;
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;
	while (T--)
		solve();
}