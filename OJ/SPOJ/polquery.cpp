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

vector<int> adj[MAXN], adj2[MAXN];
int pre[MAXN], pos[MAXN], lo[MAXN], pa[MAXN], cut[MAXN];
int clk, n, m;
map <pii, bool> bridge;

void dfsRbc( int v) {
	pre[v] = lo[v] = clk++;
	int chd = 0;
	bool any = false;

	for (int x : adj[v]) {
		if (pre[x] == -1) {
			pa[x] = v;
			dfsRbc(x);
			chd++;
			lo[v] = min( lo[v], lo[x]);
			if (lo[x] >= pre[v]){
				any = true;
				adj2[v].pb(x);
			}
			if (lo[x] > pre[v])
				bridge[{v,x}] = bridge[{x,v}] = true;
		}
		else if (x != pa[v])
			lo[v] = min( lo[v], pre[x]);
	}
	if (v == pa[v] and chd >= 2)
		cut[v] = true;
	if (v != pa[v] and any)
		cut[v] = true;
	pos[v] = clk++;
}

bool check_edj(int a, int b, int c, int d){
	if (pa[d] != c)
		swap(c, d);
	int dent = 0;

	if (pre[d] <= pre[a] and pos[a] <= pos[d])
		dent++;
	if (pre[d] <= pre[b] and pos[b] <= pos[d])
		dent++;
	if (dent%2)	
		return false;
	return true;
}

void findbc(){
	for (int i = 1; i <= n; i++)
		pre[i] = -1, cut[i] = 0;
	clk = 0;
	for (int i = 1; i <= n; i++)
		if (pre[i] == -1) {
			pa[i] = i;
			dfsRbc( i);
		}
}

int main(){
	scanf("%d %d", &n, &m);

	int a, b, c, g1, g2;
	
	fr(i, m){
		scanf("%d %d", &a, &b);
		adj[a].pb(b);
		adj[b].pb(a);
	}

	findbc();

	int q, ty;

	scanf("%d", &q);
	fr(i,q){
		scanf("%d", &ty);
		if (ty == 1){
			scanf("%d %d %d %d", &a, &b, &g1, &g2);
			if (!bridge.count({g1,g2}))
				printf("da\n");
			else{
				if (check_edj(a, b, g1, g2))
					printf("da\n");
				else
					printf("ne\n");
			}
		}

		else {
			scanf("%d %d %d", &a, &b, &c);
			if (!cut[c])
				printf("da\n");
			else {
				bool ok = 1;
				for (auto x : adj2[c])
					if (!check_edj(a, b, c, x))
						ok = 0;
				if (ok)
					printf("da\n");
				else
					printf("ne\n");				
			}

		}
	}		
}