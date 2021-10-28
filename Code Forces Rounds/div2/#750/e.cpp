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
const int MAXN = 1e5 + 10;

ll n, a[MAXN], memo[MAXN][500], pref[MAXN]; // memo[i][j] maior valor de sum(l_j, r_j) no sufixo de tamanho i

void solve(){
	cin>>n;
	frr(i, n){
		cin>>a[i];
		pref[i] = pref[i - 1] + a[i];
	}

	int k = 0;
	while (k*(k + 1) <= 2*n)
		k++;

	fr(i, k) memo[n + 1][i] = -llINF; // impossível
	memo[n + 1][0] = llINF; // o maior que consigo sem nada

	for (int i = n; i > 0; i--)
		for (int j = 0; j < k; j++){
			memo[i][j] = memo[i + 1][j];

			ll val = pref[i + j - 1] - pref[i - 1];
			if (j > 0 and i + j - 1 <= n and val < memo[i + j][j - 1])
				memo[i][j] = max(memo[i][j], val);
		} 

	int ans = 0;
	fr(j, k)
		if (memo[1][j] > 0)
			ans = j;

	cout<<ans<<endl;
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;

	while (T--)
		solve();
}