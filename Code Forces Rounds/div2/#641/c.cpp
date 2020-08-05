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
const int MAXN = 1e5 + 10;
const ll mod=1e9+7;

int32_t main(){
	fastio;
	int n;
	cin>>n;
	vll v, mdc;

	int x;
	fr(i, n){
		cin>>x;
		v.pb(x);
	}

	if (n == 2){
		cout<<v[0]*v[1]/__gcd(v[0], v[1])<<endl;
		return 0;
	}

	ll a = __gcd(v[0], v[1]);
	mdc.pb(a);

	for(int i = 2; i < n; i++){
		a = __gcd(a, v[i]);
		mdc.pb(a);
	}

	ll ans;
	for(int i = n - 1; i > 1; i--){
		if (i == n - 1)
			ans = (mdc[i - 2]*v[i])/__gcd(mdc[i - 2], v[i]);
		else
			ans = __gcd(ans, (mdc[i - 2]*v[i])/__gcd(mdc[i - 2], v[i]) );
	}

	ans = __gcd( ans, (v[0]*v[1])/__gcd(v[0], v[1]));

	cout<<ans<<endl;
}