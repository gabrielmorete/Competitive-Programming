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
const int MAXN = 1e6 + 10;

ll n, q;
ll cor[MAXN], lft[MAXN], lazy[MAXN];

using coord = ll;

struct fenwic{
	int n;
	vector<coord> bit;

	fenwic (int _n){
		n = _n + 1;
		bit.resize(n + 1);
		fill(bit.begin(), bit.end(), 0);
	}

	void modfy(int p, coord val){
		for (p++; p <= n; p += (p & -p))
			bit[p] += val;		
	}

	void modfy(int l, int r, coord val){ modfy(l, val); modfy(r + 1, -val);}

	coord query(int p){
		coord res = 0;
		for (p++; p > 0; p -= (p & -p))
			res += bit[p];
		return res;
	}

	coord query(int l, int r){return query(r) - query(l - 1);}
};


signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin>>n>>q;

	set<int> itv;

	fenwic bit(n + 4);

	lft[n] = 1;
	cor[n] = 1;
	itv.insert(n);

	while (q--){
		string op;
		cin>>op;
		if (op == "Add"){
			ll x, y;
			cin>>x>>y;
			lazy[x] += y;
		}
		else if (op == "Query"){
			ll x;
			cin>>x;
			ll v = *itv.lower_bound(x);

			ll ans = bit.query(x);
			ans += lazy[cor[v]];
			cout<<ans<<endl;
		}
		else{
			ll l, r, c, v;
			cin>>l>>r>>c;

			do {
				v = *itv.lower_bound(l);

				if (lft[v] < l){ // new head, do not change this interval
					cor[l - 1] = cor[v];
					lft[l - 1] = lft[v];
					itv.insert(l - 1);
				}

				ll ul = max(l, lft[v]);
				ll ur = min(v, r);

				bit.modfy(ul, ur, lazy[cor[v]]); // sum the lazy val

				if (v >= r){ // its time to stop!
					if (v > r){
						lft[v] = r + 1; // I will ajust this interval size
						itv.insert(r);
					}
					
					cor[r] = c;
					lft[r] = l;
				}
				else{
					itv.erase(v);
					cor[v] = 0;
					lft[v] = 0;
				}
			} while (v < r);

			bit.modfy(l, r, -lazy[c]); // subtract lazy of c
		}
	}
}