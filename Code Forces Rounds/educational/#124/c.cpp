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

ll n, a[MAXN], b[MAXN];
void solve(){
	cin>>n;

	frr(i, n)
		cin>>a[i];
	frr(i, n)
		cin>>b[i];

	ll a1 = llINF, an = llINF;		
	frr(i, n){
		a1 = min(a1, abs(b[i] - a[1]));
		an = min(an, abs(b[i] - a[n]));
	}

	ll b1 = llINF, bn = llINF;		
	frr(i, n){
		b1 = min(b1, abs(a[i] - b[1]));
		bn = min(bn, abs(a[i] - b[n]));
	}

	ll ans = llINF;

	// case 1, a1 = b1
	ans = min(ans, abs(b[1] - a[1]) + abs(a[n] - b[n]));
	ans = min(ans, abs(b[1] - a[1]) + an + bn);

	// case 2, a1 = bn
	ans = min(ans, abs(b[n] - a[1]) + abs(a[n] - b[1]));
	ans = min(ans, abs(b[n] - a[1]) + an + b1);

	// case 3, an = b1
	ans = min(ans, abs(b[1] - a[n]) + a1 + bn);

	// case 4, an = bn
	ans = min(ans, abs(b[n] - a[n]) + a1 + b1);

	// case 5
	ans = min(ans, a1 + an + b1 + bn);

	cout<<ans<<endl;
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;
	while (T--)
		solve();
}