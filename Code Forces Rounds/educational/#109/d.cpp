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

int n, m;
vi a, b;

ll memo[5555][5555];

ll pd(int p, int q){
	if (p >= n)
		return 0;
	if (q >= m)
		return INF;

	ll &pdm = memo[p][q];
	if (pdm != -1)
		return pdm;

	pdm = min(pd(p, q + 1), pd(p + 1, q + 1) + abs<ll>(a[p] - b[q]));
	return pdm;
}


int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int sz;
	cin>>sz;

	int x;
	frr(i, sz){
		cin>>x;
		if (x == 1)
			a.pb(i);
		else
			b.pb(i);
	}
	n = a.size();
	m = b.size();

	fr(i, n + 10)
		fr(j, m + 10)
			memo[i][j] = -1;

	cout<<pd(0, 0)<<endl;
}