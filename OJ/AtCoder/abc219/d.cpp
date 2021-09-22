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
const int MAXN = 1e5 + 10;

int n, x, y, a[310], b[310];
int memo[301][301][301];

int pd(int pos, int xn, int yn){
	if (xn >= x and yn >= y)
		return 0;

	xn = min(xn, x);
	yn = min(yn, y);

	if (pos >= n)
		return 10000;

	int &pdm = memo[pos][xn][yn];
	if (pdm != -1)
		return pdm;

	pdm = 1000;

	pdm = min(pdm, pd(pos + 1, xn, yn));
	pdm = min(pdm, pd(pos + 1, xn + a[pos], yn + b[pos]) + 1);

	return pdm;
}


signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin>>n>>x>>y;

	fr(i, n)
		cin>>a[i]>>b[i];

	memset(memo, -1, sizeof memo);
	
	int ans = pd(0, 0, 0);

	if (ans > n)
		cout<<-1<<endl;
	else
		cout<<ans<<endl;	
}