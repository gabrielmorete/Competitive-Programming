#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fst first
#define snd second

#define fr(i,n)     for (int i = 0; i < n; i++)
#define frr(i,n)    for (int i = 1; i <= n; i++)

//#define endl '\n'
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

pii v[MAXN];
int vv[MAXN];
vector<int> tree[4 * MAXN];

void build(int node, int l, int r){
	if (l == r) return tree[node].push_back(v[l].snd);
	int meio = (l + r)/2;
	build(node<<1, l, meio); 
	build(node<<1|1, meio + 1, r);
	std::merge(all(tree[node<<1]), all(tree[node<<1|1]), back_inserter(tree[node]));
}

// Para consultar k-ésimo elemento em [l:r] modifique a build com
// if (l == r) return tree[node].push_back(v[l].snd);
// em que v = {valor, indice} é um vetor ordenado contendo os
// elementos do vetor original e seus indices originais.
// A função retorna a posição original do k-ésimo elemento e não
// o seu valor.

//#error ordene o vetor {valor, indice}	
int query_kth(int node, int l, int r, int ql, int qr, int val){
	if (l == r)
		return tree[node][0]; // posição original do k-ésimo elemento
	int fst = lower_bound(all(tree[node<<1]), ql) - tree[node<<1].begin(); // filho esquerdo
	int lst = lower_bound(all(tree[node<<1]), qr + 1) - tree[node<<1].begin();
	int meio = (l + r)/2;
	int amnt = lst - fst; // # de elementos no filho esquerdo
	if (amnt >= val) // val está no filho esquerdo
		return query_kth(node<<1, l, meio, ql, qr, val);
	else
		return query_kth(node<<1|1, meio + 1, r, ql, qr, val - amnt);
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, q;
	cin>>n>>q;

	frr(i, n){
		cin>>vv[i];
		v[i] = {vv[i], i};
	}

	sort(v + 1, v + 1 + n);

	build(1, 1, n);	

	int l, r, k;
	while (q--){
		cin>>l>>r>>k;
		cout<<vv[query_kth(1, 1, n, l, r, k)]<<endl;
	}	
}