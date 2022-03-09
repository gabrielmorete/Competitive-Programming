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
const int MAXN = 1e3 + 10;

int cst[MAXN];

bool can(int base, int dif){
	if (dif > base)
		return false;
	
	int ini = 1, fim = base;

	while (ini <= fim){
		int meio = (ini + fim)/2;

		if ((base/meio) == dif)
			return true;

		if ((base/meio) > dif)
			ini = meio + 1;
		else
			fim = meio - 1;
	}

	return false;
}

int n, k, b[MAXN], c[MAXN];

int memo[MAXN][20200];

int pd(int pos, int cap){
	if (pos >= n)
		return 0;

	int &pdm = memo[pos][cap];
	if (pdm != -1)
		return pdm;

	pdm = pd(pos + 1, cap);

	if (cap >= cst[b[pos]])
		pdm = max(pdm, pd(pos + 1, cap - cst[b[pos]]) + c[pos]);

	return pdm;
}

void solve(){
	cin>>n>>k;

	int aux = 0;
	fr(i, n){
		cin>>b[i];
		aux += cst[b[i]];
	}

	fr(i, n)
		cin>>c[i];	

	k = min(k, aux);

	fr(i, n + 1)
		fr(j, k + 2)	
			memo[i][j] = -1;

	cout<<pd(0, k)<<endl;
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	frr(i, MAXN - 1)
		cst[i] = i; // at least this cost

	cst[1] = 0;	

	for (int i = 2; i < MAXN; i++)
		for (int j = 1; j < i; j++){
			if (can(j, i - j))
				cst[i] = min(cst[i], cst[j] + 1);
		}	

	int mx = 0;	
	fr(i, MAXN)	
		mx = max(mx, cst[i]);

	int T;
	cin>>T;
	while (T--)
		solve();		
}