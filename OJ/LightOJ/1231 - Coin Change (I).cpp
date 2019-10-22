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
const ll mod=100000007;
const int LMAXN = 25;

int n, k, v[55], qnt[55];
ll memo[1123];

ll pd() {
	ms(memo,0);

	memo[0] = 1;

	for (int i = 0; i < n; i++)
		for (int w = k; w > 0; w--)
			for (int l = 1; l <= qnt[i]; l++)
				if ((w - v[i]*l) >= 0)
					memo[w] = (memo[w] + memo[w - v[i]*l]) % mod;

	return memo[k];	
}

int clk;
void solve() {
	cin>>n>>k;
	
	fr(i,n)
		cin>>v[i];
		
	fr(i,n)
		cin>>qnt[i];	

	cout << "Case " << ++clk << ": "<< pd() << endl;	
	
}

int main() {
	fastio;
	int t;
	cin>>t;
	while (t--) solve();
}