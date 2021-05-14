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
#define all(x)  x.begin(), x.end()

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

const int INF = 0x3f3f3f3f;
const ll llINF = (long long)(1e18) + 100;   
const int MAXN = 1e5 + 10;

ll n, k, g1, g2, g3, memo[MAXN][55];
string s;

ll pd(){
	frr(i, 51)
		memo[0][i] = -INF;

	for (int i = 1; i <= n; i++)
		for (int j = 0; j < 51; j++){
			memo[i][j] = memo[i - 1][j]; // fazer nada
			if (i > 2 and j > 0 and s[i - 2] == '.' and s[i - 1] == '#' and s[i] == '.')
				memo[i][j] = max(memo[i][j], memo[i - 3][j - 1]);
			if (i > 1 and s[i] == '.' and s[i - 1] == '.')
				memo[i][j] = max(memo[i][j], memo[i - 2][j] + 1);
		}

	ll rck = count(all(s), '#');

	ll ans = 0;	
	for (ll j = 0; j < 51; j++){
		ll d = memo[n][j];
		if (d >= 0){
			ll res = k;
			ll fr = min(res, n - ((rck - j) + 3 * j + 2 * d));
			ll aux = g1 * fr + g3 * j; // livres
			res -= fr;

			if (g1 > g2){
				fr = min(res, 2 * d);
				aux += g1 * fr;
				if ((fr + 1)/2 < d)
					aux += g2 * (d - (fr + 1)/2);
			}
			else if (2*g1 > g2){
				fr = min(res, 2 * d);
				if (fr%2)
					fr--;
				aux += g1 * fr;
				aux += g2 * (d - fr/2);
			}
			else{
				aux += g2 * d;
			}
			ans = max(ans, aux);
		}
	}	

	return ans;
}


int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin>>n>>k>>g1>>g2>>g3;
	cin>>s;

	reverse(all(s));
	s.pb('a');
	reverse(all(s));

	cout<<pd()<<endl;
}