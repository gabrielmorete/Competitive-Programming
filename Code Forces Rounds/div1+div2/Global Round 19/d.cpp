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
const int MAXN = 2e2 + 10;

ll n, a[MAXN], b[MAXN], sum[MAXN];
ll memo[101][10101];

ll pd(ll pos, ll lft){
	if (pos == 0)
		return 0;

	ll &pdm = memo[pos][lft];
	if (pdm != -1)
		return pdm;

	ll rgt = sum[pos + 1] - lft; // soma na direita

	ll v1 = 2ll * (a[pos] * lft + b[pos] * rgt) + pd(pos - 1, lft + a[pos]);
	ll v2 = 2ll * (b[pos] * lft + a[pos] * rgt) + pd(pos - 1, lft + b[pos]);

	pdm = min(v1, v2);

	return pdm;
}

void solve(){
	cin>>n;

	frr(i, n)
		cin>>a[i];
	frr(i, n)
		cin>>b[i];

	fr(i, n + 10)
		sum[i] = 0;	

	for (int i = n; i > 0; i--)
		sum[i] = sum[i + 1] + a[i] + b[i];

	memset(memo, -1, sizeof memo);	

	ll ans = pd(n, 0);

	frr(i, n){
		ll aux = a[i] * a[i] + b[i] * b[i];
		aux *= n - 1;
		ans += aux;
	}		

	cout<<ans<<endl;
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;
	while (T--)
		solve();
}