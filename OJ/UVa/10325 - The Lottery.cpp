#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fst first
#define snd second

#define fr(i,n)     for (int i = 0; i < n; i++)
#define frr(i,n)    for (int i = 1; i <= n; i++)

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
const ll mod = 1e9+7;

int32_t main(){
	fastio;
	ll n, m, v[20];

	while (cin>>n>>m){
		ll ans = n;
		
		fr(i, m)
			cin>>v[i];

		for (int i = 1; i < (1 << m); i++){
			ll mmc = 0;
			
			for (int j = 0; j < m; j++){
				if (i & (1 << j)){
					if (mmc == 0)
						mmc = v[j];
					else
						mmc = (mmc * v[j])/__gcd(mmc, v[j]);
				}
			}

			if (__builtin_popcount(i) % 2)
				ans -= n / mmc;
			else
				ans += n / mmc;			
		}	
		cout<<ans<<endl;
	}
}