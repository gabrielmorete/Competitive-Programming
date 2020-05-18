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

int32_t main(){
	int n, mdc, mx, v[110];
	
	cin>>n;

	mx = 0;
	fr(i, n){
		cin>>v[i];
		mx = max(mx, v[i]);
	}

	mdc = __gcd(v[0], v[1]);
	frr(i, n - 2)
		mdc = __gcd(mdc, v[i + 1]);
	
	int ans = mx/mdc - n;

	if (ans % 2)
		cout<<"Alice"<<endl;
	else
		cout<<"Bob"<<endl;
	return 0;
}