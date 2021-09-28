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
const int MAXN = 7e5 + 10;

struct fenwic{
	int n;
	vector<ll> bit;

	fenwic (int _n){
		n = _n + 1;
		bit.resize(n + 1);
		fill(bit.begin(), bit.end(), 0);
	}

	void modfy(int p, ll val){
		for (p++; p <= n; p += (p & -p))
			bit[p] += val;		
	}

	void modfy(int l, int r, ll val){ modfy(l, val); modfy(r + 1, -val);}

	ll query(int p){
		ll res = 0;
		for (p++; p > 0; p -= (p & -p))
			res += bit[p];
		return res;
	}

	ll query(int l, int r){return query(r) - query(l - 1);}
};


signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n;
	cin>>n;

	fenwic s(MAXN), t(MAXN);

	ll x, ans = 0, sum = 0;
	for (ll i = 1; i <= n; i++){
		cin>>x;

		ans += x * (i - 1);
		ans += s.query(x);

		for (ll j = x; j < MAXN; j += x)
			s.modfy(j, -x);

		ans += sum;

		ll ml = -1;
		for (ll j = x; j < MAXN; j += x){
			ll frq = t.query(j, min<ll>(j + x - 1, MAXN));
			ans += ml * frq * x;
			ml--;
		}		

		t.modfy(x, 1);
		sum += x;

		cout<<ans<<' ';
	}
	gnl;
}