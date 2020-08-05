#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define mp make_pair
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
typedef vector<ll> vll;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = (long long)(1e18) + 100;   
const int MAXN = 100100;
const int MAXM = 1001000;
const ll mod=1e9+7;
const int LMAXN = 25;

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

typedef tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
// find_by_order(i) -> iterator to ith element
// order_of_key(k) -> position (int) of lower_bound of k

ordered_set q;

int main(){
	fastio;
	int n, x, cnt, a;
	cin>>n>>x;
	
	cnt = 0;

	fr(i,n){
		cin>>a;
		q.insert({a,cnt++});
	}

	//index element by one
	q.insert({-1,0});

	int ans = 0;
	auto it = q.find_by_order((n+1)/2);
 	
 	//already correct
 	if (it->fst == x){
 		cout<<ans<<endl;
 		return 0;
 	}

 	while (it->fst != x){
 		
 		ans++;
 		n++;

 		q.insert({x,cnt++});

 		it = q.find_by_order((n+1)/2);
 	}
 	cout<<ans<<endl;
}