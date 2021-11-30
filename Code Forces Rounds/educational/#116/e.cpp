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

ll memo[510][510], fat[MAXN];

ll choose(ll a, ll b){
	if (a < b)
		return 0;

	ll aux = fat[a];
	aux = (aux * fastxp(fat[b], mod - 2)) % mod;
	aux = (aux * fastxp(fat[a - b], mod - 2)) % mod;

	return aux;
}


ll solve(ll n, ll x){
	if (n == 0) //moreu geral
		return 1;

	if (n == 1) // sobrou 1
		return 0;

	if (x < n)
		return fastxp(x, n);

	ll &pdm = memo[n][x];

	if (pdm != -1)
		return pdm;

	pdm = 0;
	ll pos = 1;

	for (int i = 0; i <= n; i++){
		ll aux = (pos * choose(n, i)) % mod;
		aux = (aux * solve(n - i, x - n + 1)) % mod;
		pos = (pos * (n - 1)) % mod;
		pdm = (pdm + aux) % mod;
	}

	return pdm;
}



signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	ll n, x;

	cin>>n>>x;

	fat[0] = 1;
	frr(i, n)
		fat[i] = ((ll)(i) * fat[i - 1]) % mod;

	memset(memo, -1, sizeof memo);
	cout<<solve(n, x)<<endl;
}