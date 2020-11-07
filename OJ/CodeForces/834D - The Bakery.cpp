#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fst first
#define snd second

#define fr(i,n)     for (int i = 0; i < n; i++)
#define frr(i,n)    for (int i = 1; i <= n; i++)

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
const int MAXN = 4e4 + 10;

int n, m;
int v[MAXN];

int freq[MAXN], df, L, R;

void add(int pos){
	if (freq[v[pos]] == 0)
		df++;
	freq[v[pos]]++;
}

void remove(int pos){
	if (freq[v[pos]] == 1)
		df--;
	freq[v[pos]]--;
}

int calc(int i, int j){
	while(i<L) add(--L);
	while(R<j) add(++R);
	while(L<i) remove(L++);
	while(j<R) remove(R--);
	
	return df;
}

int dp_before[MAXN], dp_cur[MAXN];
void compute(int l, int r, int optl, int optr){// otimizada O(mnlong(n))
    if (l > r)
        return;

    int mid = (l + r) >> 1;

	int vmid = 0, opt = 0;
    for (int k = optl; k <= min(mid, optr); k++) {
    	if (vmid < dp_before[k - 1] + calc(k, mid)){
    		vmid = dp_before[k - 1] + calc(k, mid);
    		opt = k;
    	}
    }

    dp_cur[mid] = vmid;

    compute(l, mid - 1, optl, opt);
    compute(mid + 1, r, opt, optr);
}


ll pd(){
	set<int> prig;
	frr(i, n){
		prig.insert(v[i]);
		dp_cur[i] = prig.size();
	}

	dp_cur[0] = 0;
	
	for (ll i = 1; i < m; i++){
		memcpy(dp_before, dp_cur, sizeof dp_cur);
		compute(1, n, 1, n);
	}

	return dp_cur[n];
}


int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	
	cin>>n>>m;
	frr(i, n)
		cin>>v[i];
	L = R = 1;
	add(1);	

	cout<<pd()<<endl;
}