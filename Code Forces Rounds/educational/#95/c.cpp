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
const int MAXN = 2e5 + 10;

int memo[MAXN][2]; // 0 friend 1 me
int n, a[MAXN];

int pd(int pos, int who){
	if (pos >= n)
		return 0;

	int &pdm = memo[pos][who];
	if (pdm != -1)
		return pdm;

	if (who == 0){
		pdm = pd(pos + 1, 1) + a[pos];
		pdm = min(pdm, pd(pos + 2, 1) + a[pos] + a[pos + 1]);
	}
	else{
		pdm = min(pd(pos + 1, 0),  pd(pos + 2, 0));	
	}

	return pdm;
}

void solve(){
	cin>>n;
	fr(i, n)
		cin>>a[i];

	fr(i, n + 10){
		memo[i][0] = -1;
		memo[i][1] = -1;
	}	

	cout<<pd(0, 0)<<endl;	
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int T;
	cin>>T;

	while (T--)
		solve();
}