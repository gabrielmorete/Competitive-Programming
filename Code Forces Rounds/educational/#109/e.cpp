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
const ll mod = 998244353;

ll n, m, dst[MAXN][22];
ll perm;

ll fastxp(ll base, ll exp){
	ll ans = 1;
	while (exp){
		if (exp & 1)
			ans = (base * ans) % mod;
		base = (base * base) % mod;
		exp >>= 1;
	}
	return ans;
}



int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin>>n>>m;

	ll x;
	fr(i, n)
		fr(j, m){
			cin>>x;
			dst[j][n + 1 - x]++;
		}

	perm = 1;
	for (ll i = 1; i <= n; i++)
		perm = (perm * i) % mod;
	perm = fastxp(perm, mod - 2);


	ll ans = 0;
	fr(i, m){
		ll aux = 1, rem = 0;
		fr(j, n){
			rem += dst[i][j]; // pode entrar na permutação sem me cobrir
			aux = (aux * rem) % mod; // numero de permutações
			rem = max(0ll, rem - 1); // diminui 1 opção
		}
		aux = (aux * perm) % mod;
		ans = (ans + mod + 1 - aux) % mod; // lembra que calculamos a probabilidade não pegar
	}
	cout<<ans<<endl;
}