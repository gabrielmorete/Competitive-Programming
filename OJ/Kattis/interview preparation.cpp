#include "bits/stdc++.h"
using namespace std;

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;


#define pb push_back
#define fst first
#define snd second

#define fr(i,n)     for (int i = 0; i < n; i++)
#define frr(i,n)    for (int i = 1; i <= n; i++)

#define gnl cout << endl
#define chapa cout << "oi meu chapa" << endl
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
//cout << setprecision(9)<<fixed;

#define dbg(x)  cout << #x << " = " << x << endl
#define all(x)  x.begin(),x.end()

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

const int INF = 0x3f3f3f3f;
const ll llINF = (long long)(1e18) + 100;   
const int MAXN = 2e5 + 10;
const ll mod=1e9+7;

typedef pair<ll, ll> pll;

typedef tree<pll,null_type, less<pll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
// find_by_order(i) -> iterator to ith element
// order_of_key(k) -> position (int) of lower_bound of k

ordered_set q;
vector< pll > v;

int32_t main(){
	fastio;
	ll a, b, t, ta, tb;
	cin>>a>>b>>t>>ta>>tb;

	ll c, x, y;

	cin>>c;

	fr(i, c){
		cin>>x>>y;
		v.pb({x, y});
	}

	sort(all(v));

	ll ans = 0, aux, da, db, mx;

	fr(i, c){ // Coordenada igual a A
		x = v[i].fst;
		y = v[i].snd;

		da = max(0ll, x - a) * ta;
		db = max(0ll, y - b) * tb;
	
		q.insert({y, i});
		if (da + db <= t){
			mx = (t - da - db)/tb;
			aux = q.order_of_key({y + mx, c + 1});
			ans = max(ans, aux);
		}
	}	

	cout<<ans<<endl;

	fr(i, c)
		swap(v[i].fst, v[i].snd);
	
	sort(all(v));

	swap(a, b);
	swap(ta, tb);

	q.clear();
	fr(i, c){ // Coordenada igual a B
		x = v[i].fst;
		y = v[i].snd;

		da = max(0ll, x - a) * ta;
		db = max(0ll, y - b) * tb;

		q.insert({y, i});
		if (da + db <= t){	
			mx = (t - da - db)/tb;
			aux = q.order_of_key({y + mx, c + 1});
			ans = max(ans, aux);
		}
	}		

	cout<<ans<<endl;
}