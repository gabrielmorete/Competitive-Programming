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
	int a, b, c;

	cin>>a>>b>>c;

	int aa, bb, cc;

	int ans = INF;	

	frr(i, c){

		for (int j = i; j <= 2*c; j += i){
			
			for (int k = j; k < 3 * c; k += j){
				if (ans > abs(i - a) + abs(j - b) + abs(k - c)){
					ans = abs(i - a) + abs(j - b) + abs(k - c);	
					aa = i; bb = j; cc = k;
				}
			}
		}
	}

	cout<<ans<<endl;
	cout<<aa<<' '<<bb<<' '<<cc<<endl;
}

int32_t main(){
	fastio;
	int T;
	cin>>T;
	while (T--)
		solve();
}