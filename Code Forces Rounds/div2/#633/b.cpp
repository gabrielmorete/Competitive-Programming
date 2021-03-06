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
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
//cout << setprecision(9)<<fixed;

#define dbg(x)  cout << #x << " = " << x << endl
#define all(x)  x.begin(),x.end()

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

int32_t main(){
	fastio;
	int T;
	cin>>T;
	while (T--){
		vi v;
		int n;
		cin>>n;

		int x;
		fr(i, n){
			cin>>x;
			v.pb(x);
		}

		sort(all(v));

		vi ans;
		int i = 0, j = n - 1;

		while (i <= j){
			if (i <= j){
				ans.pb(v[j--]);
			}
			if (i <= j){
				ans.pb(v[i++]);
			}
		}

		reverse(all(ans));
		fr(i, n)
			cout<<ans[i]<<' ';
		gnl;		

	}
}