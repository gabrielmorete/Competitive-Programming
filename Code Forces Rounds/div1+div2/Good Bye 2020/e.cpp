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
#define all(x)  x.begin(),x.end()

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

const int INF = 0x3f3f3f3f;
const ll llINF = (long long)(1e18) + 100;   
const int MAXN = 5e5 + 10;

const ll mod = 1e9 + 7;

ll n, v[MAXN], freq[64], comp[MAXN];

void solve(){
	memset(freq, 0, sizeof freq);

	cin>>n;
	fr(i, n)
		cin>>v[i];

	for (int i = 0; i < n; i++){
		for (ll j = 0; j < 61; j++)
			if ((1ll << j) & v[i])
				freq[j]++;
	}

	for (int i = 0; i < n; i++){
		comp[i] = 0;
		for (ll j = 0; j < 61; j++)
			if ((1ll << j) & v[i]){
				ll aux = (1ll << j) % mod;
				aux = ((n - freq[j]) * aux) % mod;
				comp[i] = (comp[i] + aux) % mod;
			}
	}

	ll sum = 0;
	for (ll j = 0; j < 61; j++){
		ll aux = (1ll << j) % mod;
		aux = (freq[j] * aux) % mod;
		sum = (sum + aux) % mod;
	}

	ll ans = 0;

	for (int i = 0; i < n; i++){
		for (ll j = 0; j < 61; j++)
			if ((1ll << j) & v[i]){
				ll aux = (1ll << j) % mod;
				aux = (freq[j] * aux) % mod;

				ll aux2 = (sum + comp[i]) % mod;

				aux = (aux * aux2) % mod;
			
				ans = (ans + aux) % mod;
			}
	}

	cout<<ans<<endl;
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;

	while (T--)
		solve();
}