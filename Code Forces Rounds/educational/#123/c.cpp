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
const int MAXN = 4e5 + 10;

ll n, x, a[MAXN];
ll v[MAXN];
void solve(){
	cin>>n>>x;

	frr(i, n)
		cin>>a[i];

	v[0] = 0;	

	frr(sz, n){
		ll p = 1, q = 0, sum = 0;

		while (q <= n and q - p + 1 < sz){
			q++;
			sum += a[q];
		}

		v[sz] = sum;

		while (q <= n){
			v[sz] = max(v[sz], sum);
			sum -= a[p];
			sum += a[q + 1];
			p++;
			q++;
		}
	}	

	for (int k = 0; k <= n; k++){
		ll ans = 0; // empty

		for (int j = 0; j <= n; j++){
			ll aux = x * min(k, j);
			aux += v[j];
			ans = max(ans, aux);
		}		
		cout<<ans<<' ';	
	}

	gnl;
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;
	while (T--)
		solve();
}