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

int main(){
	fastio;
	string s;
	int k;

	cin>>s>>k;
	s = s+s;

	vi pos;
	for (int i = 0; i < s.size(); i++)
		if (s[i] == 'E')
			pos.pb(i);
	if (!pos.size()) {
		cout<<0<<endl;
		return 0;
	}	

	ll ans = 0;
	for (int i = 0; i < s.size()/2; i++) {
		if (s[i] == 'E')
			ans += k;
		else {
			auto it = lower_bound( all(pos), i);
			int p = *it;

			if (p > i + k - 1)
				continue;
			ans += i + k - p;
		}
	}
	cout<<ans<<endl;

}