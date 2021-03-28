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
const int MAXN = 2e7 + 10;

ll lp[MAXN + 1];
vector<ll> pr;

void crivo(){
	for (ll i = 2; i<= MAXN; ++i) {
	    if (lp[i] == 0) {
	        lp[i] = i;
	        pr.push_back(i);
	    }
	    for (ll j = 0; j < (ll)pr.size() && pr[j] <= lp[i] && i * pr[j] <= MAXN; ++j)
	        lp[i * pr[j]] = pr[j];
	}
}

vector<ll> fac;

void factor(int val){
	fac.clear();

	for (ll i = 1; i * i <= val; i++){
		if (val % i == 0){
			fac.pb(i);
			if (val / i != i)
				fac.pb(val / i);
		}
	}
}

ll comb[MAXN];

void solve(){
	ll c, d, x;
	cin>>c>>d>>x;

	factor(x);

	ll ans = 0;
	for (auto div : fac){
		ll g = x / div;

		ll h = g + d;

		if (h % c == 0)
			ans += comb[h/c];
	}

	cout<<ans<<endl;
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	crivo();

 	comb[1] = 0; // numero de divisores primos
	for (int i = 2; i < MAXN; i++)
		comb[i] = comb[i/lp[i]] + (lp[i] != lp[i/lp[i]]);
 
	for (int i = 1; i < MAXN; i++)
		comb[i] = (1<<comb[i]); // numero de conjuntos de divisores primos

	int T;
	cin>>T;
	while (T--)
		solve();
}