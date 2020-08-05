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
const int MAXN = 2e5 + 10;
const ll mod = 1e9+7;

int n, b[MAXN], c[MAXN];
ll cst[MAXN];
vi adj[MAXN];

int memo[MAXN][4]; // hb hw wb ww

ll tot;

void dfs(int v, int p, ll mincst){

	for (auto x : adj[v]){
		if (x != p){
			dfs(x, v, min(mincst, cst[v]));
			memo[v][0] += memo[x][0];
			memo[v][1] += memo[x][1];
			memo[v][2] += memo[x][2];
			memo[v][3] += memo[x][3];
		}
	}

	if (b[v] != c[v]){
		memo[v][b[v]]++;
		memo[v][c[v] + 2]++;
	}

	if (cst[v] < mincst){
		ll bb = min(memo[v][0], memo[v][2]);
		ll ww = min(memo[v][1], memo[v][3]);
		memo[v][0] -= bb;
		memo[v][2] -= bb;
		memo[v][1] -= ww;
		memo[v][3] -= ww;
		
		tot += (bb + ww)*cst[v];
	}
}

int32_t main(){
	fastio;
	cin>>n;

	int wb, hb;
	wb = hb = 0;

	frr(i, n){
		cin>>cst[i]>>b[i]>>c[i];
		
		if (b[i] == 0)
			wb++;
		if (c[i] == 0)
			hb++;
	}

	int x, y;
	fr(i, n - 1){
		cin>>x>>y;
		adj[x].pb(y);
		adj[y].pb(x);
	}

	if (wb != hb){
		cout<<-1<<endl;
		return 0;
	}

	dfs(1, 1, llINF);

	cout<<tot<<endl;

}