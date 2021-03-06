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

const int INF = 0x3f3f3f3f;
const ll llINF = (long long)(1e18) + 100;   
const int MAXN = 1e5 + 10;
const ll mod = 1e9+7;

map<int, ll> lin, col;
map<pii, ll> pnts;

ll ans;

int32_t main(){
	fastio;
	int n;

	cin>>n;

	int x, y;

	fr(i, n){
		cin>>x>>y;

		ans -= pnts[{x, y}];
		pnts[{x, y}]++;

		ans += lin[x];
		lin[x]++;

		ans += col[y];
		col[y]++;
	}
	
	cout<<ans<<endl;
}