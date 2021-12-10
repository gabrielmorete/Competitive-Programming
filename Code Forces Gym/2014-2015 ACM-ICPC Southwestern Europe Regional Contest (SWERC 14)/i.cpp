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
const int MAXN = 4e2 + 10;

ll n, a[MAXN], memo[MAXN][MAXN][2]; // 0 é min, 1 é max
char op[MAXN];

void pd(){
	fr(i, n)
		memo[i][i][0] = memo[i][i][1] = a[i];

	for (int tam = 2; tam <= n/2; tam++)
		for (int l = 0; l + tam <= n; l++){
			int r = l + tam - 1;

			memo[l][r][0] = llINF;
			memo[l][r][1] = -llINF;
		
			for (int k = l; k < r; k++){
				if (op[k] == '+'){
					fr(i, 2) fr(j, 2){
						memo[l][r][0] = min(memo[l][r][0], memo[l][k][i] + memo[k + 1][r][j]);
						memo[l][r][1] = max(memo[l][r][1], memo[l][k][i] + memo[k + 1][r][j]);
					}
				}
				else if (op[k] == '-'){
					fr(i, 2) fr(j, 2){
						memo[l][r][0] = min(memo[l][r][0], memo[l][k][i] - memo[k + 1][r][j]);
						memo[l][r][1] = max(memo[l][r][1], memo[l][k][i] - memo[k + 1][r][j]);
					}

				}
				else if (op[k] == '*'){
					fr(i, 2) fr(j, 2){
						memo[l][r][0] = min(memo[l][r][0], memo[l][k][i] * memo[k + 1][r][j]);
						memo[l][r][1] = max(memo[l][r][1], memo[l][k][i] * memo[k + 1][r][j]);
					}
				}
				else{
					fr(i, 2) fr(j, 2){
						memo[l][r][0] = min(memo[l][r][0], memo[l][k][i] + memo[k + 1][r][j]);
						memo[l][r][1] = max(memo[l][r][1], memo[l][k][i] + memo[k + 1][r][j]);
						memo[l][r][0] = min(memo[l][r][0], memo[l][k][i] - memo[k + 1][r][j]);
						memo[l][r][1] = max(memo[l][r][1], memo[l][k][i] - memo[k + 1][r][j]);
						memo[l][r][0] = min(memo[l][r][0], memo[l][k][i] * memo[k + 1][r][j]);
						memo[l][r][1] = max(memo[l][r][1], memo[l][k][i] * memo[k + 1][r][j]);
					}
				}
			}
		}
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin>>n;
	fr(i, n)
		cin>>a[i]>>op[i];
	
	fr(i, n){
		a[n + i] = a[i];
		op[n + i] = op[i];
	}

	n += n;
	pd();
	
	for (int i = 0; i < n/2; i++)
		cout<<abs(memo[i][i + n/2 - 1][0])<<abs(memo[i][i + n/2 - 1][1]);
}