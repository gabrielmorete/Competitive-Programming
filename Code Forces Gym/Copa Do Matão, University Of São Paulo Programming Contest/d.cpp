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

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

const ll mod1 = 1000015553; // primo grande 1
const ll mod2 = 1000028537; // primo grande 2
// const ll mod3 = 1000041323; // primo grande 3, coisa ta feia

// primos pequenos : 50331653, 12582917, 6291469, 3145739, 1572869.

mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count()); // Gerador aleatório
static ll p = uniform_int_distribution<int>(27, mod1 - 1)(rng);	// Caso TL usa const p
// Lembre que (alfabeto < p < mod)

struct str_hash{
	string s; // Se tem elemento zero, o hash é nulo hash(0) = hash(000...000), pode usar 'a' = 1
	ll n;
	vector<ll> hsh1, pwr1, hsh2, pwr2;

	str_hash(string _s) : n(_s.size()), s(_s), hsh1(n), pwr1(n), hsh2(n), pwr2(n){	
		pwr1[0] = pwr2[0] = 1;
		for (int i = 1; i < n; i++){
			pwr1[i] = (p * pwr1[i - 1]) % mod1;
			pwr2[i] = (p * pwr2[i - 1]) % mod2;
		}
		hsh1[0] = hsh2[0] = s[0] - 'a';
		for (int i = 1; i < n; i++){
			hsh1[i] = (hsh1[i - 1] * p + (ll)(s[i] - 'a'))%mod1;
			hsh2[i] = (hsh2[i - 1] * p + (ll)(s[i] - 'a'))%mod2;
		}
	}
	ll operator()(int i, int j){ // hash no intervalo [i, j], indexado de zero
		if (i == 0) return hsh1[j] ^ (hsh2[j]<<29);
		ll ret1 = ((hsh1[j] - (hsh1[i - 1] * pwr1[j - i + 1])) % mod1 + mod1) % mod1;
		ll ret2 = ((hsh2[j] - (hsh2[i - 1] * pwr2[j - i + 1])) % mod2 + mod2) % mod2;
		return ret1 ^ (ret2<<29);
	}
};

string s;
int n;

str_hash hsh("str");

ll solve(int tam){
	bool ok = 1;
	ll val = hsh(0, tam - 1);

	for (int j = 0; j < n; j += tam)
		if (hsh(j, j + tam - 1) != val)
			return 0;

	return n;	
}


signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin>>s;
	n = s.size();
	hsh = str_hash(s);

	ll ans = 1 + solve(1);

	for (int i = 2; i * i <= n; i++){
		if (n % i == 0){
			ans += solve(i);

			if (n/i != i)
				ans += solve(n/i);
		}
	}

	cout<<ans<<endl;
}