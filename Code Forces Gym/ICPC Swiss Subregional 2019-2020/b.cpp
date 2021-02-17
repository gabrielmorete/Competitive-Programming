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

const ll mod = 1e9 + 7;

int n, pi[MAXN], cicle[MAXN];
int sz, vis[MAXN];
ll memo[MAXN];

ll pd_par(ll val, ll freq){
	memo[0] = 1; // uma forma de fazer vazio
	memo[1] = memo[2] = memo[3] = 0; // impossível

	for (ll fr = 4; fr <= freq; fr += 4){ // formar de combinar 4 ciclios de tamanho val em 1
		memo[fr] = (val * val * val) % mod;
		memo[fr] = (memo[fr] * (((fr - 1) * (fr - 2) * (fr - 3)) % mod)) % mod;
		memo[fr] = (memo[fr] * memo[fr - 4]) % mod;
	}

	return memo[freq];
}

ll pd_impar(ll val, ll freq){
	memo[0] = 1; // 1 forma de formar o vazio
	memo[1] = 1; // 1 forma de fazer um ciclo
	memo[2] = 1 + val; // 2 separados + ligar os dois em qualquer posição
	memo[3] = 1 + 3 * val; // deixar todos sozinhos ou unir dois

	for (ll fr = 4; fr <= freq; fr++){
		memo[fr] = (val * val * val) % mod; // unir os 4
		memo[fr] = (memo[fr] * (((fr - 1) * (fr - 2) * (fr - 3)) % mod)) % mod;
		memo[fr] = (memo[fr] * memo[fr - 4]) % mod;

		ll aux = ((fr - 1) * val) % mod; // unir dois
		aux = (aux * memo[fr - 2]) % mod;

		memo[fr] = (memo[fr] + aux + memo[fr - 1]) % mod; // manter sozinho
	}

	return memo[freq];
}	


int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin>>n;

	fr(i, n)
		cin>>pi[i];

	for (int i = 0; i < n; i++){ // dfs
		if (!vis[i]){
			sz = 0;
			
			int v = i;
			while (!vis[v]){
				vis[v] = 1;
				sz++;
				v = pi[v];
			}

			cicle[sz]++;
		}
	}

	ll ans = 1;

	for	(int i = 1; i <= n; i++){
		if (i % 2)
			ans = (ans * pd_impar(i, cicle[i])) % mod;
		else{
			if (cicle[i] % 4){ // impossível
				cout<<0<<endl;
				return 0;
			}
			ans = (ans * pd_par(i, cicle[i])) % mod;
		}
	}

	cout<<ans<<endl;
}