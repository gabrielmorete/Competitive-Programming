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
const ll llINF = (long long)(1e18) + 100;   
const int MAXN = 1e3 + 10;

ll n, m, u[MAXN], p[MAXN];
ll sum[MAXN], acum[MAXN], dacum[MAXN];
ll dp_before[MAXN], dp_cur[MAXN];

void compute(ll l, ll r, ll optl, ll optr){// otimizada O(mnlong(n))
    if (l > r)
        return;

    ll mid = (l + r) >> 1;

	ll vmid = llINF, opt = -1;
    for (ll k = optl; k <= min(mid, optr); k++) {
    	if (vmid > dp_before[k] + sum[mid] - sum[k] - (acum[mid] - acum[k]) * p[k + 1]){
    		vmid = dp_before[k] + sum[mid] - sum[k] - (acum[mid] - acum[k]) * p[k + 1];
    		opt = k;
    	}
    }

    dp_cur[mid] = vmid;
 
    compute(l, mid - 1, optl, opt);
    compute(mid + 1, r, opt, optr);
}

ll pd(){
	frr(i, n)
		dp_cur[i] = sum[i];
	dp_cur[0] = llINF;

	for (ll i = 1; i < m; i++){
		memcpy(dp_before, dp_cur, sizeof dp_cur);
		compute(1, n, 1, n);
	}

	return dp_cur[n];
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	while (cin>>n>>m){
		for (int i = 1; i <= n; i++)
			cin>>p[i]>>u[i];	
		
		reverse(u + 1, u + 1 + n);
		reverse(p + 1, p + 1 + n);

		for (int i = 2; i <= n; i++)
			p[i] = -(p[i] - p[1]);
		p[1] = 0;

		sum[1] = 0;
		acum[1] = u[1];
		for (ll i = 2; i <= n; i++){ 
			sum[i] = sum[i - 1] + p[i] * u[i]; // levar até o 1
			acum[i] = acum[i - 1] + u[i]; // peso acumulado
		}

		cout<<pd()<<endl;
	}
}