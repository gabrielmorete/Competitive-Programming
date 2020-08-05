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

int n, k;
ll memo[500100][27];
char path[500100][27];
string v;

// int pd( int pos, int used) {
// 	if (pos >= n)
// 		return 0;

// 	int &pdm = memo[pos][used];
// 	if (pdm != -1)
// 		return pdm;

// 	pdm = INF;
// 	if ((v[pos] - 'A') != used){
// 		pdm = pd( pos + 1, (v[pos] - 'A'));
// 		path[pos][used] = (v[pos] - 'A');
// 	}
	
// 	for (int i = 0; i < k; i++) {
// 		if (used == i or i == (v[pos] - 'A'))
// 			continue;
// 		if (pdm > (pd( pos + 1, i) + 1)) {
// 			pdm = pd( pos + 1, i) + 1;
// 			path[pos][used] = i;
// 		}
// 	}

// 	return pdm;
// }

ll pd(){
	for (int i = 0; i <= k; i++)
		memo[n][i] = 0;

	for (int pos = n - 1; pos >= 0; pos--) {
		
		for (int used = 0; used <= k; used++) {
			
			ll &pdm = memo[pos][used];
			pdm = INF;
			
			if (used != (v[pos] - 'A')) {
				pdm = memo[pos + 1][v[pos] - 'A'];
				path[pos][used] = v[pos] - 'A';
			}

			for (int i = 0; i < k; i++) {
				
				if (used == i or i == (v[pos] - 'A'))
					continue;
			
				if (pdm > (memo[pos + 1][i] + 1)) {
					pdm = memo[pos + 1][i] + 1;
					path[pos][used] = i;
				}
			}
		}
	}

	return memo[0][k];
}

int main(){
	fastio;

	cin>>n>>k;
	cin>>v;

	int ans = pd();
	cout<<ans<<endl;

	int pos, used;
	
	pos = 0;
	used = k;
	fr(i,n){
		cout<<(char) (path[pos][used] + 'A');
		used = path[pos][used];
		pos++;
	}
	gnl;
}