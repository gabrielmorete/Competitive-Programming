#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i,n)     for(int i=0;i<n;i++)
#define frr(i,n)    for(int i=1;i<=n;i++)

#define ms(x,i) memset(x,i,sizeof(x))
#define dbg(x)  cout << #x << " = " << x << endl
#define all(x)  x.begin(),x.end()

#define gnl cout << endl
#define chapa cout << "oi meu chapa" << endl
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
//cout << setprecision(9)<<fixed;

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = (long long)(1e18) + 100;   
const int MAXN = 100100;
const int MAXM = 1001000;
const ll mod=1e9+7;
const int LMAXN = 25;

int mx[4] = {-1, 1, 0, 0};
int my[4] = {0, 0, 1, -1};

int mapa[1123][1123];
bool vis[1123][1123];


int n, m;
bool valid(int x, int y){
	if (x < 0 or y < 0)
		return false;
	if (x >= n or y >= m)
		return false;
	if (vis[x][y] or !mapa[x][y])
		return false;
	return true;
}

void dfs(int x, int y){
	vis[x][y] = 1;
	fr(k, 4){
		if (valid(x + mx[k], y + my[k]))
			dfs(x + mx[k], y + my[k]);
	}
}

int main(){
	fastio;
	cin>>n>>m;

	string s;
	fr(i,n){
		cin>>s;
		fr(j, m)
			mapa[i][j] = (s[j] == '#')? 1 : 0;
	}

	bool lb, cb, ok;
	int aux;

	ok = 1;
	lb = cb = 0;

	fr(i, n){
		aux = 0;
		fr(j, m){
			if (j == 0){
				aux += mapa[i][j];
			}
			else if (mapa[i][j] == 1 and mapa[i][j - 1] == 0)
				aux++;
		}
		if (aux > 1)
			ok = 0;
		if (aux == 0)
			lb = 1;
	}

	fr(j, m){
		aux = 0;
		fr(i, n){
			if (i == 0){
				aux += mapa[i][j];
			}
			else if (mapa[i][j] == 1 and mapa[i - 1][j] == 0)
				aux++;
		}
		if (aux > 1)
			ok = 0;
		if (aux == 0)
			cb = 1;
	}

	if (!ok or (lb ^ cb)){
		cout<<-1<<endl;
		return 0;
	}

	int ans = 0;
	fr(i, n)
		fr(j, m){
			if (mapa[i][j] == 1 and vis[i][j] == 0){
				ans++;
				dfs(i, j);
			}
		}
	cout<<ans<<endl;	
}