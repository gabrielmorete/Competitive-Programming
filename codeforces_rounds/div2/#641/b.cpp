#include "bits/stdc++.h"
using namespace std;
 
#define pb push_back
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
typedef vector<pii> vii;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;
 
const int INF = 0x3f3f3f3f;
const ll llINF = (long long)(1e18) + 100;   
const int MAXN = 1e5 + 10;
const ll mod=1e9+7;
 
int n, nn;
int v[MAXN], memo[MAXN];
 
void solve(){
	cin>>n;
	frr(i, n)
		cin>>v[i];
 
	int ans = 1;
	for (int i = n; i >= 1; i--){
		memo[i] = 1;
		for (int j = 2*i; j <= n; j += i)
			if (v[i] < v[j])
				memo[i] = max(memo[i], memo[j] + 1);
		ans = max(ans, memo[i]);	
	}
	cout<<ans<<endl;
}
 
int32_t main(){
	fastio;
	int T;
	cin>>T;
	while (T--)
		solve();
}