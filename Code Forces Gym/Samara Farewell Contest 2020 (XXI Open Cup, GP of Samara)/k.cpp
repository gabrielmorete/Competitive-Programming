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

ll n, m, hp;
vector<pair<ll, ll>> pos, nev;
vector<ll> stk;

bool fight(pair<ll, ll> x){
	ll mhp, mres;
	tie(mhp, mres) = x;

	if (mhp == 1) // coloquei em 1 de hp
		stk.pb(mres); // adiciona restauração no 1 de hp

	while (mhp > 1){
		ll dlt = min(hp - 1, mhp - 1);

		hp -= dlt;
		mhp -= dlt;

		if (mhp == 1) // coloquei em 1 de hp
			stk.pb(mres); // adiciona restauração no 1 de hp

		if (hp == 1){
			if (stk.empty()){
				cout<<"NO"<<endl;
				return false;
			}

			hp = min(m, stk.back()); // gasta 1 pra matar
			stk.pop_back();
		}
	}
	return true;	
}

void solve(){
	pos.clear();
	nev.clear();
	stk.clear();

	cin>>n>>m;

	ll t, h;
	fr(i, n){
		cin>>t>>h;
		if (t <= h)
			pos.pb({t, h});
		else
			nev.pb({h, t});
	}

	sort(all(pos));
	sort(all(nev));
	reverse(all(nev));
	

	fr(i, nev.size())
		swap(nev[i].fst, nev[i].snd);

	hp = m;	

	for (auto x : pos)
		if (!fight(x)) return;

	for (auto x : nev) // vou primeiro pelos com mais restauração
		if (!fight(x)) return;

	cout<<"YES"<<endl;
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;
	while (T--)
		solve();
}