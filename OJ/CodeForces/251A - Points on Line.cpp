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

int main(){
	fastio;
	ll n, d;
	vector<ll> v;

	cin>>n>>d;
	
	ll x;
	fr(i,n){
		cin>>x;
		v.pb(x);
	}

	ll ans = 0;
	for(int i = 0; i < n - 2; i++) {

		auto it = lower_bound(all(v), v[i] + d);
		ll dst = distance(v.begin(),it);
		
		//cout<<i<<' '<<dst<<endl;

		if (it == v.end()){
			dst--;
			dst -= i;
			ans += dst*(dst-1)/2;
			
		}
		else if (*it > (v[i] + d)){
			dst--;
			if (dst - i >= 2) {
				dst -= i;
				ans += dst*(dst-1)/2;
			}
		}
		else {
			if (dst - i >= 2) {
				dst -= i;
				ans += dst*(dst-1)/2;
			}
		}
	}
	cout<<ans<<endl;

}