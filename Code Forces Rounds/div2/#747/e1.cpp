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
const int MAXN = 1e5 + 10;
const ll mod = 1e9 + 7;

ll fastxp(ll base, ll exp){
	ll ans = 1;
	while (exp){
		if (exp&1)
			ans = (ans * base)%mod;
		base = (base * base) % mod;
		exp >>= 1;
	}

	return ans;
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	ll k;
	cin>>k;

	ll n = 1ll<<k;
	n -= 2;

	ll ans = (6*fastxp(4, n))%mod;

	cout<<ans<<endl;	
}