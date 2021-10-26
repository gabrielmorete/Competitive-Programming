#include "bits/stdc++.h"
using namespace std;

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

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
const int MAXN = 1e6 + 10;

int n, m, a[MAXN], b[MAXN], p[MAXN];

void solve(int l, int r, int ql, int qr){
	if (l > r) return;

	int mid = (l + r)/2;

	int low = 0;
	for (int i = ql; i < qr; i++)
		low += a[i] < b[mid];

	// se p igual a i entro entre i - 1 e i
	int bst = low, bstp = ql;

	int high = 0;
	for (int i = ql; i < qr; i++){
		low -= a[i] < b[mid];
		high += a[i] > b[mid];

		if (low + high < bst){
			bst = low + high;
			bstp = i + 1;
		}
	}
	p[mid] = bstp;
	solve(l, mid - 1, ql, bstp);
	solve(mid + 1, r, bstp, qr);
}

typedef tree<pii,null_type,less<pii>,rb_tree_tag,
tree_order_statistics_node_update> ordered_set;

void solve(){
	cin>>n>>m;

	frr(i, n)
		cin>>a[i];
	
	frr(i, m)
		cin>>b[i];	

	sort(b + 1, b + 1 + m);
	
	solve(1, m, 1, n + 1);	

	vi c;
	int q = 1;
	frr(i, n + 1){
		while (q <= m and p[q] == i)
			c.pb(b[q++]);
		if (i <= n)
			c.pb(a[i]);
	}

	ll ans = 0;
	ordered_set v;
	fr(i, c.size()){
		ll aux = v.size();
		aux -= v.order_of_key({c[i], i});
		ans += aux;
		v.insert({c[i], i});
	}

	cout<<ans<<endl;
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;

	while (T--)
		solve();
}