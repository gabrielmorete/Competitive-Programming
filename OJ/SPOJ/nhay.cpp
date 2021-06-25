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

typedef long long int ll;

const ll mod1 = 1000015553; // primo grande 1
const ll mod2 = 1000028537; // primo grande 2
// const ll mod3 = 1000041323; // primo grande 3 coisa ta feia

mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count()); // Gerador aleatório
static ll p = uniform_int_distribution<int>(27, mod1 - 1)(rng);	// Caso TL usa const p

struct str_hash{
	string s;
	ll n;
	vector<ll> hsh1, pwr1, hsh2, pwr2;

	str_hash(string _s) : n(_s.size()), s(_s), hsh1(n), pwr1(n), hsh2(n), pwr2(n){	
		pwr1[0] = pwr2[0] = 1;
		for (int i = 1; i < n; i++){
			pwr1[i] = (p * pwr1[i - 1]) % mod1;
			pwr2[i] = (p * pwr2[i - 1]) % mod2;
		}
		hsh1[0] = hsh2[0] = s[0];
		for (int i = 1; i < n; i++){
			hsh1[i] = (hsh1[i - 1] * p + (ll)(s[i]))%mod1;
			hsh2[i] = (hsh2[i - 1] * p + (ll)(s[i]))%mod2;
		}
	}
	pair<ll, ll> operator()(int i, int j){ // hash no intervalo [i, j]
		if (i == 0) return {hsh1[j], hsh2[j]};
		ll ret1 = ((hsh1[j] - (hsh1[i - 1] * pwr1[j - i + 1])) % mod1 + mod1) % mod1;
		ll ret2 = ((hsh2[j] - (hsh2[i - 1] * pwr2[j - i + 1])) % mod2 + mod2) % mod2;
		return {ret1, ret2}; // Possivelmente pode retornar o xor tbm
	}
};

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n;
	string s, t;
	bool ok = 0;
	while (cin>>n){
		if (ok) gnl;
		cin>>s>>t;

		str_hash h1 = str_hash(s);
		str_hash h2 = str_hash(t);

		for (int i = 0; i + n <= t.size(); i++)
			if (h1(0, n - 1) == h2(i, i + n - 1))
				cout<<i<<endl;
		
		ok = 1;	
	}	
}