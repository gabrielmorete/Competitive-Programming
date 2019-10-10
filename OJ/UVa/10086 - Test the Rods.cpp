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
int n, t1, t2;
ll m[33], c[33][22][2];
ll memo[33][333][333];
int path[33][333][333];

ll pd() {
	for (int i = 0; i <= t1; i++)
		for (int j = 0; j <= t2; j++)
			memo[n + 1][i][j] = 0;

	for (int site = n; site >= 1; site--) {
		int qnt = m[site];

		for (int tt1 = 0; tt1 <= t1; tt1++){
			for (int tt2 = 0; tt2 <= t2; tt2++) {
				
				memo[site][tt1][tt2] = INF;			
	
				for (int i = 0; i <= qnt; i++) {
					if ((tt1 - i) >= 0 and (tt2 - qnt + i) >= 0) {
						if (memo[site][tt1][tt2] > (memo[ site + 1][tt1 - i][tt2 - qnt + i] 
													+ c[site][i][0] + c[site][qnt - i][1])) {
							memo[site][tt1][tt2] = memo[ site + 1][tt1 - i][tt2 - qnt + i] 
												+ c[site][i][0] + c[site][qnt - i][1];
							path[site][tt1][tt2] = i;
						}
					}	
				}
			}
		}		
	}
	return memo[1][t1][t2];
}

int main(){
	fastio;
	cin>>t1>>t2;
	while (t1 + t2){
		cin>>n;

		for (int i = 1; i <= n; i++) {
			cin>>m[i];
			for (int j = 1; j <= m[i]; j++)
				cin>>c[i][j][0];
			for (int j = 1; j <= m[i]; j++)
				cin>>c[i][j][1];	
		}
	
		//Only for memoized recursion
		//ms( memo, -1); 
		//ll ans = pd( 1, t1, t2);

		ll ans = pd();
		cout<<ans<<endl;
		
		int aux;
		for (int i = 1; i <= n; i++){
			cout<<path[i][t1][t2]<<' ';
			aux = path[i][t1][t2];
			t1 -= aux;
			t2 -= m[i] - aux;
		}
		gnl;
		gnl;
		cin>>t1>>t2;
	}
}

// Memoized Recursion
// ll pd(int site, int tt1, int tt2) {
// 	if (site > n)
// 		return 0;
	
// 	ll &pdm = memo[site][tt1][tt2];
// 	if (pdm != -1)
// 		return pdm;
	
// 	int qnt = m[site];
// 	pdm = INF;
// 	for (int i = 0; i <= qnt; i++)
// 		if ((tt1 - i) >= 0 and (tt2 - qnt + i) >= 0)
// 			if (pdm > (pd( site + 1, tt1 - i, tt2 - qnt + i) + c[site][i][0] + c[site][qnt - i][1])) {
// 				pdm = pd( site + 1, tt1 - i, tt2 - qnt + i) + c[site][i][0] + c[site][qnt - i][1];
// 				path[site][tt1][tt2] = i;
// 			}
	
// 	return pdm;		
// }