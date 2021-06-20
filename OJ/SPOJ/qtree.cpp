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
 
#define endl '\n' 
#define gnl cout << endl
#define chapa cout << "oi meu chapa" << endl
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//cout << setprecision(9)<<fixed;
 
typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;
 
const int INF = 0x3f3f3f3f;
const int MAXN = 20010;
const ll mod=1e9+7;
const int LMAXN = 25;
 
typedef tuple<int, int, int> tup;
 
int n;
 
namespace seg {
	ll v[2 * MAXN];
 
	void build() {  // build the tree
		for (int i = n - 1; i > 0; --i) 
			v[i] = max(v[i<<1], v[i<<1|1]);
	}
 
	void update(int p, ll value) {  // set value at position p
		for (v[p += n] = value; p > 1; p >>= 1) 
			v[p>>1] = max(v[p], v[p^1]);
	}
 
	ll query(int l, int r) {  // sum on interval [l, r)
		ll res = -INF;
		for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
			if (l&1) res = max(res, v[l++]);
			if (r&1) res = max(res, v[--r]);
		}
		return res;
	}
};
 
tup edge[MAXN];
 
vector<int> adj[MAXN];
int pos[MAXN], sz[MAXN];
int pai[MAXN];
int h[MAXN], clk;
 
void dfs_hld(int k, int p = -1){
	sz[k] = 1;
	for (auto &i : adj[k]){
		if (i != p){
			dfs_hld(i, k);
			sz[k] += sz[i];
			if (sz[i] > sz[adj[k][0]] or adj[k][0] == p){ // fixing tree
				swap(i, adj[k][0]);
			}
		}
 
	}
}
 
void build_hld(int k, int p = -1){
	pos[k] = clk++;
	for (auto &i : adj[k])
		if (i != p){
			pai[i] = k;
			if (i == adj[k][0])
				h[i] = h[k];
			else
				h[i] = i;
			build_hld(i, k);
		}
}
 
void build(int r = 0){
	clk = 0;
	dfs_hld(r);
	build_hld(r);
}
 
ll query_path(int a, int b){
	if (pos[a] < pos[b])
		swap(a, b);
	if (h[a] == h[b])
		return seg::query(pos[b] + 1, pos[a] + 1); //pos[b] + 1
	return max(seg::query(pos[h[a]], pos[a] + 1), query_path(pai[h[a]], b));
}
 
void solve(){
	cin>>n;
	
	fr(i, n)
		adj[i].clear();
 
	ll a, b, x;
	fr(i, n - 1){
		cin>>a>>b>>x;
		a--; b--;
		adj[a].pb(b);
		adj[b].pb(a);
		edge[i] = {x, a, b};
	}
 
	fr(i, 2 * n + 10)
		seg::v[i] = -INF;
 
	build();
 
 
	ll c;
	fr(i, n - 1){
		a = get<1>(edge[i]); b = get<2>(edge[i]); c = get<0>(edge[i]);
		if (a == pai[b])
			seg::v[pos[b] + n] = c;
		else
			seg::v[pos[a] + n] = c;
	}
 
	seg::build();
 
 
	ll y;
	string s;
	cin>>s;
	while (s != "DONE"){
		cin>>a>>b;
		if (s == "CHANGE"){
			x = get<1>(edge[a - 1]);
			y = get<2>(edge[a - 1]);
			if (x == pai[y])
				seg::update(pos[y], b);
			else
				seg::update(pos[x], b);
		}
		else{
			a--;b--;
			cout<<query_path(a, b)<<endl;
		}
		cin>>s;
	}
 
}
 
int main(){
	fastio;
	int T;
	cin>>T;
	frr(i, T){
		solve();
	}
} 