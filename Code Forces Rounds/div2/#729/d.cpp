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
const int MAXN = 5e2 + 10;
const ll mod = 998244353;

ll n, a[MAXN];
ll memo[MAXN][MAXN], bad;

ll pd(ll pos, ll small){
	if (pos == n)
		return 1;
	
	ll &pdm = memo[pos][small];
	if (pdm != -1)
		return pdm;

	pdm = pd(pos + 1, small); // faz nada

	if (pos == bad) // fixado, passa pro proximo estado
		return pdm;
	
	if (a[pos] > 0){
		if (a[pos] < a[bad])
			pdm = (pdm + pd(pos + 1, small + 1)) % mod; // se coloca, aumenta small
		
		if (a[pos] == a[bad] and pos < bad)
			pdm = (pdm + pd(pos + 1, small + 1)) % mod; // se coloca, aumenta small
		
		if(a[pos] > a[bad] or (a[pos] == a[bad] and pos > bad))
			pdm = (pdm + pd(pos + 1, small)) % mod; // se coloca, não muda nada
	}
	else{
		if (small > 0)
			pdm = (pdm + pd(pos + 1, small - 1)) % mod;
		if (small == 0 and pos < bad) 
			pdm = (pdm + pd(pos + 1, 0)) % mod;
	}

	return pdm;
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin>>n;

	string c;
	int x;
	fr(i, n){
		cin>>c;
		if (c == "+"){
			cin>>x;
			a[i] = x;
		}
		else{
			a[i] = -1;
		}
	}

	ll ans = 0;

	for (int i = 0; i < n; i++){
		if (a[i] > 0){
			memset(memo, -1, sizeof memo);
			bad = i;
			ll aux = pd(0, 0) % mod;
			ans = (ans + aux * a[i]) % mod;
		}
	}

	cout<<ans<<endl;
}