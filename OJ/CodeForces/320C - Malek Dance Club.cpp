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

ll fastxp(ll base, ll exp){
	ll ans = 1;
	while (exp > 0){
		if (exp & 1ll)
			ans = (ans * base) % mod;
		base = (base * base) % mod;
		exp >>= 1;
	}
	return ans;
}

int32_t main(){
	fastio;
	string s;
	
	cin>>s;
	reverse(all(s));

	ll ans = 0;

	if (s[0] == '1')
		ans = 1;

	for (ll i = 1; i < s.size(); i++){
		if (s[i] == '0')
			ans = (2ll * ans) % mod;
		else
			ans = (2ll * ans + fastxp(2, i << 1)) % mod;
	}

	cout<<ans<<endl;	

}