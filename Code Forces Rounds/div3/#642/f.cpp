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
	ll m, n, a[110][110];

	cin>>n>>m;

	fr(i, n)
		fr(j, m)
			cin>>a[i][j];

	ll a00 = a[0][0];
	ll ans = llINF;

	ll need, memo[110][110];


	fr(x, n)
		fr(y, m){
			need = a[x][y] - x - y;
			if (need > a00)
				continue;

			fr(i, n)
				fr(j, m)
					memo[i][j] = llINF;

			a[0][0] = need;
			memo[0][0] = a00 - need;
			fr(i, n)
				fr(j, m){
					need = a[0][0] + i + j;
					if (need > a[i][j])
						continue;

					if (i > 0)
						memo[i][j] = min(memo[i][j], memo[i - 1][j] + a[i][j] - need);
					
					if (j > 0)
						memo[i][j] = min(memo[i][j], memo[i][j - 1] + a[i][j] - need);
				}
				ans = min(ans, memo[n - 1][m - 1]);
		}

	cout<<ans<<endl;				
}

int32_t main(){
	fastio;
	int T;
	cin>>T;
	while (T--)
		solve();
}