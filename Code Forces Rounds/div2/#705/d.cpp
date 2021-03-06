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
const int MAXN = 3e5 + 10;
const ll mod = 1e9 + 7;

ll n, q, a[MAXN];

ll gpd[MAXN]; // maior divisor primo

multiset<ll> prim[MAXN];
map<int, int> decomp[MAXN];

ll ans;

ll fast_xp(ll base, ll exp){
	ll ans = 1;
	while (exp){
		if (exp & 1)
			ans = (base * ans) % mod;
		base = (base * base) % mod;
		exp >>= 1;
	}
	return ans;
}

void update(ll prm, ll ofr, ll nfr){
	ll mn = 0; 
	if (prim[prm].size() == n) // tem em todos
		mn = *prim[prm].begin();
	
	if (!prim[prm].empty() and ofr > 0)
		prim[prm].erase(prim[prm].find(ofr)); // apaga frequencia anterior
	
	prim[prm].insert(nfr);

	if (prim[prm].size() == n){ // tem em todos
		ll mn2 = *prim[prm].begin();
		ans = (ans * fast_xp(prm, mn2 - mn)) % mod;
	}	
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin>>n>>q;
	fr(i, n)
		cin>>a[i];

	for (ll i = 2; i < MAXN; i++){
		if (gpd[i] == 0){
			for (ll j = i; j < MAXN; j += i)
				gpd[j] = i;
		}
	}

	ll prm, frq, x;
	for (int i = 0; i < n; i++){
		x = a[i];

		while (x > 1){
			prm = gpd[x];
			frq = 0;
			while (gpd[x] == prm){
				frq++;
				x /= gpd[x];
			}
			decomp[i][prm] = frq;
			prim[prm].insert(frq);
		}
	}

	ans = a[0];

	for (int i = 1; i < n; i++)
		ans = __gcd(ans, a[i]);

	int p;
	while (q--){
		cin>>p>>x;
		p--;
		while (x > 1){
			prm = gpd[x];
			frq = 0;
			while (gpd[x] == prm){
				frq++;
				x /= gpd[x];
			}

			update(prm, decomp[p][prm], decomp[p][prm] + frq);
			decomp[p][prm] += frq;
		}

		cout<<ans<<endl;
	}
}