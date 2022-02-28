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

#define dbg(x)  cout << #x << " = " << x << endl
#define all(x)  x.begin(), x.end()

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

const int INF = 0x3f3f3f3f;
const ll llINF = (long long)(1e18) + 100;   
const int MAXN = 4e5 + 10;


typedef tree<pair<ll, ll>,null_type,less<pair<ll, ll>>,rb_tree_tag,
tree_order_statistics_node_update> ordered_set;

ll n, T, t[MAXN];

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin>>n>>T;

	frr(i, n)
		cin>>t[i];

	ll ans = 0;
	
	ordered_set q;

	frr(i, n){
		if (T - 1< i)
			break;

		q.insert({t[i] - i, i});

		ans = max(ans, (ll)q.order_of_key({T - i, 0}));
	}

	cout<<ans<<endl;
}