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


set< pair<ll, ll> > q;

ll n, m, a[MAXN];

void solve(){
	q.clear();

	cin>>n>>m;

	ll s = 0, mx = 0;
	fr(i, n){
		cin>>a[i];
		s += a[i];
		mx = max(s, mx);
		if (q.lower_bound({s, -1}) == q.end())
			q.insert({s, i});
	}

	ll x;
	while (m--){
		cin>>x;

		if (x > mx and s <= 0){
			cout<<"-1 ";
			continue;
		}

		ll ans = 0;
		if (x > mx){
			ans += n * ((x - mx + s - 1)/s); // voltas
			x -= s * ((x - mx + s - 1)/s);
		}

		auto it = q.lower_bound({x, -1});
		ans += (*it).snd;
		cout<<ans<<' ';
	}
	gnl;
}


int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;
	while (T--)
		solve();
}