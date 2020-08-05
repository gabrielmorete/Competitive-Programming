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
const int MAXN = 2e2 + 10;
const ll mod=1e9+7;

int memo[MAXN][MAXN][2 * MAXN];
tuple<int, int, int, char> p[MAXN][MAXN][2 * MAXN];
int32_t main(){
	fastio;
	string s, t;
	cin>>s>>t;
	int n = s.size(); 
	int m = t.size();

	fr(i, n + 1)
		fr(j, m + 1)
			fr(k, 2*MAXN)
				memo[i][j][k] = INF;

	int nxti, nxtj;

	memo[0][0][0] = 0;

	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= m; j++)
			for (int k = 0; k < 2*MAXN; k++){
				if (memo[i][j][k] == INF)
					continue;

				nxti = i + (i < n and s[i] == '(');
				nxtj = j + (j < m and t[j] == '(');

				if (k + 1 < 2*MAXN and memo[nxti][nxtj][k + 1] > memo[i][j][k] + 1){
					memo[nxti][nxtj][k + 1] = memo[i][j][k] + 1;
					p[nxti][nxtj][k + 1] = {i, j, k, '(' };
				}

				nxti = i + (i < n and s[i] == ')');
				nxtj = j + (j < m and t[j] == ')');

				if (k > 0 and memo[nxti][nxtj][k - 1] > memo[i][j][k] + 1){
					memo[nxti][nxtj][k - 1] = memo[i][j][k] + 1;
					p[nxti][nxtj][k - 1] = {i, j, k, ')'};
				}
			}	

	int ci = n, cj = m, ck = 0;		
	for (int k = 0; k < 2 * MAXN; k++){
		if (memo[n][m][k] + k < memo[n][m][ck] + ck)
			ck = k;
	}

	string ans = string(ck, ')');
	int a, b, c;
	while (ci > 0 or cj > 0 or ck != 0){
		a = get<0>(p[ci][cj][ck]);
		b = get<1>(p[ci][cj][ck]);
		c = get<2>(p[ci][cj][ck]);
		ans.pb(get<3>(p[ci][cj][ck]));
		ci = a;
		cj = b;
		ck = c;
	}
	reverse(all(ans));
	cout<<ans<<endl;

}