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

ll n, k, v[MAXN], sum[MAXN];

ll test(ll sz){ // number os guys that will me equal to v[0];
	__int128 ini = -llINF, fim = v[0], bst = -llINF;

	while (ini <= fim){
		__int128 meio = (ini + fim)/2;

		__int128 in = sum[1] - sum[n - sz];
		in += (sz + 1) * meio;

		if (in <= (__int128)k){
			bst = meio;
			ini = meio + 1;
		}
		else
			fim = meio - 1;
	}

	return (v[0] - bst) + sz;
}


void solve(){
	cin>>n>>k;

	fr(i, n)
		cin>>v[i];

	sort(v, v + n);

	sum[n] = 0;
	for (int i = n - 1; i >= 0; i--)
		sum[i] = sum[i + 1] + v[i];

	ll ans = llINF;
	for (int i = n - 1; i >= 0; i--)
		ans = min(ans, test(i));

	cout<<ans<<endl;
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;
	while (T--)
		solve();
}