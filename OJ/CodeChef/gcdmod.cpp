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

const ll mod = 1e9 + 7;

ll fastxp(ll base, ll exp, ll modd){
	ll ans = 1;

	while (exp){
		if (exp & 1)
			ans = ( (__int128) ans * base) % modd; // Esse desgraça da 10**24
		base = ( (__int128) base * base) % modd;
		exp >>= 1;
	}

	return ans;
}

void solve(){
	ll a, b, n;
	cin>>a>>b>>n;

	ll dif = abs(a - b);

	if (dif == 0){
		cout<< (fastxp(a, n, mod) + fastxp(b, n, mod) ) % (mod) <<endl;
		return;
	}	

	ll aa = fastxp(a, n, dif); // gcd(a, b) == gcd(a % b, b)
	ll bb = fastxp(b, n, dif);

	aa = (aa + bb) % dif;
	cout<< (__gcd(aa, dif)) % mod <<endl;
}

int32_t main(){
	fastio;
	int T;
	cin>>T;
	while (T--)
		solve();
}