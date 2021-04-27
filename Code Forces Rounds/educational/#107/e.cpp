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
const int MAXN = 3e5 + 10;
const ll mod = 998244353;

ll n, m, pwr[MAXN], memo[MAXN];
string mapa[MAXN];

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	memo[0] = memo[1] = 1;
	memo[2] = 3;
	pwr[0] = 1;
	pwr[1] = 2;
	pwr[2] = 4;	

	for (int i = 3; i < MAXN; i++){
		memo[i] = (memo[i - 2] + pwr[i - 1]) % mod;
		pwr[i] = (pwr[i - 1]<<1) % mod;
	}

	cin>>n>>m;

	fr(i, n)
		cin>>mapa[i];

	ll wht = 0;	
	fr(i, n)
		fr(j, m)	
			wht += mapa[i][j] == 'o';
	
	ll ans = 0, q;
	
	for (int i = 0; i < n; i++){
		q = 0;
		for (int j = 0; j < m - 1; j++){
			if (mapa[i][j] == '*')
				q = 0;
			else{
				if (mapa[i][j + 1] == 'o')
					ans = (ans + memo[q] * pwr[wht - 2 - q]) % mod;
				q++;
			}
		}
	}	

	for (int j = 0; j < m; j++){
		q = 0;
		for (int i = 0; i < n - 1; i++){
			if (mapa[i][j] == '*')
				q = 0;
			else{
				if (mapa[i + 1][j] == 'o')
					ans = (ans + memo[q] * pwr[wht - 2 - q]) % mod;
				q++;
			}
		}
	}	

	cout<<ans<<endl;
}