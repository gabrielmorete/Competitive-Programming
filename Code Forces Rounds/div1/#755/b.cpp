#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fst first
#define snd second

#define fr(i,n)     for (int i = 0; i < n; i++)
#define frr(i,n)    for (int i = 1; i <= n; i++)

// #define endl '\n'
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

ll n;

ll query(ll l, ll r){
	cout<<"? "<<l<<' '<<r<<endl;
	ll ans;
	cin>>ans;
	return ans;	
}


ll getsq(ll val){
	ll ini = 1, fim = n, bst = 1;
	while (ini <= fim){
		ll mid = (ini + fim)/2;
		if (mid * (mid - 1) <= val){
			bst = mid;
			ini = mid + 1;
		}
		else
			fim = mid - 1;
	}

	return bst;
}


void solve(){
	cin>>n;

	ll ini = 1, fim = n, bst = n;

	while (ini <= fim){
		ll mid = (ini + fim)/2;
			
		ll val = query(mid, n);

		if (val > 0)
			ini = mid + 1;
		else{
			bst = mid;
			fim = mid - 1;
		}
	}

	ll k = bst; // achei o k;

	ll tot = query(1, n);
	ll val = query(1, k - 1);

	ll sz2 = tot - val + 1;

	ll j = k - sz2 + 1;

	ll sz1 = getsq(2*tot - sz2 * (sz2 - 1));

	ll i = j - sz1;

	cout<<"! "<<i<<' '<<j<<' '<<k<<endl;
}

signed main(){
	// ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;
	while (T--)
		solve();
}