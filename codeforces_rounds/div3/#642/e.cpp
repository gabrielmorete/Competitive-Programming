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
const int MAXN = 1e6 + 10;
const ll mod=1e9+7;

int memo[MAXN];

int pd(string &t){
	int n = t.size();
	int tot = count(all(t), '1');
	int ans = tot;

	int cur, pref = 0;
	for (int i = 0; i < n; i++){
		cur = t[i] - '0';
		pref += cur;
		memo[i] = 1 - cur;
		if (i > 0)
			memo[i] += min(memo[i - 1], pref - cur);
		ans = min(ans, memo[i] + tot - pref);
	}

	return ans;

}

void solve(){
	int n, k;
	string s;

	cin>>n>>k;
	cin>>s;

	int tot = count( all(s) , '1');

	int ans = INF;

	int aux;
	string t;
	fr(i, k){
		t.clear();
		for (int j = i; j < n; j += k)
			t.pb(s[j]);
		
		aux = count(all(t), '1');

		ans = min(ans, pd(t) + tot - aux);
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