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

map< pair<vi, int>, int > memo;

int pd(vi freq, int tme, int tot){
	if (memo.count({freq, tme}))
		return memo[{freq, tme}];
	if (tot == 0)
		return 0;

	int ans = INF;
	frr(i, 7){
		if (!freq[i])
			continue;
		freq[i]--;
		int lft = max(i - tme - 1, 0);
		int add = max(i - tme, 1);
		ans = min(ans, pd(freq, lft, tot - 1) + add);
		freq[i]++;
	}
	memo[{freq, tme}] = ans;
	return ans;
}

int main(){
	fastio;
	vi freq(8, 0);
	int k, x;
	cin>>k;
	fr(i, k){
		cin>>x;
		freq[x]++;
	}
	cout<<pd(freq, 0, k)<<endl;
}