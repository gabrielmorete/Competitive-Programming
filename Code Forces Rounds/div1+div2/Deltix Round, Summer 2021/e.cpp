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
const int MAXN = 2e5 + 10;
const int LMAXN = 25;


ll n, q, a[MAXN], b[MAXN], dif[MAXN];


ll tablemin[MAXN][LMAXN], tablemax[MAXN][LMAXN], lg[MAXN];

void build_rmq(){
	for (int i = 0; i < n + 1; i++)
		tablemin[i][0] = tablemax[i][0] = dif[i];

	for (int j = 1; j < LMAXN; j++)
    	for (int i = 0; i + (1 << j) <= n + 1; i++){
        	tablemin[i][j] = min(tablemin[i][j - 1], tablemin[i + (1 << (j - 1))][j - 1]);
          	tablemax[i][j] = max(tablemax[i][j - 1], tablemax[i + (1 << (j - 1))][j - 1]);
    	}

	lg[1] = 0;
	for (int i = 2; i < MAXN; i++)
	    lg[i] = lg[i/2] + 1;    
}

ll query_min(int l, int r){
	int aux = lg[r - l + 1];
	return min(tablemin[l][aux], tablemin[r - (1 << aux) + 1][aux]);
}

ll query_max(int l, int r){
	int aux = lg[r - l + 1];
	return max(tablemax[l][aux], tablemax[r - (1 << aux) + 1][aux]);
}


int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin>>n>>q;

	frr(i, n)
		cin>>a[i];
	frr(i, n)
		cin>>b[i];

	frr(i, n)
		dif[i] = b[i] - a[i];
	frr(i, n)
		dif[i] += dif[i - 1];

	build_rmq();

	int l, r;	
	while (q--){
		cin>>l>>r;

		ll mn = query_min(l, r) - dif[l - 1];
		ll mx = query_max(l, r) - dif[l - 1];

		if (mn < 0 or dif[r] != dif[l - 1])
			cout<<-1<<endl;
		else
			cout<<mx<<endl;
	}	
}