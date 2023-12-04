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

bool test(ll d, ll n, ll p, ll t, ll l){
	ll nd = n - d + 1;
	ll nt = (n + 6)/7;

	ll dt = min(2 * nd, nt);

	return p <= dt * t + nd * l;
}

void solve(){
	ll n, p, l, t;
	cin>>n>>p>>l>>t;

	ll lft = 1, rgt = n, bst = 1;

	while (lft <= rgt){
		ll m = (lft + rgt)/2;

		if (test(m, n, p, t, l)){
			bst = m;
			lft = m + 1;
		}
		else
			rgt = m - 1;		
	}


	cout << bst - 1 << endl;
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;

	cin>>T;

	while (T--)
		solve();
}