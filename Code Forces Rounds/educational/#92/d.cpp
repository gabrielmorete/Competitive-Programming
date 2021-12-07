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

void solve(){
	ll n, k, l1, r1, l2, r2;

	cin>>n>>k;
	cin>>l1>>r1;
	cin>>l2>>r2;

	if (l2 < l1){
		swap(l1, l2);
		swap(r1, r2);
	}

	if (l2 <= r1){
		ll intsec = min(r1, r2) - l2;
		intsec *= n; // total intersection
		
		if (k <= intsec){
			cout<<0<<endl;
			return;
		}


		k -= intsec;

		ll grow = abs(l1 - l2) + abs(r1 - r2);
		grow *= n;

		ll ans = min(grow, k);

		k -= min(grow, k);

		ans += 2 * max(k, 0ll);

		cout<<ans<<endl;
	}
	else{
		ll ans = llINF;
		ll dst = abs(l2 - r1);

		for (ll i = 1; i <= n; i++){
			ll ak = k;

			ll cst = i * dst;

			ll grow = r2 - l1;
			grow *= i;

			cst += min(grow, ak);

			ak -= min(grow, ak);

			cst += 2 * max(ak, 0ll);

			ans = min(ans, cst);
		}

		cout<<ans<<endl;
	}
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;
	while (T--)
		solve();
}