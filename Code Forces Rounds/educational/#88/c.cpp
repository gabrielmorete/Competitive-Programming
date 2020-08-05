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
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
//cout << setprecision(9)<<fixed;

#define dbg(x)  cout << #x << " = " << x << endl
#define all(x)  x.begin(),x.end()

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

const int INF = 0x3f3f3f3f;
const ll llINF = (long long)(1e18) + 100;   
const int MAXN = 1e5 + 10;

void solve(){
	int h, c, t;
	
	cin>>h>>c>>t;

	int d1, d2;
	d1 = h - t;
	d2 = t - c;

	if (d1 == 0){
		cout<<1<<endl;
		return;
	}
	
	if (d1 >= d2){
		cout<<2<<endl;
		return;
	}

	ll val = d1 % (d2 - d1);
	ll ans = 2 * (d1/(d2 - d1)) + 1;

	if (abs(val + d1 - d2) * ans < (ans + 2) * val)
			ans += 2;

	cout<<ans<<endl;
}

int32_t main(){
	fastio;
	int T;
	cin>>T;
	while (T--)
		solve();
}