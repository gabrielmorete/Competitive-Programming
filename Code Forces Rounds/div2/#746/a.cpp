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

ll n, h, a[MAXN];

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;
	while (T--){
		cin>>n>>h;
		fr(i, n)
			cin>>a[i];

		sort(a, a + n);
		
		ll s = a[n - 1] + a[n - 2];

		ll ans = h/(s);
		ans *= 2;

		h -= s*(h/s);
		
		if (h > 0)
			ans++;

		h -= a[n - 1];
		if (h > 0)
			ans++;
		cout<<ans<<endl;

	}
}