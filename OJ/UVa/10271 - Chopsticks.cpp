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

ll sticks[5555];
ll memo[5555][1123];
ll n,k;

ll pd() {
	for (int i = 0; i <= k; i++)
		memo[n-1][i] = INF, memo[n][i] = INF;

	for (int i = 0; i <= n; i++)
		memo[i][0] = 0;

	for (int pos = n-2; pos >= 0; pos--) {
		for (int rk = k; rk >= 1; rk--) {
			memo[pos][rk] = memo[pos + 1][rk];
			if (pos > 3*(k-rk))
				memo[pos][rk] = min( memo[pos][rk], memo[pos + 2][rk - 1] +
					(sticks[pos] - sticks[pos+1])*(sticks[pos] - sticks[pos+1]));
		}
	}
	return memo[0][k];
}

void solve() {
	//ms( memo,-1); //Only in memoized version
	scanf( "%d %d", &k, &n);
	k += 8;

	for (int i = 0; i < n; ++i)
		scanf( "%d", &sticks[i]);

	sort( sticks, sticks + n, greater<ll>());

	
	cout<<pd()<<endl;
}

int main() {
	int t;
	scanf( "%d", &t);
	while (t--) 
		solve();
}
// Memoized Version
// ll pd( int pos, int rk) {
// 	if (rk == 0)
// 		return 0;

// 	if (pos >= n-1)
// 		return INF;
	
// 	ll &pdm = memo[pos][rk];
// 	if (pdm != -1)
// 		return pdm;
	
// 	pdm = pd( pos + 1, rk);
	
// 	if (pos > 3*(k-rk))
// 	pdm = min( pdm, pd( pos + 2, rk - 1) + (sticks[pos] - sticks[pos+1])*(sticks[pos] - sticks[pos+1]));

// 	return pdm;
// }