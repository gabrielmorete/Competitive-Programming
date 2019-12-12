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
int pre[21234], lo[21234], pa[21234], stk[21234], bcc[21234];
int n, m;
int sn, clk, id;

void dfsRebcc( int v){
	pre[v] = clk++;
	stk[sn++] = v;
	lo[v] = pre[v];
	for (int x : adj[v]){
		if (pre[x] == -1){
			pa[x] = v;
			dfsRebcc( x);
			lo[v] = min( lo[v], lo[x]);
		}
		else if (x != pa[v])
			lo[v] = min( lo[v], pre[x]);
	}
	if (lo[v] == pre[v]){
		int u;
		do {
			u = stk[--sn];
			bcc[u] = id;
		} while (u != v);
		id++;
	}
}

int ebcc(){
	frr(i,n)
		pre[i] = -1;
	sn = clk = id = 0;
	frr(i, n)
		if (pre[i] == -1){
			pa[i] = i;
			dfsRebcc( i);
		}
	return id;		
}
int main(){
	fastio;

	cin>>n>>m;
	while (n != 0){
		frr(i, n)
			adj[i].clear();
		
		int a, b;
		fr(i,m){
			cin>>a>>b;
			adj[a].pb(b);
			adj[b].pb(a);
		}

		ebcc();	

		if (id == 1)
			cout<<"S"<<endl;
		else
			cout<<"N"<<endl;

		cin>>n>>m;
	}

}