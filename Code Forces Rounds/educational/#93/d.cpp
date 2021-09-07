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
const int MAXN = 200 + 10;

ll r[MAXN], b[MAXN], g[MAXN];
ll memo[MAXN][MAXN][MAXN];

ll pd(ll nr, ll nb, ll ng){
	ll cnt = (nr == 0) + (nb == 0) + (ng == 0);

	if (cnt >= 2) return 0;
	
	ll &pdm = memo[nr][nb][ng];
	if (pdm != -1)
		return pdm;

	pdm = 0;

	if (nr > 0 and nb > 0)
		pdm = max(pdm, r[nr] * b[nb] + pd(nr - 1, nb - 1, ng));
	if (nr > 0 and ng > 0)
		pdm = max(pdm, r[nr] * g[ng] + pd(nr - 1, nb, ng - 1));
	if (nb > 0 and ng > 0)
		pdm = max(pdm, b[nb] * g[ng] + pd(nr, nb - 1, ng - 1));

	return pdm;
}


signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	ll nr, nb, ng;

	cin>>nr>>nb>>ng;

	frr(i, nr)
		cin>>r[i];
	frr(i, nb)
		cin>>b[i];
	frr(i, ng)
		cin>>g[i];	

	sort(r + 1, r + 1 + nr);
	sort(b + 1, b + 1 + nb);
	sort(g + 1, g + 1 + ng);

	memset(memo, -1, sizeof memo);

	ll ans = pd(nr, nb, ng);

	cout<<ans<<endl;	
}