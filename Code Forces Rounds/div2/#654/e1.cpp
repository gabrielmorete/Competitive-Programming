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

#define endl '\n'
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
const int MAXN = 1e4 + 10;

typedef tree<pii,null_type,less<pii>,rb_tree_tag,
tree_order_statistics_node_update> ordered_set;
// find_by_order(i) -> iterator to ith element
// order_of_key(k) -> position (int) of lower_bound of k

ll n, p, a[MAXN];

ll test(int x){
	ordered_set q;
	fr(i, n)
		q.insert({a[i], i});

	ll ans = 1;
	fr(i, n){
		ll aux = q.order_of_key({x + 1, -1});
		ans = (ans * aux) % p;
		x++;
		q.erase(q.begin());
	}

	return ans;	
}

int32_t main(){
	fastio;
	cin>>n>>p;
	fr(i, n)
		cin>>a[i];

	vi ans;
	frr(i, 2000){
		if (test(i) > 0)
			ans.pb(i);
	}	

	cout<<ans.size()<<endl;
	for(int x : ans)
		cout<<x<<' ';
	gnl;		
}