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
const int MAXN = 2e3 + 10;
const ll mod = 1e9+7;

int n, frqs[30][MAXN], frqt[30][MAXN];
string s, t;

int memo[MAXN][MAXN];

int pd(int i, int j){
	if (j == 0)
		return 0;

	int &pdm = memo[i][j];
	if (pdm != -1)
		return pdm;

	pdm = INF;

	if (i > 0){
		pdm = min(pdm, pd(i - 1, j) + 1);
		if (s[i - 1] == t[j - 1])
			pdm = min(pdm, pd(i - 1, j - 1));
	}
	int cht = t[j - 1] - 'a';	

	if (frqs[cht][i + 1] > frqt[cht][j + 1])
		pdm = min(pdm, pd(i, j - 1));

	return pdm;
}

void solve(){
	fr(i, 30){
		fill(frqs[i], frqs[i] + MAXN, 0);
		fill(frqt[i], frqt[i] + MAXN, 0);	
	}

	cin>>n;
	cin>>s>>t;

	fr(i, n){
		frqs[s[i] - 'a'][i + 1]++;
		frqt[t[i] - 'a'][i + 1]++;
	}

	fr(j, 30)
		for (int i = n - 1; i >= 0; i--){
			frqs[j][i] += frqs[j][i + 1];
			frqt[j][i] += frqt[j][i + 1];
		}

	fr(j, 30)
		if (frqs[j][0] != frqt[j][0]){
			cout<<-1<<endl;
			return;
		}

	fr(i, n + 1)
		fr(j, n + 1)
			memo[i][j] = -1;

	cout<<pd(n, n)<<endl;	

}


int32_t main(){
	fastio;
	int T;
	cin>>T;
	while (T--)
		solve();
}