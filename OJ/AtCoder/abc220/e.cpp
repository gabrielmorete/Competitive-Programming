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
const int MAXN = 1e6 + 10;
const ll mod = 998244353;


int calc[MAXN], pwr[MAXN];

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, d;

	cin>>n>>d;

	pwr[0] = 1;

	for (int i = 1; i < MAXN; i++)
		pwr[i] = (pwr[i - 1] * 2) % mod;
	
	for (int i = 1; i <= min(d, n) - 1; i++){
		int aux = d - i;

		if (aux >= n)
			continue;

		ll val = pwr[i - 1];
		val *= (ll) pwr[aux - 1];

		val %= mod;
		calc[i] = val;

		calc[i] = (2 * calc[i]) % mod;
	}

	if (d < n)
		calc[d] = pwr[d + 1];

	frr(i, n)
		calc[i] = (calc[i] + calc[i - 1]) % mod;
	
	ll ans = 0;

	for (int i = 0; i < n; i++){
		int dst = n - i - 1;
		int aux = min(d, dst);

		int mx = min(d, n - i - 1);
		int mn = max(0, d - (n - i));

		if (mn > mx) continue;

		ll sz = pwr[i];
		ll val = (calc[mx] - calc[mn] + mod) % mod;

		ll a = (sz * val) % mod;
		ans = (ans + a)%mod;
	}

	cout<<ans<<endl;
}