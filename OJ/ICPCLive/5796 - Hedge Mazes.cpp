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

vi adj[21234];
map<pii,bool> ponte;
int pre[21234], lo[21234], pa[21234];
int n, m;
int sn, clk, id;

int vis[21234];
void dfs(int v, int cp){
	vis[v] = cp;
	for (int x : adj[v]){
		if (vis[x])
			continue;
		if (ponte.count({v,x}))
			dfs(x, cp);
	}
}

void dfsRb( int v){
	pre[v] = lo[v] = clk++;
	for (int x : adj[v]){
		if (pre[x] == -1 ){
			pa[x] = v;
			dfsRb( x);
			lo[v] = min( lo[v], lo[x]);
			if (lo[x] > pre[v])
				ponte[{x,v}] = ponte[{v,x}] = true;
		}
		else if (x != pa[v])
			lo[v] = min( lo[v], pre[x]);
	}
}

void findbc(){
	frr(i,n)
		pre[i] = -1;
	clk = 0;
	frr(i, n)
		if (pre[i] == -1){
			pa[i] = i;
			dfsRb( i);
		}
}
int main(){
	fastio;
	int q;
	cin>>n>>m>>q;
	while (n != 0){
		ponte.clear();
		frr(i, n){
			adj[i].clear();
			vis[i] = 0;
		}
		
		int a, b;
		fr(i,m){
			cin>>a>>b;
			adj[a].pb(b);
			adj[b].pb(a);
		}

		findbc();	

		int cp = 1;
		frr(i,n)
			if (!vis[i])
				dfs(i, cp++);

		fr(i,q){
			cin>>a>>b;
			if (vis[a] == vis[b])
				cout<<"Y"<<endl;
			else
				cout<<"N"<<endl;
		}

		cout<<'-'<<endl;
		cin>>n>>m>>q;
	}

}