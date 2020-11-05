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
#define all(x)  x.begin(),x.end()

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

const int INF = 0x3f3f3f3f;
const ll llINF = (long long)(1e17) + 100;   
const int MAXN = 4e3 + 10;

ll n, m, u[MAXN][MAXN], cost[MAXN][MAXN];
ll dp_before[MAXN], dp_cur[MAXN];

void compute(ll l, ll r, ll optl, ll optr){// otimizada O(mnlong(n))
    if (l > r)
        return;

    ll mid = (l + r) >> 1;

	ll vmid = llINF, opt = -1;
    for (int k = optl; k <= min(mid, optr) + 1; k++) {
    	if (vmid > dp_before[k - 1] + cost[k][mid]/2){
    		vmid = dp_before[k - 1] + cost[k][mid]/2;
    		opt = k;
    	}
    }

    dp_cur[mid] = vmid;
 
    compute(l, mid - 1, optl, opt);
    compute(mid + 1, r, max(opt - 1, 1ll), optr);
}

ll pd(){
	frr(i, n)
		dp_cur[i] = cost[1][i]/2;
	dp_cur[0] = llINF;

	for (ll i = 1; i < m; i++){
		for (ll j = 0; j <= n; j++)
			dp_before[j] = dp_cur[j];
		compute(1, n, 1, n);
	}

	return dp_cur[n];
}

char c[9000];

int32_t main(){
	scanf("%d%d\n", &n, &m);	
	
	for (int i = 1; i <= n; i++){
		gets(c); // desgraçaaaaaaaaaaa
		int sz = strlen(c);
		for (int j = 0; j < sz; j += 2) {
			u[i][j / 2 + 1] = c[j] - '0';
		}
	}
	
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			u[i][j] = u[i][j] + u[i][j - 1] + u[i - 1][j] - u[i - 1][j - 1];
 
	for (int i = 1; i <= n; i++)				
		for (int j = 1; j <= n; j++)
			cost[i][j] = u[j][j] - u[j][i - 1] - u[i - 1][j] + u[i - 1][i - 1];	
 
	printf("%d\n", pd());
}

// ll pd(int gnd, int r){ // não otimizada O(n²m)
// 	if (r < 1){
// 		if (gnd == 0)
// 			return 0;
// 		else
// 			return llINF;
// 	}
// 	if (gnd < 1)
// 		return llINF;
	
// 	ll &pdm = memo[gnd][r];
// 	if (pdm != -1)
// 		return pdm;	
	
// 	pdm = llINF;
// 	for (ll l = r; l > 0; l--)
// 		pdm = min(pdm, pd(gnd - 1, l - 1) + cost[l][r] / 2);
	
// 	return pdm;
// }
