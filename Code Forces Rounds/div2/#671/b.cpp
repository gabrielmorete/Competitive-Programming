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

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;

	while (T--){
		ll x;
		cin>>x;

		ll ans = 0, sum = 0, pwr = 1;

		for (ll i = 1; i < 62; i++){
			if (sum > x)
				break;
			sum = 2 * sum;
			sum += pwr * pwr;
			pwr *= 2;
		
			if (sum <= x){
				ans++;
				x -= sum;
			}
		}

		cout<<ans<<endl;
	}
}