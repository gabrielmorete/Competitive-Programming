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
const int MAXN = 1e6 + 10;

ll n, r1, r2, r3, d, a[MAXN], memo[MAXN][2];

ll pd(ll pos, ll volta){
	ll &pdm = memo[pos][volta];
	if (pdm != -1)
		return pdm;

	pdm = llINF;

	if (volta == 0){
		// primeira opção pistola + awp
		if (pos == n - 1)
			pdm = min(pdm, a[pos] * r1 + r3);
		else
			pdm = min(pdm, a[pos] * r1 + r3 + d + pd(pos + 1, 0));

		// segunda opção full pistola + teleporte
		if (pos == n - 1)
			pdm = min(pdm, (a[pos] + 1) * r1 + d + d + r1);
		else	
			pdm = min(pdm, (a[pos] + 1) * r1 + d + pd(pos + 1, 1));

		// terceira opção laser + teleporte
		if (pos == n - 1)
			pdm = min(pdm, r2 + d + d + r1);
		else	
			pdm = min(pdm, r2 + d + pd(pos + 1, 1));
	}
	else { // n ou não
		// primeira opção pistola + awp + volta
		if (pos == n - 1)
			pdm = min(pdm, a[pos] * r1 + r3 + d + r1);
		else
			pdm = min(pdm, a[pos] * r1 + r3 + d + r1 + d + d + pd(pos + 1, 0));

		// segunda opção full pistola + teleporte
		if (pos == n - 1)
			pdm = min(pdm, (a[pos] + 1) * r1 + d + r1 + d + r1);
		else
			pdm = min(pdm, (a[pos] + 1) * r1 + d + r1 + d + r1 + d + pd(pos + 1, 0));

		// terceira opção laser + teleporte
		if (pos == n - 1)
			pdm = min(pdm, r2 + d + r1 + d + r1);
		else
			pdm = min(pdm, r2 + d + r1 + d + r1 + d + pd(pos + 1, 0));
	}

	return pdm;
}



int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin>>n>>r1>>r2>>r3>>d;

	fr(i, n)
		cin>>a[i];

	memset(memo, -1, sizeof memo);

	cout<<pd(0, 0)<<endl;
}