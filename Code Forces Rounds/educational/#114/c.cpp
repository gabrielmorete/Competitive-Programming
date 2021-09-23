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

ll n, m;
vector<ll> a;

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin>>n;

	a.resize(n);

	ll sum = 0;
	fr(i, n){
		cin>>a[i];
		sum += a[i];
	}

	sort(all(a));
	
	cin>>m;

	ll x, y;
	while (m--){
		cin>>x>>y;

		auto it = lower_bound(all(a), x);

		if (it == a.end()){
			ll ans = x - a.back();
			ans += max(0ll, y - (sum - a.back()));
			cout<<ans<<endl;
		}
		else{
			int p = (int)(it - a.begin());
			ll ans = max(0ll, y - (sum - a[p]));

			if (p > 0){
				ll aux = x - a[p - 1];
				aux += max(0ll, y - (sum - a[p - 1]));
				ans = min(ans, aux);
			}

			cout<<ans<<endl;
		}
	}
}