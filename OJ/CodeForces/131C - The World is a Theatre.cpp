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
 
ll n, m, t;
int32_t main(){
	fastio;
	
	__int128 fac[31];
	fac[0] = 1;
	for (__int128 i = 1; i < 31; i++)
		fac[i] = i * fac[i - 1];
 
	cin>>n>>m>>t;
	
	ll ans = 0;
	for (ll i = max(t - n, 1ll); i <= min(m, t - 4); i++){
		ans += (fac[n]/(fac[t - i] * fac[n - (t - i)]))*(fac[m]/(fac[m - i] * fac[i]));
	}
	cout<<ans<<endl;
}