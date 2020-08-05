#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fst first
#define snd second

#define fr(i,n)     for(int i=0;i<n;i++)
#define frr(i,n)    for(int i=1;i<=n;i++)

#define ms(x,i) memset(x,i,sizeof(x))
#define dbg(x)  cout << #x << " = " << x << endl
#define all(x)  x.begin(),x.end()

#define gnl cout << endl
#define chapa cout << "oi meu chapa" << endl
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
//cout << setprecision(9)<<fixed;

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = (long long)(1e18) + 100;   
const int MAXN = 2e5 + 100;
const ll mod=1e9+7;

int a[MAXN], b[MAXN];
vi ab;
int32_t main(){
	fastio;
	
	ll n;
	cin>>n;
	
	int x;
	fr(i, n){
		cin >> x;
		a[i] = x;
		ab.pb(-x);
	}
	
	fr(i, n){
		cin>>x;
		b[i] = x;
		ab[i] += x;
	}

	sort(all(ab));

	ll ans = 0;

	fr(i, n){
		ll p;
		int c = a[i] - b[i];

		auto it = lower_bound(all(ab), c);
		p = (ll) (it - ab.begin());

		// if (it == ab.end())
		// 	p = n;
		// else if (p != 0 and ab[p] >= c)
		// 	p--;
		
		ans += p;

		if (c > 0)
			ans--;
	}

	cout<<ans/2<<endl;

}