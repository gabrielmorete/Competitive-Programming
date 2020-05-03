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

int v[212345], up[512345];

void solve(){
	int n, k;

	cin>>n>>k;

	fr(i, n)
		cin>>v[i];
	
	fr(i, 2*k + 1)
		up[i] = 0;



	int a, b, c;	
	fr(i, n/2){
		a = max(v[i], v[n - i - 1]);
		b = min(v[i], v[n - i - 1]);
		c = a + b;
		up[0] += 2;
		up[b + 1] -= 2;
		up[b + 1]++;
		up[c]--;
		up[c + 1]++;
		up[a + k + 1]--;
		up[a + k + 1] += 2;
	}

	int now = 0;
	int ans = INF;

	fr(i, 2*k + 1){
		now += up[i];
		
		ans = min(ans, now);	
	}
	cout<<ans<<endl;
}

int main(){
	fastio;
	int t;
	cin>>t;
	while (t--)
		solve();
}