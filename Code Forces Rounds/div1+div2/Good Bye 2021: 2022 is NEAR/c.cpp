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

ll n, a[100];

void solve(){
	cin>>n;

	frr(i, n)
		cin>>a[i];

	int ans = n - 1;
	
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++){
			ll r = a[j] - a[i];
			ll dv = (j - i);

			int now = 0;

			frr(k, n)
				if (dv * a[k] != dv * a[i] + r * (k - i))
					now++;

			ans = min(ans, now);	
		}

	cout<<ans<<endl;
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;

	while (T--)
		solve();
}