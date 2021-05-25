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
const int MAXN = 5e2 + 10;

ll n, mod;

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

ll fat[MAXN], invmod[MAXN], pwr[MAXN], memo[MAXN][MAXN];

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin>>n>>mod;

	invmod[0] = fat[0] = pwr[0] = 1;
	for (ll i = 1; i < n + 10; i++){
		fat[i] = (fat[i - 1] * i) % mod;
		invmod[i] = fastxp(fat[i], mod - 2);
		pwr[i] = (pwr[i - 1]<<1ll) % mod;
	}

	memo[0][0] = 1; // memo[i][j] = #forma de ligar j computadores manualmente no prefixo i - 1

	for (ll i = 0; i < n; i++) // tamnho
		for (ll j = 0; j <= i; j++) // liguei manualmente
			for (ll k = 1; k + i <= n; k++){
				ll aux = (fat[j + k] * invmod[k]) % mod;
				aux = (aux * invmod[j]) % mod;
				aux = (aux * pwr[k - 1]) % mod;
				memo[i + k + 1][j + k] = (memo[i + k + 1][j + k] + memo[i][j] * aux) % mod; 
			}

	ll ans = 0;	
	for (int j = 0; j <= n; j++)
		ans = (ans + memo[n + 1][j]) % mod;

	cout<<ans<<endl;
}