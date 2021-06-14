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
const int MAXN = 5e5 + 10;
const int LMAXN = 25;

ll n, a[MAXN], c[MAXN];

// memo[v][i] é o acentral a distancia 2^i de v
int pai[MAXN], memo[MAXN][LMAXN]; 

void put_in(int v){
	memo[v][0] = pai[v]; 
	for (int i = 1; i < LMAXN; i++) 
		memo[v][i] = memo[memo[v][i - 1]][i - 1];
}

pair<ll, ll> query(ll v, ll qnt){
	ll val, tot, aux;
	val = tot = 0;

	int u;
	do{
		u = v;
		for (int i = LMAXN - 1; i >= 0; i--)
			if (a[memo[u][i]] > 0) // tem ouro lá em cima
				u = memo[u][i];
		// fui o mais alto que deu, mais barato
		aux = min(a[u], qnt - tot);
		val += aux * c[u];
		tot += aux;
		a[u] -= aux;
	} while (u != v and tot < qnt);

	return {tot, val};
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin>>n>>a[0]>>c[0];
	fill(memo[0], memo[0] + LMAXN, 0); // raiz

	pair<ll, ll> aux;
	int typ, x, y, z;
	frr(i, n){
		cin>>typ;
		if (typ == 1){
			cin>>x>>y>>z;
			a[i] = y;
			c[i] = z;
			pai[i] = x;
			put_in(i); // coloca i
		}
		else{
			cin>>x>>y;
			aux = query(x, y);
			cout<<aux.fst<<' '<<aux.snd<<endl;
		}
	}
}