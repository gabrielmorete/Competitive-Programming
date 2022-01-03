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
const ll mod = 1e9 + 7;

ll n, pwr[MAXN];
vector<ll> a, b;

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	pwr[0] = 1;
	frr(i, MAXN - 1)
		pwr[i] = (pwr[i - 1] * 2) % mod;

	cin>>n;
	
	fr(i, n){
		ll x;
		cin>>x;
		a.pb(x);
	}

	ll ans = 0;

	while (!a.empty()){
		b.clear();

		ll ev = 0;

		for (auto x : a){
			if (!(x&1)){
				ev++;
				b.pb(x/2);
			}
		}

		ll od = a.size() - ev;
		
		if (n != a.size	())
			od = max<ll>(0, od - 1);

		ans = (ans + (pwr[od] - 1ll) * pwr[ev]) % mod; 

		// notice that this is not counted twice with respect to powers of two, 
		// sice a number becomes odd at most once

		a = b;
	}


	cout<<ans<<endl;
}