#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i,n)     for(int i=0;i<n;i++)
#define frr(i,n)    for(int i=1;i<=n;i++)

#define ms(x,i) memset(x,i,sizeof(x))
#define dbg(x)  cout << #x << " = " << x << endl
#define all(x)  x.begin(),x.end()

#define gnl cout << endl
#define chapa cout << "oi meu chapa" << endl
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
//cout << setprecision(9)<<fixed;

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = (long long)(1e18) + 100;   
const int MAXN = 100100;
const int MAXM = 1001000;
const ll mod=1e9+7;
const int LMAXN = 25;

int n, m, x, y;
ll w[11234];
ll memo[11234][2];

ll pd( int pos, int cor){
	if (pos == m + 1)
		return 0;
	if (pos > m + 1)
		return INF;
	ll &pdm = memo[pos][cor];
	if (pdm != -1)
		return pdm;
	pdm = INF;
	
	for (int i = x; i <= y; i++)
		if (cor == 1)
			pdm = min(pdm, pd( pos + i, 1 - cor) + ( n*i - w[pos + i - 1] + w[pos - 1] ));
		else
			pdm = min(pdm, pd( pos + i, 1 - cor) + (w[pos + i - 1] - w[pos - 1] ));
	return pdm;					
}


int main(){
	fastio;
	char mapa[1123][1123];
	cin>>n>>m>>x>>y;

	frr(i,n)
		frr(j,m)
			cin>>mapa[i][j];
	frr(j,m)
		frr(i,n)
			if (mapa[i][j] == '.')
				w[j]++;
	frr(j,m)
		w[j] += w[j - 1];		

	ms(memo, -1);

	cout<<min(pd(1, 0), pd(1,1))<<endl;
}