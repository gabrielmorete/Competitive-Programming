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

ll n, k, inv[MAXN], a[MAXN];

ll fastxp(ll base, ll exp){
	ll ans = 1;
	while (exp){
		if (exp & 1)
			ans = (ans * base) % mod;

		base = (base * base) % mod;

		exp >>= 1;
	}

	return ans;
}

ll comb(ll a, ll b){
	if (a < b)
		return 0;

	ll ans = 1;
	frr(i, b)
		ans = (ans * inv[i]) % mod;

	for (ll i = a; i > a - b; i--)	
		ans = (ans * i) % mod;

	return ans;
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	fr(i, 400)	
		inv[i] = fastxp(i, mod - 2);

	cin>>n>>k;

	frr(i, n)
		cin>>a[i];

	for (int i = 2; i <= n; i++)
		a[1] -= a[i];

	a[1] -= k;// coloca	uma bola em cada caixa

	if (a[1] < 0){
		cout<<0<<endl;
		return 0;
	}

	ll ans = 1;
	frr(i, n)
		ans = (	ans * comb(a[i] + k - 1, k - 1)) % mod; // weak combination, some boxes may be empty, stars and bars	

	cout<<ans<<endl;
}