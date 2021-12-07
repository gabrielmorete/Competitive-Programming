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
	ll m, d, w;
	cin>>m>>d>>w;

	if (d == 1){
		cout<<0<<endl;
		return;
	}

	ll l = min(m, d);

	w /= __gcd(d - 1, w);
	

	ll t = (l + w - 1)/w;
	ll p = l/w;

	ll ans = (l % w)*( (t*(t - 1))/2) + (w - (l % w))*((p * (p - 1))/2);
	cout<<ans<<endl;
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	ll T;
	cin>>T;

	while (T--)
		solve();
}