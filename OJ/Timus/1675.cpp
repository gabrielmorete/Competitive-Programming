#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fst first
#define snd second

#define fr(i,n)     for (int i = 0; i < n; i++)
#define frr(i,n)    for (int i = 1; i <= n; i++)

#define gnl cout << endl
#define chapa cout << "oi meu chapa" << endl

#define dbg(x)  cout << #x << " = " << x << endl
#define all(x)  x.begin(),x.end()

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

const int INF = 0x3f3f3f3f;
const ll llINF = (long long)(1e18) + 100;   
const int MAXN = 1e5 + 10;

const ll mod = 1e9 + 7;

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

ll invmod(ll base){
	return fastxp(base, mod - 2);
}

ll fat[MAXN], pwr[MAXN];

ll choose(ll a, ll b){
	return (fat[a] * invmod( (fat[a - b] * fat[b]) % mod)) % mod;
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	fat[0] = 1;
	frr(i, MAXN - 1)
		fat[i] = (((ll)i) * fat[i - 1]) % mod;

	pwr[0] = 1;
	frr(i, MAXN - 1)
		pwr[i] = (2 * pwr[i - 1]) % mod;	

	ll n, m, k, l;
	
	cin>>n>>m>>k>>l;
	
	// n, k - row
	// m, l - column

	ll mpl = (choose(n, k) * choose(m, l)) % mod;

	k = n - k; // non-zero
	l = m - l;

	ll ans = 0, s = 1, aux;
	for (int i = 1; i <= l; i++){
		aux = (choose(l, i) * fastxp(pwr[l - i] - 1, k)) % mod;
		aux = ((s * aux) + mod) % mod;
		ans = (ans + aux) % mod;
		s *= -1;
	}

	ans = (fastxp(pwr[l] - 1, k) - ans + mod) % mod;

	cout<<(mpl * ans) % mod<<endl;
}