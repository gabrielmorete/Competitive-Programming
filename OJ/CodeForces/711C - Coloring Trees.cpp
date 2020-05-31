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
const ll llINF = (long long)(1e17) + 100;   
const int MAXN = 1e5 + 10;
const ll mod = 1e9+7;

int n, m, kk;
int cor[110], cst[110][110];
ll memo[110][110][110];

ll pd(int p, int c, int k){
	if (p > n){
		if (k == kk)
			return 0;
		else
			return llINF;
	}

	ll &pdm = memo[p][c][k];
	if (pdm != -1)
		return pdm;

	if (cor[p] != 0){
		if (cor[p] == c)
			pdm = pd(p + 1, c, k);
		else
			pdm = pd(p + 1, cor[p], k + 1);
	}
	else{
		pdm = llINF;
		for (int j = 1; j <= m; j++)
			pdm = min(pdm , pd(p + 1, j, k + (j == c? 0 : 1)) + cst[p][j]);
	}

	return pdm;
}

int32_t main(){
	fastio;
	cin>>n>>m>>kk;

	frr(i, n)
		cin>>cor[i];
	frr(i, n)
		frr(j, m)
			cin>>cst[i][j];
		
	fr(i, 110)
		fr(j, 110)
			fr(k, 110)
				memo[i][j][k] = -1;

	ll aux = pd(1, 110, 0); // First position | impossible color | no chain		

	if (aux >= llINF)
		cout<<-1<<endl;
	else
		cout<<aux<<endl;

}