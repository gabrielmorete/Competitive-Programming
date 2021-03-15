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

int n, v[MAXN], ans[MAXN];

void solve(){
	cin>>n;
	fr(i, n){
		cin>>v[i];
		ans[i] = 0;
	}

	int now = 0;
	for (int i = n - 1; i >= 0; i--){
		now = max(v[i], now);

		if (now){
			ans[i] = 1;
			now--;
		}
	}

	fr(i, n)
		cout<<ans[i]<<' ';
	gnl;
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t;
	cin>>t;
	while (t--)
		solve();
}