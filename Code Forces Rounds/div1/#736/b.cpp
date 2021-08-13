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
const int MAXN = 2e5 + 100;

ll n, a[MAXN], dif[MAXN];

ll t[2 * MAXN];

void build() {  // build the tree
  for (int i = n - 1; i > 0; --i) 
  	t[i] = __gcd(t[i<<1], t[i<<1|1]);
}

void modify(int p, ll value) {  // set value at position p
  for (t[p += n] = value; p > 1; p >>= 1) t[p>>1] = __gcd(t[p], t[p^1]);
}

ll query(int l, int r) {  // sum on interval [l, r)
  ll res = 0;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) res = __gcd(t[l++], res);
    if (r&1) res = __gcd(t[--r], res);
  }
  return res;
}

void solve(){
	cin>>n;

	frr(i, n)
		cin>>a[i];

	fr(i, 2 * n + 10)
		t[i] = 0;		

	frr(i, n - 1){
		dif[i] = abs(a[i] - a[i + 1]);
		modify(i, dif[i]);
	}

	ll ans = 1;

	int r = 1;

	frr(i, n){
		while (r < n and query(i, r + 1) != 1ll){
			ans = max<ll>(ans, r - i + 2);
			r++;
		}
	}	

	cout<<ans<<endl;
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;
	while (T--)
		solve();
}

