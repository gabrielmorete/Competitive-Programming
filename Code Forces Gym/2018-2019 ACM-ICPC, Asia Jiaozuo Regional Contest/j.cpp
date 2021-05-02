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
const int MAXN = 2e3 + 10;

ll n, m, cnt[MAXN][MAXN], a[MAXN][MAXN], b[MAXN][MAXN], sozinho[312345];
map<pair<ll, ll>, ll> pares;

ll llsqrt(ll x){
	ll y = sqrt(x);

	if ((y - 1) * (y - 1) == x) return y - 1;
	if (y * y == x) return y;
	return y + 1;
}

ll recupera(int px, int py){
	ll aa = 2;
	ll bb = -2ll * a[px][py];
	ll cc =  a[px][py] * a[px][py] - b[px][py];

	ll dlt = bb * bb - 4ll * aa * cc;
	ll rdlt = llsqrt(dlt);

	ll x1 = (-bb - rdlt)/(2 * aa);
	ll x2 = (-bb + rdlt)/(2 * aa);

	if ((-bb - rdlt) % 4ll) x1 = 0;
	if ((-bb + rdlt) % 4ll) x2 = 0;

	if (1 <= x1 and x1 <= n) return x1;
	return x2;
}


void solve(){
	cin>>n>>m;

	pares.clear();
	fr(i, n + 10)
		sozinho[i] = 0;

	fr(i, m + 10) fr(j, m + 10) cnt[i][j] = a[i][j] = b[i][j] = 0;

	int xr, xl, yl, yr;
	for (ll i = 1; i <= n; i++){
		cin>>xl>>xr>>yl>>yr;

		cnt[xl][yl]++;
		a[xl][yl] += i;
		b[xl][yl] += i * i;

		cnt[xl][yr + 1]--;
		a[xl][yr + 1] -= i;
		b[xl][yr + 1] -= i * i;

		cnt[xr + 1][yl]--;
		a[xr + 1][yl] -= i;
		b[xr + 1][yl] -= i * i;

		cnt[xr + 1][yr + 1]++;
		a[xr + 1][yr + 1] += i;
		b[xr + 1][yr + 1] += i * i;						
	}

	ll livre = 0;

	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= m; j++){
			cnt[i][j] += cnt[i][j - 1] + cnt[i - 1][j] - cnt[i - 1][j - 1];
			a[i][j] += a[i][j - 1] + a[i - 1][j] - a[i - 1][j - 1];
			b[i][j] += b[i][j - 1] + b[i - 1][j] - b[i - 1][j - 1];

			if (cnt[i][j] == 0){
				livre++;
			} else if (cnt[i][j] == 1){
				sozinho[a[i][j]]++;
			} else if (cnt[i][j] == 2){
				ll v = recupera(i, j);
				ll u = a[i][j] - v;
				if (v > u) 
					swap(v, u);
				pares[{v, u}]++;
			}	
		}

	ll ans = m * m;
	for (auto it : pares){
		int u, v;
		tie(v, u) = it.fst;
		ans = min<ll>(ans, m * m - livre - it.snd - sozinho[v] - sozinho[u]);
	}
	sort(sozinho + 1, sozinho + 1 + n);

	ans = min<ll>(ans, m * m - livre - sozinho[n] - sozinho[n - 1]);

	cout<<ans<<endl;
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;

	while (T--)
		solve();
}