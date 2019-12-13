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
const int MAXN = 1010;
const int MAXM = 1001000;
const ll mod=1e9+7;
const int LMAXN = 25;

vi adj[1010];
int pre[MAXN], lo[MAXN], pa[MAXN];
int clk, n, m;
int vis[1010], visa[1010][1010];


void dfsRbc( int v) {
	pre[v] = lo[v] = clk++;

	for (int x : adj[v]) {
		if (pre[x] == -1) {
			pa[x] = v;
			dfsRbc(x);
			lo[v] = min( lo[v], lo[x]);
			if (lo[x] > pre[v])
				visa[x][v] = visa[v][x] = 2;
		}
		else if (x != pa[v])
			lo[v] = min( lo[v], pre[x]);
	}
}

void findbc(){
	for (int i = 1; i <= n; i++)
		pre[i] = -1;
	clk = 0;
	for (int i = 1; i <= n; i++)
		if (pre[i] == -1) {
			pa[i] = i;
			dfsRbc( i);
		}
}

void dfs( int v){
	vis[v] = 1;
	for (auto x : adj[v]){
		if (visa[v][x] != 0)
			continue;
		visa[v][x] = 1;
		visa[x][v] = -1;
		dfs( x);
	}
}

int main(){
	fastio;
	cin>>n>>m;
	int tst = 1;
	while (n != 0){
		frr(i,n){
			adj[i].clear();
			vis[i] = 0;
			frr(j,n)
				visa[i][j] = 0;
		}
		int a, b;
		fr(i,m){
			cin>>a>>b;
			adj[a].pb(b);
			adj[b].pb(a);
		}

		findbc();

		frr(i,n){
			if (!vis[i])
				dfs(i);
		}
		
		cout<<tst++<<endl<<endl;
		frr(v,n)
			for (auto x : adj[v])
				if (visa[x][v] > 0)
					cout<<x<<' '<<v<<endl;	
		cout<<"#"<<endl;
		cin>>n>>m;
	}
}