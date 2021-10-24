#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(ll i = 0; i < n; i++)
#define frr(i, n) for(ll i = 1; i <= n; i++)
#define frm(i, n) for(ll i = n-1; i >= 0; i--)

#define pb push_back
#define f first
#define s second

typedef long long ll;
typedef pair<ll,ll> pii;
typedef vector<vector<ll>> matrix;

#define mem(v, k) memset(v, k, sizeof(v));
#define db cout << "Debug" << endl;
#define all(x) begin(x), end(x)
#define dbg(x)  cout << #x << " = " << x << endl
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define random mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define myrand(a, b) uniform_ll_distribution<ll>(a, b)(rng)

#define mp make_pair
#define pq priority_queue

#define MAXN 100010
#define MOD 1000000007
#define INF 2000000000000000100
#define eps 0.000000001

ll n, b;
ll maximo[10];
ll area = 0;
ll ans = INF;
vector<pii> bag;

long double heron(long double a, long double b, long double c){
	long double p2 = (a + b + c);
	long double A = sqrt(p2 * (p2 - 2 * a)/4) * sqrt((p2 - 2 * b) * (p2 - 2 * c)/4);
	return A;
}

bool comp(pii x, pii y){
	return x.f * y.s > x.s * y.f;
}

ll peguei[10];
ll area_tot = 0, preco_tot = 0;

void backtracking(ll ind){
	if (preco_tot >= ans)
		return;

	if(ind == b){
		peguei[0] = max((ll)0, (ll)ceil((area - (long double)area_tot) / bag[0].f - eps));
		ans = min(ans, preco_tot + peguei[0] * bag[0].s);
		return;
	}
	peguei[ind] = 0;
	while(area_tot < area){
		backtracking(ind + 1);
		area_tot += bag[ind].f;
		preco_tot += bag[ind].s;
		peguei[ind]++;

		ll x = preco_tot / bag[0].s;
		if(x * bag[0].f >= area_tot) break;
	}
	while(peguei[ind] > 0){
		peguei[ind]--;
		area_tot -= bag[ind].f;
		preco_tot -= bag[ind].s;
	}
}

signed main(){
	fastio;
	cin >> b >> n;

	fr(i, b){
		ll w, p;
		cin >> w >> p;
		if(w != 0) {
			bag.pb({w, p});
			if(p == 0){
				cout<< 0 << endl;
				return 0;
			}
		}
	}

	if(bag.size() == 0){
		cout << -1 << endl;
		return 0;
	}
	
	b = (int)bag.size();
	sort(all(bag), comp);
	
	long double a2 = 0;
	fr(i, n){
		ll a, y, c;
		cin >> a >> y >> c;
		a2 += heron(a, y, c);
	}

	a2 /= 30;
	area = ceil(a2 - eps);

	fr(i, b)
		ans = ((area + bag[i].f - 1)/bag[i].f) * bag[i].s;
	backtracking(1);
	cout<< ans << endl;
}
