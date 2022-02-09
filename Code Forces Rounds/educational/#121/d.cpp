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

int n, m, frq[MAXN];
vi v;

int test(int a, int b){
	int p = 0, sum = n;

	while (p < m - 1 and a - v[p] >= 0){
		sum -= v[p];
		a -= v[p];
		p++;
	}
	p--;

	int q = m - 1;
	while (q > p and b - v[q] >= 0){
		sum -= v[q];
		b -= v[q];
		q--;
	}

	int ans = a + b;

	fr(i, 19)
		if (1<<i >= sum){
			ans += (1<<i) - sum;
			break;
		}

	return ans;
}

void solve(){
	v.clear();

	cin>>n;
	frr(i, n)
		frq[i] = 0;

	frr(i, n){
		int x;
		cin>>x;
		frq[x]++;
	}	

	v.pb(0);

	frr(i, n)
		if (frq[i] > 0)
			v.pb(frq[i]);

	v.pb(0);	

	m = v.size();

	int ans = INF;
	fr(i, 19)
		fr(j, 19)
			ans = min(ans, test(1<<i, 1<<j));

	cout<<ans<<endl;
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;
	while (T--)
		solve();
}