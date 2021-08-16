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
const int MAXN = 2e5 + 10;
const ll mod = 1e9 + 7;

string s;
ll n, memo[MAXN], nxt[27][MAXN];

ll pd(ll pos){
	ll &pdm = memo[pos];

	if (pdm != -1)
		return pdm;

	pdm = 1; // palavra acaba aqui

	for (int i = 0; i < 26; i++){
		if (pos + 2 < n and nxt[i][pos + 2] < n)
			pdm = (pdm + pd(nxt[i][pos + 2])) % mod;
	}

	return pdm;
}


int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin>>s;

	n = s.size();

	fr(i, 26)
		nxt[i][n + 2] = nxt[i][n + 1] = nxt[i][n] = INF;

	for (int i = n - 1; i >= 0; i--){
		fr(j, 26)
			nxt[j][i] = nxt[j][i + 1];

		nxt[s[i] - 'a'][i] = i;
	}	

	memset(memo, -1, sizeof memo);

	ll ans = 0;
	for (int i = 0; i < 26; i++)
		if (nxt[i][0] <= n)
			ans = (ans + pd(nxt[i][0])) % mod;

	cout<<ans<<endl;
}	