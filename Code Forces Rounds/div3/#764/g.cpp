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

ll sz[MAXN], id[MAXN], ncmp;

ll find(ll a){
	if (a == id[a])
		return a;
	return id[a] = find(id[a]);
}

void merge(ll a, ll b){
	a = find(a);
	b = find(b);

	if (a == b)
		return;
	if (sz[a] < sz[b])
		swap(a, b);
	id[b] = a;
	sz[a] += sz[b];
	ncmp--;
}

int n, m;
vector<array<ll, 3>> edges;

void solve(){
	edges.clear();

	cin>>n>>m;

	fr(i,m){
		ll a, b, c;
		cin>>a>>b>>c;
		edges.pb({a, b, c});
	}

	ll ans = 0;
	for (int bit = 30; bit >= 0; bit--){
		frr(i, n){
			id[i] = i;
			sz[i] = 1;
		}
		ncmp = n;

		// try to make with no bit (bit) as a greedy
		ll allow = ans;
		allow += (1ll<<bit) - 1;

		for (auto x : edges)
			if ((x[2] & allow) == x[2]){ // I can use it!
				merge(x[0], x[1]);
			}

		if (ncmp != 1)	
			ans |= (1ll<<bit);
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