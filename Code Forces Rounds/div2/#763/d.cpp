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
const ll mod = 1e9 + 7;

ll fastxp(ll base, ll exp){
	ll ans = 1;
	while (exp){
		if (exp & 1)
			ans = (ans * base) % mod;
		base = (base * base) % mod;
		exp >>= 1;
	}
	return ans;
}

inline ll hsh(ll a, ll b, ll c, ll d){
	return a + ((ll)(1e6))*b + ((ll)(1e12))*c + ((ll)(1e13))*d;
}

map<ll, int> vis;
vii pos;

void solve(){
	vis.clear();
	pos.clear();

	ll n, m, ra, ca, rb, cb, p;

	cin>>n>>m>>ra>>ca>>rb>>cb>>p;

	ll pc = ((100 - p) * fastxp(100, mod - 2)) % mod;
	p = (p * fastxp(100, mod - 2)) % mod;

	int rx = ra;
	int cx = ca;

	int px = 1;
	int py = 1;

	if (rx == n) px = -1;
	if (rx == 1) px = 1;
	if (cx == m) py = -1;
	if (cx == 1) py = 1;


	ll sc = 0;

	int cnt = 0;
	while (true){
		// cout<<rx<<' '<<cx<<endl;

		if (vis.count(hsh(rx, cx, px, py))){
			sc = vis[hsh(rx, cx, px, py)];
			break;
		}

		vis[hsh(rx, cx, px, py)] = cnt++;
		pos.pb({rx, cx});

		rx += px;
		cx += py;

		if (rx == n) px = -1;
		if (rx == 1) px = 1;
		if (cx == m) py = -1;
		if (cx == 1) py = 1;
	}

	// dbg(sc);


	ll pnt = 1;
	ll scyc = 0;
	for (ll i = sc; i < pos.size(); i++){
		if (pos[i].fst == rb or pos[i].snd == cb){
			ll aux = (pnt * p) % mod;
			aux = (aux * (i - sc)) % mod;
			scyc = (scyc + aux) % mod;
			pnt = (pnt * pc) % mod;	
		}
	}

	ll szc = pos.size() - sc;

	scyc = (scyc + pnt * szc) % mod;
	ll aux = (1 - pnt + mod) % mod;
	scyc = (scyc * fastxp(aux, mod - 2)) % mod;


	pnt = 1;
	ll spth = 0;

	for (ll i = 0; i < sc; i++){
		if (pos[i].fst == rb or pos[i].snd == cb){
			ll aux = (pnt * p) % mod;
			aux = (aux * i) % mod;
			spth = (spth + aux) % mod;
			pnt = (pnt * pc) % mod;	
		}
	}


	ll ans = (spth + pnt * (sc + scyc)) % mod;

	cout<<ans<<endl;
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;
	while (T--)
		solve();
}