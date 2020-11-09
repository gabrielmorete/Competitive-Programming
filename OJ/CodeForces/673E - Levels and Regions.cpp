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
const double llINF = (1e18) + 100;   
const int MAXN = 2e5 + 10;

int n, m, t[MAXN];

double rev[MAXN], sum[MAXN], pre[MAXN];
double dp_before[MAXN], dp_cur[MAXN];

void compute(int l, int r, int optl, int optr){// otimizada O(mnlong(n))
    if (l > r)
        return;

    int mid = (l + r) >> 1;

    int opt = 1;
	double vmid = llINF, aux;
    for (int k = optl; k <= min(mid, optr); k++) {
    	aux = pre[mid] - pre[k - 1] - sum[k - 1] * (rev[mid] - rev[k - 1]);
    	if (vmid > dp_before[k - 1] + aux){
    		vmid = dp_before[k - 1] + aux;
    		opt = k;
    	}
    }

    dp_cur[mid] = vmid;
 
    compute(l, mid - 1, optl, opt);
    compute(mid + 1, r, opt, optr);
}

double pd(){
	frr(i, n)
		dp_cur[i] = pre[i];
	dp_cur[0] = llINF;

	for (int i = 1; i < m; i++){
		for (int j = 0; j <= n; j++)
			dp_before[j] = dp_cur[j];
		compute(1, n, 1, n);
	}

	return dp_cur[n];
}

// se um evento tem probabilidade p de ocorrer o # esperado
// de tentativas até ocorrer é 1/p

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin>>n>>m;

	frr(i, n)
		cin>>t[i];

	for (int i = 1; i <= n; i++){
		rev[i] = rev[i - 1] + 1/((double) t[i]);
		sum[i] = sum[i - 1] + (double) t[i];
		pre[i] = pre[i - 1] + sum[i]/((double) t[i]);
	}	

	cout<<setprecision(9)<<fixed;
	cout<<pd()<<endl;

}