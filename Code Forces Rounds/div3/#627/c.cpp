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

void solve(){
	string s;
	vi pos;

	cin>>s;

	pos.pb(0);
	fr(i, s.size())
		if (s[i] == 'R')
			pos.pb(i + 1);
	pos.pb(s.size() + 1);
	
	int ans = 0;
	fr(i, pos.size() - 1)
		ans = max(ans, pos[i + 1] - pos[i]);
	cout<<ans<<endl;				
}

int32_t main(){
	fastio;
	int T;
	cin>>T;
	while (T--)
		solve();
}