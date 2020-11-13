#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fst first
#define snd second

#define fr(i,n)     for (int i = 0; i < n; i++)
#define frr(i,n)    for (int i = 1; i <= n; i++)

//#define endl '\n'
#define gnl cout << endl
#define chapa cout << "oi meu chapa" << endl

#define dbg(x)  cout << #x << " = " << x << endl
#define all(x)  x.begin(),x.end()

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

const int INF = 0x3f3f3f3f;
const ll llINF = (long long)(1e18) + 100;   
const int MAXN = 1e2 + 10;
const int MAXM = 1e2 + 10;




// Hungarian's Algorithm O(n^2 m)
// linhas de 1 a n, colunas de 1 a n
// codigo de minimização, para maximização use -custo

int n, m; // faça m >= n
int pu[MAXN], pv[MAXN], cost[MAXN][MAXM];
int pairV[MAXN], way[MAXM], minv[MAXM];
bool used[MAXM];

void hungarian() {
	memset(&pairV, 0, sizeof pairV);
	for(int i = 1, j0 = 0; i <= n; i++) {
		pairV[0] = i;
		memset(&minv, INF, sizeof minv);
		memset(&used, false, sizeof used);
		do {
			used[j0] = true;
			int i0 = pairV[j0], delta = INF, j1;
			for(int j = 1; j <= m; j++) {
				if (used[j]) continue;
				int cur = cost[i0][j] - pu[i0] - pv[j];
				if (cur < minv[j])
					minv[j] = cur, way[j] = j0;
				if (minv[j] < delta)
					delta = minv[j], j1 = j;
			}
			for(int j = 0; j <= m; j++) {
				if (used[j])
					pu[pairV[j]] += delta, pv[j] -= delta;
				else minv[j] -= delta;
			}
			j0 = j1;
		} while(pairV[j0] != 0);
		do {
			int j1 = way[j0];
			pairV[j0] = pairV[j1];
			j0 = j1;
		} while(j0);
	}
}

void solve(){
	cin>>n>>m;
	for (int i = 0; i <= max(n, m) + 1; i++)
		for (int j = 0; j <= max(n, m) + 1; j++)
			cost[i][j] = 0;

	int a, b, c;	
	cin>>a>>b>>c;
	while (a != 0){
		cost[a][b] = -c;
		cin>>a>>b>>c;
	}

	m = max(n, m); // igualando os tamanhos 
	n = max(n, m);

	hungarian();
	
	int ans = 0;
	for (int j = 1; j <= m; j++)
		if (pairV[j] != 0)
			ans -= cost[pairV[j]][j];
	cout<<ans<<endl;	
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int T;
	cin>>T;
	while (T--)
		solve();
}