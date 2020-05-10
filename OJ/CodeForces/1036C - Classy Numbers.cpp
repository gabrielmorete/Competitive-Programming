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

string s;

int memo[20][5][3];

ll pd(int p, int nz, bool chg){
	if (p == s.size())
		return 1;

	if (memo[p][nz][chg] != -1)
		return memo[p][nz][chg];

	ll ans = 0;
	for (int i = 0; i <= 9; i++){
		if (i == 0){
			if (s[p] > '0')
				ans += pd(p + 1, nz, 1);
			else
				ans += pd(p + 1, nz, chg);
		}
		else{
			if (nz >= 3 or (!chg and i > s[p] - '0'))
				continue;
			if (s[p] - '0' > i)
				ans += pd(p + 1, nz + 1, 1);
			else
				ans += pd(p + 1, nz + 1, chg);
		}
	}
	return memo[p][nz][chg] = ans;
}

void solve(){
	ll r, l;
	cin>>l>>r;

	ms(memo, -1);
	s = to_string(r);
	ll ans = pd(0, 0, 0);

	ms(memo, -1);
	s = to_string(l - 1);

	ans -= pd(0, 0, 0);
	cout<<ans<<endl;
}

int main(){
	fastio;
	int t;
	cin>>t;
	while (t--)
		solve();	
}