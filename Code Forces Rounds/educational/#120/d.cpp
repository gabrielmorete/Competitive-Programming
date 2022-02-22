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

#define dbg(x)  cout << #x << " = " << x << endl
#define all(x)  x.begin(), x.end()

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

const int INF = 0x3f3f3f3f;
const ll llINF = (long long)(1e18) + 100;   
const int MAXN = 5e3 + 10;
const ll mod = 998244353;

ll n, k, sum[MAXN], comb[MAXN][MAXN];
string s;

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	fr(i, MAXN){
		comb[i][0] = comb[i][i] = 1;

		for (int j = 1; j < i; j++)
			comb[i][j] = (comb[i - 1][j] + comb[i - 1][j - 1]) % mod;
	}

	cin>>n>>k;
	cin>>s;

	fr(i, n)
		sum[i + 1] = sum[i] + (int)(s[i] - '0');

	if (sum[n] < k){
		cout<<1<<endl;
		return 0;
	}

	ll ans = 1;

	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++){
			ll sz = j - i + 1;
			ll cnt1 = sum[j + 1] - sum[i];

			if (cnt1 > k)
				continue;

			sz -= 2;

			if (s[i] == '0')
				cnt1--;
			if (s[j] == '0')
				cnt1--;

			if (sz >= cnt1 and sz >= 0 and cnt1 >= 0)
				ans = (ans + comb[sz][cnt1]) % mod;
		}

	cout<<ans<<endl;
}