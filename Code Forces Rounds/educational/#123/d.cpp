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
const int MAXN = 4e5 + 10;
const ll mod = 998244353;

void solve(){
	ll n, m, k, q;
	vii v;
	cin>>n>>m>>k>>q;

	fr(i, q){
		int x, y;
		cin>>x>>y;
		v.pb({x, y});
	}

	reverse(all(v));

	set<int> lin, col;

	int in = 0;

	for (auto e : v){
		int x, y;
		tie(x, y) = e;

		if ((lin.size() == n) or (col.size() == m)) // no white cell
			continue;

		if ((lin.count(x) > 0) and (col.count(y) > 0)) // got column and row
			continue;

		in++;

		lin.insert(x);
		col.insert(y);
	}

	ll ans = 1;

	fr(i, in){
		ans = (ans * k) % mod;
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