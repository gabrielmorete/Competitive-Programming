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
vector<ll> a, b;


int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin>>n>>m;

	ll x;
	fr(i, n){
		cin>>x;
		a.pb(x);
	}

	fr(i, m){
		cin>>x;
		b.pb(x);
	}

	if (n <= 3){
		fr(i, m){
			ll ans = a[0] + b[i];
			fr(j, n)
				ans = __gcd(ans, a[j] + b[i]);
			cout<<ans<<' ';	
		}
		gnl;

		return 0;
	}


	sort(all(a));

	ll mdc = a[1] - a[0];

	for (int i = 2; i < n; i++)
		mdc = __gcd(mdc, a[i] - a[i - 1]);

	fr(i, m)
		cout<<__gcd(a[0] + b[i], mdc)<<' ';
	gnl; 
}