#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fst first
#define snd second

#define fr(i,n)     for (int i = 0; i < n; i++)
#define frr(i,n)    for (int i = 1; i <= n; i++)

#define endl '\n'
#define gnl cout << endl
#define chapa cout << "oi meu chapa" << endl
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
//cout << setprecision(9)<<fixed;

#define dbg(x)  cout << #x << " = " << x << endl
#define all(x)  x.begin(),x.end()

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

const int INF = 0x3f3f3f3f;
const ll llINF = (long long)(1e18) + 100;   
const int MAXN = 2e6 + 10;

const ll mod = 1e9 + 7;

ll ans[MAXN];

int32_t main(){
	fastio;

	ans[3] = 1;
	for (int i = 4; i < MAXN; i++){
		ans[i] = (2 * ans[i - 2] + ans[i - 1]) % mod;
		if (i % 3 == 0)
			ans[i] = (ans[i] + 1) % mod;
	}

	int T, n;
	ll val;
	cin>>T;
	while (T--){
		cin>>n;
		val = (ans[n] * 4) % mod;
		cout<<val<<endl;
	}
}