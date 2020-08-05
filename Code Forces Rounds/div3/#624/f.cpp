#include "bits/stdc++.h"
using namespace std;

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define pb push_back
#define fst first
#define snd second

#define fr(i,n)     for(int i=0;i<n;i++)
#define frr(i,n)    for(int i=1;i<=n;i++)

#define ms(x,i) memset(x,i,sizeof(x))
#define dbg(x)  cout << #x << " = " << x << endl
#define all(x)  x.begin(),x.end()

#define gnl cout << endl
#define chapa cout << "oi meu chapa" << endl
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
//cout << setprecision(9)<<fixed;

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = (long long)(1e18) + 100;   
const int MAXN = 1e5 + 10;
const ll mod=1e9+7;

typedef tree<pii,null_type,less<pii>,rb_tree_tag,
tree_order_statistics_node_update> ordered_set;
// find_by_order(i) -> iterator to ith element
// order_of_key(k) -> position (int) of lower_bound of k


int32_t main(){
	fastio;
	ll n;
	vector<pll> v;

	cin>>n;

	ll x;
	fr(i, n){
		cin>>x;
		v.pb({x, 0});
	}

	int mn = INF;
	fr(i, n){
		cin>>x;
		mn = min<ll>(mn, x);
		v[i].snd = x;
	}
	fr(i, n)
		v[i].snd -= mn;

	sort(all(v));

	ordered_set q;

	ll ans = 0;

	fr(i, n){
		ll aux = (ll) q.order_of_key({v[i].snd + 1, -1});
		// dbg(aux);
		ans += aux *((ll) v[i].fst);
		q.insert({v[i].snd, i});
	}
	// chapa;

	q.clear();

	for (int i = n - 1; i >= 0; i--){
		ll aux = (ll)q.size() - q.order_of_key({v[i].snd - 1, n});
		// dbg(aux);
		ans -= aux *((ll) v[i].fst);
		q.insert({v[i].snd, i});
	}

	cout<<ans<<endl;
}