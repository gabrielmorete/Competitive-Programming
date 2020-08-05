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
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
//cout << setprecision(9)<<fixed;

#define dbg(x)  cout << #x << " = " << x << endl
#define all(x)  x.begin(),x.end()

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

const ll llINF = (long long)(1e18) + 100;   
const int MAXN = 1e6 + 10;

const int INF = 1e6 + 100;
const ll mod = 1e9 + 7;

ll fastxp(ll base, ll exp){
	ll ans = 1;
	while (exp){
		if (exp & 1)
			ans = (ans * base) % mod;
		base = (base * base) % mod;
		exp >>= 1;
	}
	return ans;
}

void solve(){
	ll n, p, v[MAXN];
	
	cin>>n>>p;

	fr(i, n)
		cin>>v[i];

	sort(v, v + n);	
	reverse(v, v + n);
	ll pos = 0, res = 0, sum = 0, pwr = INF, aux, dlt;
	bool inf = 0; // v / (p**k) > n

	while (pos < n){
		aux = v[pos];
		dlt = pwr - aux;
		pwr = aux;

		res = (res * fastxp(p, dlt)) % mod;

		// atualizar a soma dos exps, 2**20 > INF

		for (int i = 0; i < min(dlt, 20ll); i++){
			sum *= p;
			if (sum > INF)
				inf = 1;
		}

		// resolver todos com valor aux

		while (pos < n and v[pos] == aux){
			if (sum > 0 or inf){
				sum--;
				res += mod - 1;
			}
			else{
				sum++;
				res++;
			}
			res %= mod;
			pos++;
		}

	}
	
	res = (res * fastxp(p, pwr)) % mod;
	cout<<res<<endl;
}

int32_t main(){
	fastio;
	int T;
	cin>>T;
	while (T--)
		solve();
}