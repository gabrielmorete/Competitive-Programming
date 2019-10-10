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
ll p[201], acum[201], l, n;
ll memo[2001][20010];
int path[2001][20010];

ll pd() {
	for (int i = n; i < 201; i++)
		for (int j = 0; j < 20010; j++)
			memo[i][j] = 0;
	for (int pos = n - 1; pos >= 0; pos--){
		for (ll cap = 0; cap <= l; cap++){
			memo[pos][cap] = 0;
			if ((cap + p[pos]) <= l) {
				memo[pos][cap] = memo[pos + 1][cap + p[pos]] + 1ll;
				path[pos][cap] = 1;
		    }
		    if ((acum[pos] - cap) <= l) {
				if ((memo[pos + 1][cap] + 1ll) > memo[pos][cap] ){
					memo[pos][cap] = memo[pos + 1][cap] + 1ll;
					path[pos][cap] = 2;
				}
			}
		}	
	}
	return memo[0][0];		
}

void solve() {
	ll x;
	cin>>l;
	l *= 100;

	n = 0;
	while (cin>>x and x) 
		p[n++] = x;;
	
	if (n == 0){
		cout<<0<<endl;
		return;
	}

	acum[0] = p[0];
 	frr(i,n-1)
 		acum[i] = acum[i - 1] + p[i];

	// fr(i,201) //Only for memoized recursion
	// 	fr(j,20010)
	// 		memo[i][j] = -1;

	ll cnt = pd();
	
	cout<<cnt<<endl;

	ll a , b;
	a = b = 0;
	while (cnt) {
		cout<<(path[a][b] == 1? "port" : "starboard")<<endl;
		if (path[a][b] == 1)
			b += p[a];
		a++;
		cnt--;
	}
	
}

int main(){
	fastio;
	int t;
	cin>>t;
	while (t--){ 
		solve();
		if (t) //Blanck line after each testcase
			gnl;
	}
}
// Memoized Recursion
// ll pd(int pos, ll cap) {
// 	if (pos >= n)
// 		return 0;

// 	ll &pdm = memo[pos][cap];
// 	if (pdm != -1)
// 		return pdm;

// 	pdm = 0;		

// 	if ((cap + p[pos]) <= l) {
// 		pdm = pd(pos + 1, cap + p[pos]) + 1ll;
// 		path[pos][cap] = 1;
		
// 	}
// 	if ((acum[pos] - cap) <= l) {
// 		if ((pd(pos + 1, cap) + 1ll) > pdm ){
// 			pdm = pd(pos + 1, cap) + 1ll;
// 			path[pos][cap] = 2;
// 		}
// 	}	
// 	return pdm;
// }