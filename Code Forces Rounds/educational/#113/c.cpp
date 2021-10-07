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
const int MAXN = 5e5 + 10;
const ll mod = 998244353;

ll fat[MAXN];


ll fastxp(ll base, ll exp){
	ll ans = 1;
	while (exp){
		if (exp&1)
			ans = (ans * base)%mod;
		base = (base * base)%mod;
		exp >>=1;
	}

	return ans;
}

ll comb(ll a, ll b){
	if (b > a) return 0;

	ll ans = fastxp(fat[b], mod - 2);
	ans = (ans * fastxp(fat[a - b], mod - 2))%mod;
	return (ans * fat[a]) % mod;
}


void solve(){
	ll n;
	cin>>n;

	map<ll, ll> freq;
	set<ll> q;

	fr(i, n){
		ll x;
		cin>>x;
		freq[x]++;
		q.insert(x);
	}


	if (q.size() == 1){
		cout<<fat[n]<<endl;
		return;
	}

	ll mx1 = *q.rbegin();
	q.erase(*q.rbegin());

	ll mx2 = *q.rbegin();
	q.erase(*q.rbegin());

	if (freq[mx1] > 1){
		cout<<fat[n]<<endl;
		return;
	}

	if (mx2 + 1 < mx1){
		cout<<0<<endl;
		return;
	}

	ll a = freq[mx1];
	ll b = freq[mx2];
	ll c = n - a - b;

	ll ans = 0;
	for (ll i = a + b; i <= n; i++){
		ll val = comb(c, i - (a + b));
		ll aux = (fat[i - 1]*val) % mod;
		aux = (aux * b) % mod;
		aux = (aux * fat[n - i]) % mod;
		ans = (ans + aux) % mod;
	}

	cout<<ans<<endl;
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	fat[0] = 1;
	for (ll i = 1; i < MAXN; i++)
		fat[i] = (i * fat[i - 1]) % mod;

	int T;
	cin>>T;
	while (T--)
		solve();
}