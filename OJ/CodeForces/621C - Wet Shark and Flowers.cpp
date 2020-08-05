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

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = (long long)(1e18) + 100;   
const int MAXN = 1e5 + 100;
const ll mod=1e9+7;

int v[MAXN], dlt[MAXN];

int32_t main(){
	fastio;
	cout << setprecision(9)<<fixed;

	int n, p;

	cin>>n>>p;

	int a, b;
	fr(i, n){
		cin>>a>>b;
		dlt[i] = b - a + 1;
		v[i] = b/p - (a - 1)/p;
	}
	v[n] = v[0];
	dlt[n] = dlt[0];

	double ans = 0, p1, p2;
	fr(i, n){
		p1 = 1.0 - ( (double) v[i] )/( (double) dlt[i]);
		p2 = 1.0 - ( (double) v[i + 1] )/( (double) dlt[i + 1]);
		ans += (1 - p1*p2)*2000.0;
	}
	cout<<ans<<endl;
}