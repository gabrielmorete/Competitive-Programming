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
const int MAXN = 6e5 + 10;
const ll mod = 998244353;

typedef tuple<ll, ll, ll> tup;

ll n, a[MAXN], memo[2][MAXN];

void solve(){
	cin>>n;
	fr(i, n)
		cin>>a[i];

	fr(i, n + 10)
		memo[0][i] = memo[1][i] = 0;

	queue<tup> fila;

	fr(i, n){
		if (a[i] == 0)
			fila.push({1, 1, 0});
		if (a[i] == 1)
			fila.push({1, 0, 1});

		if (a[i] - 1 >= 0)
			fila.push({memo[0][a[i] - 1], a[i] - 1, 1});

		fila.push({memo[0][a[i]], a[i] + 1, 0});
		fila.push({memo[0][a[i] + 1], a[i] + 1, 0});

		if (a[i] - 1 >= 0)
			fila.push({memo[1][a[i] - 1], a[i] - 1, 1});

		fila.push({memo[1][a[i] + 1], a[i] + 1, 1});

		while (!fila.empty()){
			ll x, y, z;
			tie(x, y, z) = fila.front();
			fila.pop();

			memo[z][y] = (memo[z][y] + x) % mod;
		}
	}	

	ll ans = 0;
	fr(i, n + 10)
		ans = (ans + memo[0][i] + memo[1][i]) % mod;

	cout<<ans<<endl;
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;
	while (T--)
		solve();
}