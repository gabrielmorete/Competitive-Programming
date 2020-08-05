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
const int MAXN = 5e5 + 100;
const ll mod=1e9+7;

ll ans[MAXN];	

int32_t main(){
	fastio;
	int T;
	cin>>T;

	ans[0] = 0;
	ans[1] = 0;

	ll novo = 8, mlt = 1;
	for (ll i = 3; i < 5e5 + 5; i += 2){
		ans[i] = novo*mlt + ans[i - 2];
		novo += 8;
		mlt++;
	}

	int n;
	while (T--){
		cin>>n;
		cout<<ans[n]<<endl;
	}

}