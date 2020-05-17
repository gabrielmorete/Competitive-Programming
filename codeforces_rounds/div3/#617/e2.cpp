#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fst first
#define snd second

#define fr(i,n)     for(int i=0;i<n;i++)	
#define frr(i,n)    for(int i=1;i<=n;i++)

#define dbg(x)  cout << #x << " = " << x << endl
#define all(x)  x.begin(), x.end()

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
const int MAXN = 2e5 + 10;
const ll mod=1e9+7;

int32_t main(){
	fastio;
	int n;
	string s;
	cin>>n>>s;

	fr(i, n)
		s[i] -= 'a';

	int memo[MAXN], maxc[30];

	fill(memo, memo + MAXN, 1);
	fill(maxc, maxc + 30, 0);

	int ans = 0;

	for (int i = 0; i < n; i++){
		for (int j = s[i] + 1; j <= 'z' - 'a'; j++)
			memo[i] = max(memo[i], maxc[j] + 1);

		maxc[s[i]] = max(maxc[s[i]], memo[i]);
		ans = max(ans, memo[i]);
	}

	cout<<ans<<endl;
	fr(i, n)
		cout<<memo[i]<<' ';
	gnl;	

}