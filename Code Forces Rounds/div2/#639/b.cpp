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

vector<ll> v;
void solve(){
	ll n;
	cin>>n;

	ll ans = 0;
	while (n >= 2){
		auto it = lower_bound(all(v), n);
		int p = (int)(it - v.begin());
		if (v[p] > n)
			p--;
		n -= v[p];
		ans++;
	}
	cout<<ans<<endl;
}

int main(){
	fastio;

	ll stp = 5;
	int p = 0;
	v.pb(2);
	while (v[p] <= 1000000000){
		v.pb(v[p] + stp);
		stp += 3;
		p++;
	}

	int T;
	cin>>T;
	while (T--)
		solve();
}