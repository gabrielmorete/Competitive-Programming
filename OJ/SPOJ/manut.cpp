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

vector<int> adj[MAXN];
int pre[MAXN], lo[MAXN], pa[MAXN], cut[MAXN];
int cnt, n, m;
map <pii, bool> bridge;

void dfsRbc( int v) {
	pre[v] = lo[v] = cnt++;
	int chd = 0;
	bool any = false;

	for (int x : adj[v]) {
		if (pre[x] == -1) {
			pa[x] = v;
			dfsRbc(x);
			chd++;
			lo[v] = min( lo[v], lo[x]);
			if (lo[x] >= pre[v])
				any = true;
			if (lo[x] > pre[v])
				bridge[{v,x}] = true;
		}
		else if (x != pa[v])
			lo[v] = min( lo[v], pre[x]);
	}
	if (v == pa[v] and chd >= 2)
		cut[v] = true;
	if (v != pa[v] and any)
		cut[v] = true;
}

void findbc(){
	for (int i = 1; i <= n; i++)
		pre[i] = -1;
	for (int i = 1; i <= n; i++)
		if (pre[i] == -1) {
			pa[i] = i;
			dfsRbc( i);
		}
}

int main(){
	fastio;
	int tst = 1, t;
	cin>>n>>m;
	while (n != 0) {
		frr(i,n){
			adj[i].clear();
			cut[i] = false;
		}
		int a, b;
		fr(i,m){
			cin>>a>>b;
			adj[a].pb(b);
			adj[b].pb(a);
		}

		findbc();

		cout<<"Teste "<<tst++<<endl;
		t = 0;
		frr(i,n)
			if(cut[i]){
				cout<<i<<' ';	
				t++;
			}
		if (t == 0)
			cout<<"nenhum";
		gnl;		

		cin>>n>>m;
		if (n != 0)
			gnl;
	}
}