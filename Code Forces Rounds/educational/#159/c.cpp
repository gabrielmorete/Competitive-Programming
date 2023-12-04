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

ll n, a[MAXN];

ll getans(ll x){
	ll ans = 0, mx = a[0];

	for (int i = 0; i <= n; i++)
		mx = max(mx, a[i]);

	for (int i = 0; i <= n; i++)
		ans += (mx - a[i]) / x;
	return ans;
}

void solve(){
	cin>>n;

	fr(i, n)
		cin>>a[i];

	sort(a, a + n);
	
	if (n == 1){
		cout << 1 << endl;
		return;
	}

	if (n == 2){
		cout << 3 << endl;
		return;
	}	

	ll x = __gcd(a[1] - a[0], a[2] - a[1]);

	for (int i = 3; i < n; i++)
		x = __gcd(x, a[i] - a[i - 1]);

	assert(x > 0);

	// first possible answer;
	//a_{n + 1} = a_n + x;
	a[n] = a[n - 1] + x;
	ll ans = getans(x);

	// let us try another
	ll mul = n;
	for (int i = 0; i < n; i++){
		if ((a[n - 1] - a[n - 1 - i]) != i * x){
			mul = i;
			break;
		}
	}

	a[n] = a[n - 1] - x * mul;
	ans = min(ans, getans(x));

	ll nx = -1;
	// now, we change x
	for (ll i = 2; i * i <= x; i++)
		if (x % i == 0){
			nx = x/i;
			break;
		}

	if (nx != -1){
		x = nx;

		// first possible answer;
		//a_{n + 1} = a_n + x;
		a[n] = a[n - 1] + x;
		ans = min(ans, getans(x));

	// let us try another
		ll mul = n;
		for (int i = 0; i < n; i++){
			if ((a[n - 1] - a[n - 1 - i]) != i * x){
				mul = i;
				break;
			}
		}

		a[n] = a[n - 1] - x * mul;
		ans = min(ans, getans(x));
	}	

	cout << ans << endl;
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;

	cin>>T;

	while (T--)
		solve();
}