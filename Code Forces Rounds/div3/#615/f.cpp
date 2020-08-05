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
const ll mod=1e9+7;

int n, la, lb;
vi adj[MAXN];

int vtx, dist;

void dfs1(int v, int p, int dst){
	if (dst >= dist){
		vtx = v;
		dist = dst;
	}

	for (int x : adj[v])
		if (x != p)
			dfs1(x, v, dst + 1);
}

bool dfs2(int v, int p){
	if (v == lb){
		for (int x : adj[v])
			if (x != p)
				dfs1(x, v, 1);
		return true;
	}

	bool ok = 0;
	for (int x : adj[v]){
		if (x != p){
			ok = dfs2(x, v);
			if (ok){
				for (auto y : adj[v]){
					if (y != x and y != p)
						dfs1(y, v, 1);
				}

				if (vtx == 0 and v != la){ // Caso que é um caminho
					vtx = v;
				}

				return true;
			}
		}
	}

	return false;
}	


int32_t main(){
	fastio;
	cin>>n;

	int a, b;
	fr(i, n - 1){
		cin>>a>>b;
		adj[a].pb(b);
		adj[b].pb(a);
	}

	if (n == 3){
		cout<<n - 1<<endl;
		cout<<1<<' '<<2<<' '<<3<<endl;
		return 0;
	}

	dfs1(1, 1, 0);
	la = vtx;

	vtx = dist = 0;
	dfs1(la, la, 0);

	lb = vtx;
	int ans = dist;

	vtx = dist = 0;
	dfs2(la, la);

	cout<<ans + dist<<endl;
	cout<<la<<' '<<lb<<' '<<vtx<<endl;
}