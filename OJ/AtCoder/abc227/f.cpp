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
const int MAXN = 65;

ll mapa[MAXN][MAXN], memo[MAXN][MAXN][MAXN];

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	ll h, w, k;
	cin>>h>>w>>k;

	fr(i, h)
		fr(j, w)
			cin>>mapa[i][j];
	
	ll ans = llINF;
	
	fr(ln, h)
		fr(cl, w){
			ll x = mapa[ln][cl];
			fr(l, k + 1) fr(i, h) fr(j, w)
				memo[l][i][j] = llINF;		

			if (mapa[0][0] >= x) 
				memo[1][0][0] = mapa[0][0];
			if (mapa[0][0] <= x) // custo exatamente x, pode contar ou não
				memo[0][0][0] = 0;

			fr(l, k + 1)
				fr(i, h)
					fr(j, w){
						if (i != 0){
							if (mapa[i][j] >= x and l > 0)
								memo[l][i][j] = min(memo[l][i][j], memo[l - 1][i - 1][j] + mapa[i][j]);
							if (mapa[i][j] <= x)
								memo[l][i][j] = min(memo[l][i][j], memo[l][i - 1][j]);
						}
						if (j != 0){
							if (mapa[i][j] >= x and l > 0)
								memo[l][i][j] = min(memo[l][i][j], memo[l - 1][i][j - 1] + mapa[i][j]);
							if (mapa[i][j] <= x)
								memo[l][i][j] = min(memo[l][i][j], memo[l][i][j - 1]);
						}
					}

			ans = min(ans, memo[k][h - 1][w - 1]);		
	}

	cout<<ans<<endl;
}