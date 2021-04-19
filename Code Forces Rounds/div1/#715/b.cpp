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

ll func(ll x){
	if (x == 0) return 1;
	return (1ll << (x - 1));
}


void solve(){
	ll n, k;
	cin>>n>>k;

	if (n < 61){
		if (1ll<<(n - 1ll) < k){
			cout<<-1<<endl;
			return;
		}			
	}

	ll m = 0;

	while ((1ll<<m) < k)
		m++;
	
	m++; // numero de elementos do fim

	vi aux;

	ll p = 1;
	while (p <= m){
		ll q = p;

		ll nperm = 0;

		while (q <= m and (nperm + func(m - q)) < k){
			nperm += func(m - q);
			q++;
		}

		if (q > m)
			q--;

		k -= nperm;
		
		for (int l = q; l >= p; l--)
			aux.pb(l);

		p = q + 1;
	}

	vi ans;

	frr(i, n - m)
		ans.pb(i);

	for (auto x : aux)
		ans.pb(x + n - m);

	for (auto x : ans)
		cout<<x<<' ';
	gnl;
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;
	while (T--)
		solve();
}