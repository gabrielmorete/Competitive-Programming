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

typedef tuple<ll, ll, ll> tup;

map<tup, ll> memo;

ll pd(ll a, ll b, ll c){
	if (memo.count({a, b, c}))
		return memo[{a, b, c}];	

	ll pdm = 0;

	if (a > 0 and b > 1){
		ll val = min(a, b/2);
		pdm = val + pd(a - val, b - 2* val, c);
	
	}

	if (a > 2 and b > 0){
		ll val = min(a/3, b);
		pdm = max(pdm, val + pd(a - 3*val, b - val, c));
	}


	if (b > 0 and c > 0){
		ll val = min(b, c);
		pdm = max(pdm, val + pd(a, b - val, c - val));
	}
	if (a > 1 and c > 0){
		ll val = min(a/2, c);
		pdm = max(pdm, val + pd(a - 2*val, b, c - val));
	}
	if (a > 4){	
		ll val = a/5;
		pdm = max(pdm, val + pd(a - 5*val, b, c));
	}

	memo[{a, b, c}] = pdm;
	return pdm;
}


signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;
	while (T--){
		ll a, c, b;

		cin>>a>>c>>b;

		c /= 2;

		memo.clear();
		ll ans = pd(a, b, c);

		cout<<ans<<endl;
	}
}