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

ll n, z, k, a[MAXN];

ll memo[MAXN][6][2];


ll pd(ll dir, ll lft, ll lst){
	if (dir + lft >= k)
		return 0;

	ll &pdm = memo[dir][lft][lst];
	if (pdm != -1)
		return pdm;

	ll pos = dir - lft;
	pdm = 0;

	if (pos > 0 and lst == 0 and lft < z){
		pdm = a[pos - 1] + pd(dir, lft + 1, 1);
	}

	if (pos < n - 1){
		pdm = max(pdm, a[pos + 1] + pd(dir + 1, lft, 0));
	}

	return pdm;
}


void solve(){
	cin>>n>>k>>z;

	fr(i, n)
		cin>>a[i];

	fr(i, k + 1)	
		fr(j, z + 1)
			fr(l, 2)
				memo[i][j][l] = -1;

	cout<<a[0] + pd(0, 0, 0)<<endl;
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;
	while (T--)
		solve();
}