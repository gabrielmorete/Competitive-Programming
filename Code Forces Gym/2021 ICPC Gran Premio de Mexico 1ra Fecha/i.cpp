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

ll n, k, t;
vector<ll> v;

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin>>n>>k>>t;

	v.resize(n);

	fr(i, n)
		cin>>v[i];

	ll tot = 0;
	fr(i, n)
		tot += v[n - 1] - v[i];

	ll ans = tot, l, r;	

	for (ll i = 0; i < n - 1; i++){
		int p = (int)(upper_bound(all(v), v[i] + k) - v.begin()) - 1; // ultimo cara valido
		ll aux = tot;
		ll df = v[p] - v[i];
		aux -= (i + 1) * df;
		aux += (i + 1)*t;

		if (aux < ans){
			ans = aux;
			l = i + 1;
			r = p + 1;
		}
	}	

	if (ans < tot)
		cout<<l<<' '<<r<<' '<<ans<<endl;
	else
		cout<<"-1"<<endl;
}