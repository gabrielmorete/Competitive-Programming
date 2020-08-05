#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define mp make_pair
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
typedef vector<ll> vll;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = (long long)(1e18) + 100;   
const int MAXN = 100100;
const int MAXM = 1001000;
const ll mod=1e9+7;
const int LMAXN = 25;

ll x, n;
vll fac; 

bool vis[1123456];
void factor(){
	for( ll i = 2; i*i <= x; i++) {
		if( vis[i])
			continue;
		vis[i] = 1;
		int ct = 0;
		while( x%i == 0){
			x /= i;
			ct++;
		}
		if( ct)
			fac.pb(i);
		for( ll j = i*i; j*j <= x; j += i)
			vis[j] = 1;
	}
	if (x != 1)
		fac.pb(x);
}

ll fastxp( ll exp, ll base){
	ll ans = 1;

	while( exp > 0){
		if( exp % 2)
			ans = ans*base % mod;
		base = base*base % mod;
		exp /= 2;	
	}
	return ans;
}

int main(){
	fastio;
	cin>>x>>n;
	factor();

	ll ans = 1;
	for(auto x : fac) {
		ll aux = n;
		while( aux){
			ans = ans*fastxp( aux/x, x) % mod;
			aux /= x;
		}
	}

	cout<<ans<<endl;
}