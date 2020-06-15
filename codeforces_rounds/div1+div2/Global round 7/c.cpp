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
const int MAXN = 2e5 + 10;

const ll mod = 998244353;
ll v[MAXN], n, k;

int32_t main(){
	fastio;
	cin>>n>>k;

	fr(i, n)
		cin>>v[i];

	ll sum, ans;
	sum = 0;
	ans = 1;

	for (ll i = 0; i < k; i++)
		sum += n - i;

	vector<ll> pos;

	fr(i, n)
		if (v[i] > n - k)
			pos.pb(i);

	for (int i = 1; i < pos.size(); i++)	
		ans = (ans * (pos[i] - pos[i - 1])) % mod;

	cout<<sum<<' '<<ans<<endl;
}