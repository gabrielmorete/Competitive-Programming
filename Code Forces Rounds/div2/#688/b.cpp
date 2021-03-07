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
const int MAXN = 2e5 + 10;

ll n, a[MAXN];

void solve(){
	cin>>n;
	fr(i, n)
		cin>>a[i];

	ll sum = 0;
	
	for (int i = 1; i < n; i++)	
		sum += abs(a[i] - a[i - 1]);

	ll ans = sum;

	ans = min(ans, sum - abs(a[0] - a[1]));
	ans = min(ans, sum - abs(a[n - 1] - a[n - 2]));

	for (int i = 1; i < n - 1; i++){
		ll df = abs(a[i - 1] - a[i]) + abs(a[i + 1] - a[i]);

		ans = min(ans, sum - df + abs(a[i + 1] - a[i - 1]));
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