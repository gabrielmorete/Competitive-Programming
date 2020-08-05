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
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
//cout << setprecision(9)<<fixed;

#define dbg(x)  cout << #x << " = " << x << endl
#define all(x)  x.begin(),x.end()

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

const int INF = 0x3f3f3f3f;
const ll llINF = (long long)(1e18) + 100;   
const int MAXN = 5e5 + 10;

const ll mod =  998244353;

ll fast_xp(ll base, ll exp){
	ll ans = 1;
	while (exp){
		if (exp & 1)
			ans = (ans * base) % mod;
		base = (base * base) % mod;
		exp >>= 1;
	}

	return ans;
}

ll invmod(ll val){
	return fast_xp(val, mod - 2);
}

ll fat[MAXN];
int32_t main(){
	fastio;
	ll n, k;
	cin>>n>>k;

	ll ans = 0;

	fat[0] = 1;
	for (ll i = 1; i < MAXN; i++)
		fat[i] = (fat[i - 1] * i) % mod;

	ll d, aux;
	for (ll x = 1; x <= n; x++){
		d = n/x;
		if (k - 1 > d - 1)
			continue;
		aux = (fat[d - 1] * invmod(fat[k - 1])) % mod;
		aux = (aux * invmod(fat[d - k])) % mod;
		ans = (ans + aux) % mod;
	}

	cout<<ans<<endl;
}