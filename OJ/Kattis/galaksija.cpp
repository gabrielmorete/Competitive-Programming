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

const int INF = 0x3f3f3f3f;
const ll llINF = (long long)(1e18) + 100;   
const int MAXN = 1e5 + 10;

// de fato dsu on tree
// um pouco diferente da tecnica generica de small to large

ll n, a[MAXN], b[MAXN], c[MAXN];
ll id[MAXN], sz[MAXN], path[MAXN], qry[MAXN], ans[MAXN];
ll sum;

map<ll, vector<ll>> tree[MAXN]; // caras da subávore de b que tem path[v]

void merge(int a, int b, int c){
	if (sz[id[a]] < sz[id[b]])
		swap(a, b);

	for (auto x : tree[id[b]]) // para todos os valores de caminho na arvore de b
		for (int v : x.snd) // anda todos os vertices do valor
			sum += tree[id[a]][path[a] ^ c ^ path[b] ^ path[v]].size(); // soma xor zero

	int old = path[b], ob = id[b];
  	for (auto x : tree[ob]) {
		for (auto v: x.second) {
     		path[v] ^= old ^ c ^ path[a];
      		id[v] = id[a]; // sempre filho direto
      		tree[id[a]][path[v]].push_back(v); // adciona na subárvore de a
    	}
 	}

 	sz[id[a]] += sz[ob];	
	tree[ob].clear();
}

int32_t main(){
	fastio;
	cin>>n;
	
	fr(i, n - 1)
		cin>>a[i]>>b[i]>>c[i]; // aresta i

	fr(i, n - 1){
		cin>>qry[i];
		qry[i]--;
	}

	frr(i, n){
		tree[i][0].pb(i);
		id[i] = i;
		sz[i] = 1;
	}

	for (int i = n - 2; i >= 0; i--){ // vamos fazer ao contrario, colocando arestas
		merge(a[qry[i]], b[qry[i]], c[qry[i]]);
		ans[i] = sum;
	}

	fr(i, n)
		cout<<ans[i]<<endl;
}