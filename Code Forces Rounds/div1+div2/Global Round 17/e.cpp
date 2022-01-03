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

int n;
vi v;

void solve(){
	cin>>n;
	v.resize(n);

	fr(i, n)
		cin>>v[i];

	int ans = 0;
	
	fr(i, n){
		int aux = 0;
		int p = i;

		if (i > 0 and v[i] == v[i - 1])
			continue;

		while (p < n){
			aux++;
			p = lower_bound(v.begin() + p + 1, v.end(), 2 * v[p] - v[i]) - v.begin();
		}

		ans = max(ans, aux);
	}

	cout<<n - ans<<endl;
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;
	while (T--)
		solve();
}