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
const int MAXN = 4e3 + 10;

int n, m, a[MAXN], v[MAXN], sum[MAXN];
int memo[MAXN][MAXN];

int pd(int pos, int lot){
	for (int i = 0; i <= m; i++)
		for (int j = 0; j <= n; j++)
			memo[i][j] = 0;

	memo[0][0] = 1;

	for (int i = 0; i < m; i++)
		for (int j = 0; j <= n; j++){
			if (j + v[i] <= n)
				memo[i + 1][j + v[i]] |= memo[i][j];
			
			int otr = sum[pos] - j;

			if (v[i] + otr <= n)
				memo[i + 1][j] |= memo[i][j];
		}

	return memo[m][n];
}


void solve(){
	cin>>n;

	fr(i, 2*n)
		cin>>a[i];

	int p = 0;

	m = 0;
	while (p < 2*n){
		int q = p;

		while (q + 1 < 2 * n and a[q + 1] < a[p])
			q++;
		v[m++] = q - p + 1;

		p = q + 1;
	}	

	sum[0] = 0;
	for (int i = 1; i < m; i++)
		sum[i] = sum[i - 1] + v[i - 1];

	if (pd(0, 0) == 1)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;
	while (T--)
		solve();
}