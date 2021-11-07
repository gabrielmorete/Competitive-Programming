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
const int MAXN = 2e5 + 10;

const ll mod1 = 1000015553; // primo grande 1
const ll mod2 = 1000028537; // primo grande 2

mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count()); // Gerador aleatório
static ll p = uniform_int_distribution<int>(300000, mod1 - 1)(rng);	// Caso TL usa const p

ll n, pwr1[MAXN], pwr2[MAXN];

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	pwr1[0] = pwr2[0] = 1;

	frr(i, MAXN - 1){
		pwr1[i] = (pwr1[i - 1] * p) % mod1;
		pwr2[i] = (pwr2[i - 1] * p) % mod2;
	}

	cin>>n;

	set<pair<ll, ll>> q;
	ll k, x;
	fr(i, n){
		cin>>k;
		ll hsh1 = 0, hsh2 = 0;

		fr(j, k){
			cin>>x;
			hsh1 = (hsh1 + x*pwr1[j])%mod1;
			hsh2 = (hsh2 + x*pwr2[j])%mod2;
		}

		hsh1 ^= hsh2<<29;

		q.insert({k, hsh1});
	}


	cout<<q.size()<<endl;
}