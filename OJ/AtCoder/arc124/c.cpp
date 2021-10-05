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
const int MAXN = 1e5 + 10;

typedef tuple<int, int, int> tup;

map<ll, ll> divi;

// O numero de divisores é por volta da raiz cubica do numero

void factor(ll n){
	for (ll i = 1; i * i <= n; i++)
		if (n % i == 0){
			divi[i];
			divi[n/i];
		}
} 

vector<ll> rdivi;
ll n, a[55], b[55];

map<tup, ll> memo;

ll pd(int p, int x, int y){
	if (p >= n)
		return (rdivi[x]*rdivi[y])/__gcd(rdivi[x], rdivi[y]);

	if (memo.count({p, x, y}))
		return memo[{p, x, y}];

	ll &pdm = memo[{p, x, y}];

	pdm = 1;

	ll l = rdivi[x];
	ll r = rdivi[y];

	pdm = max(pdm, pd(p + 1, divi[__gcd(l, a[p])], divi[__gcd(r, b[p])]));
	pdm = max(pdm, pd(p + 1, divi[__gcd(r, a[p])], divi[__gcd(l, b[p])]));

	return pdm;
}


signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin>>n;
	fr(i, n)
		cin>>a[i]>>b[i];

	factor(a[0]);
	factor(b[0]);

	ll cnt = 0;
	for (auto &e : divi){
		e.snd = cnt++;
		rdivi.pb(e.fst);
	}

	ll ans = pd(1, divi[a[0]], divi[b[0]]);

	cout<<ans<<endl;
}