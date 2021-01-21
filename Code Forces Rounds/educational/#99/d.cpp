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
const int MAXN = 1e5 + 10;

int n, x, a[501];

int memo[502][502][502];

int pd(int pos, int lval, int xnow){
	if (pos >= n)
		return 0;

	int &pdm = memo[pos][lval][xnow];
	if (pdm != -1)
		return pdm;

	pdm = INF;

	if (a[pos] >= lval) // posso continuar sem mudar e ver no que da
		pdm = min(pdm, pd(pos + 1, a[pos], xnow)); // proxima posição, ultimo sou eu, mesmo x
	
	if (xnow >= lval and a[pos] > xnow) // vou mudar meu valor pois posso
		pdm = min(pdm, 1 + pd(pos + 1, xnow, a[pos]));

	return pdm;
}



void solve(){
	cin>>n>>x;
	fr(i, n)
		cin>>a[i];

	set<int> q;	

	q.insert(x);
	fr(i, n)
		q.insert(a[i]);

	int val[501];	

	int cnt = 1;
	while (!q.empty()){
		val[*q.begin()] = cnt++;
		q.erase(q.begin());
	}	
	
	x = val[x];
	fr(i, n)
		a[i] = val[a[i]];	

	fr(i, n + 2) fr(j, n + 2) fr(k, n + 2)
		memo[i][j][k] = -1;	

	int ans = pd(0, 0, x);
	if (ans >= n + 1)
		cout<<-1<<endl;
	else
		cout<<ans<<endl;
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int T;

	cin>>T;

	while (T--)
		solve();
}