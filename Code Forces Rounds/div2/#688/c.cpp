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
const int MAXN = 2e3 + 10;

int extr[4][11]; // esqerda, direita, cima, baixo
int n, m[MAXN][MAXN], ans[11];

void solve(){
	cin>>n;

	string s;
	fr(i, n){
		cin>>s;
		fr(j, n)
			m[i][j] = s[j] - '0';
	}

	fr(i, 11){
		ans[i] = 0;
		fr(j, 4)
			extr[j][i] = -1;
	}

	fr(i, n)
		fr(j, n){
			int d = m[i][j];
			if (extr[0][d] == -1){
				extr[0][d] = extr[1][d] = j;
				extr[2][d] = extr[3][d] = i;
			}

			extr[0][d] = min(extr[0][d], j);
			extr[1][d] = max(extr[1][d], j);
			extr[2][d] = min(extr[2][d], i);
			extr[3][d] = max(extr[3][d], i);
		}

	for (int d = 0; d < 10; d++){	
		for (int j = 0; j < n; j++){
			int up, dw, es, dr;
			up = dw = -1;
			for (int i = 0; i < n; i++){
				if (m[i][j] == d){
					if (up == -1)
						up = i;
					dw = max(dw, i);
				}
			}

			es = dr = -1;
			for (int i = 0; i < n; i++){
				if (m[j][i] == d){
					if (es == -1)
						es = i;
					dr = max(dr, i);
				}
			}


			if (up != -1){
				ans[d] = max(ans[d], (n - 1 - up) * abs(extr[0][d] - j));
				ans[d] = max(ans[d], (dw) * abs(extr[0][d] - j));
				ans[d] = max(ans[d], (n - 1 - up) * abs(extr[1][d] - j));
				ans[d] = max(ans[d], (dw) * abs(extr[1][d] - j));
				ans[d] = max(ans[d], (dw - up) * abs(j));
				ans[d] = max(ans[d], (dw - up) * abs(n - 1 - j));
			}

			if (es != -1){
				ans[d] = max(ans[d], (n - 1 - es) * abs(extr[2][d] - j));
				ans[d] = max(ans[d], (dr) * abs(extr[2][d] - j));
				ans[d] = max(ans[d], (n - 1 - es) * abs(extr[3][d] - j));
				ans[d] = max(ans[d], (dr) * abs(extr[3][d] - j));
				ans[d] = max(ans[d], (dr - es) * abs(j));
				ans[d] = max(ans[d], (dr - es) * abs(n - 1 - j));
			}
		}	
	}

	fr(d, 10)
		cout<<ans[d]<<' ';
	gnl;	


}


int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;

	while (T--)
		solve();
}