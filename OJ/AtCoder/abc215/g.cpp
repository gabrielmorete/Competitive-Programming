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
const ll mod = 998244353;

ll n, c[MAXN], cnt, freq[MAXN], freq2[MAXN];
ll fat[MAXN];

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
	if (b > a) return 0;
	
	ll ans = (fat[a] * fastxp(fat[b], mod - 2)) % mod;
	return (ans * fastxp(fat[a - b], mod - 2)) % mod;
}	


vii a;
map<int, int> crd;

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	fat[0] = 1;
	for (ll i = 1; i < MAXN; i++)
		fat[i] = (fat[i - 1] * i) % mod;


	cin>>n;

	frr(i, n){
		cin>>c[i];
		crd[c[i]];
	}

	cnt = 1;
	for (auto &it : crd)
		it.snd = cnt++;

	frr(i, n)
		c[i] = crd[c[i]];

	frr(i, n)
		freq[c[i]]++;
	frr(i, n)
		freq2[freq[i]]++;

	frr(i, n)
		if (freq2[i] > 0)	// no maximo sqrt(n)
			a.pb({i, freq2[i]}); // frequencia da cor, quantos tem essa frequencia

	frr(i, n){
		ll ans = 0;
		ll val = comb(n, i);
		for (auto x : a){
			ll aux = (val - comb(n - x.fst, i) + mod) % mod;
			aux = (((ll) x.snd)*aux) % mod;
			ans = (ans + aux) % mod;
		}

		ans = (ans * fastxp(val, mod - 2)) % mod;
		cout<<ans<<endl;
	}	
}