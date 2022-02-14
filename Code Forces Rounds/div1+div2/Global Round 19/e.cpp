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

int n, m;
map<int, int> frq;
set<pii> bad;
vector<ll> v[MAXN];

void solve(){
	bad.clear();
	frq.clear();

	cin>>n>>m;

	fr(i, n + 10)
		v[i].clear();


	fr(i, n){
		int x;
		cin>>x;
		frq[x]++;
	}

	fr(i, m){
		int x, y;
		cin>>x>>y;
		bad.insert({x, y});
		bad.insert({y, x}); // bad pairs
	}

	for (auto e : frq)
		v[e.snd].pb(e.fst);

	fr(i, n + 10)
		reverse(all(v[i])); // decrescente

	ll ans = 0;
	
	for (auto e : frq){
		ll x = e.fst;
		ll f = e.snd;

		for (ll i = 0; i <= f; i++)
			for (auto j : v[i]){
				if (bad.count({x, j}) or j == x)
					continue;

				ans = max(ans, (x + j) * (f + i));

				break;
			}
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