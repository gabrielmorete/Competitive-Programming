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

void solve(){
	vector<ll> miner, mine;
	int n;

	cin>>n;

	ll x, y;
	fr(i, 2 * n){
		cin>>x>>y;
		if (x == 0)
			miner.pb(y * y);
		else
			mine.pb(x * x);
	}

	sort(all(miner));
	sort(all(mine));

	double ans = 0;

	fr(i, n)
		ans += sqrt(miner[i] + mine[i]);

	cout<<setprecision(13)<<fixed;
	
	cout<<ans<<endl;	



}


int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;

	while (T--)
		solve();
}