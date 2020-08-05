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

void solve(){
	int n, k;
	cin>>n>>k;

	vi a, b;

	int x;
	fr(i, n){
		cin>>x;
		a.pb(x);
	}

	fr(i, n){
		cin>>x;
		b.pb(x);
	}

	sort(all(a));
	sort(all(b));
	reverse(all(b));

	fr(i, n){
		if (b[i] > a[i] and k > 0){
			a[i] = b[i];
			k--;
		}
	}

	int ans = 0;
	fr(i, n)
		ans += a[i];
	cout<<ans<<endl;	


}

int32_t main(){
	fastio;
	int T;
	cin>>T;
	while (T--)
		solve();
}