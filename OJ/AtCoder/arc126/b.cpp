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
const int MAXN = 2e5 + 10;

int n, m;
vi adj[MAXN];

int seg[4 * MAXN];

void update(int node, int l, int r, int pos, int val){
	if (pos < l or r < pos)
		return;
	
	if (l == r){
		seg[node] = max(seg[node], val);
		return;
	}

	int m = (l + r)/2;

	update(node<<1, l, m, pos, val);
	update(node<<1|1, m + 1, r, pos, val);

	seg[node] = max(seg[node<<1], seg[node<<1|1]);
}

int query(int node, int l, int r, int ql, int qr){
	if (qr < l or r < ql)
		return 0;
	if (ql <= l and r <= qr)
		return seg[node];

	int m = (l + r)/2;
	return max(query(node<<1, l, m, ql, qr), query(node<<1|1, m + 1, r, ql, qr));
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin>>n>>m;

	int a, b;
	fr(i, m){
		cin>>a>>b;
		adj[a].pb(b);
	}

	for (int i = 1; i <= n; i++){
		sort(all(adj[i]));
		reverse(all(adj[i]));

		for (auto x : adj[i]){
			int val = query(1, 1, n, 1, x - 1);
			update(1, 1, n, x, val + 1);
		}
	}

	int ans = query(1, 1, n, 1, n);

	cout<<ans<<endl;
}