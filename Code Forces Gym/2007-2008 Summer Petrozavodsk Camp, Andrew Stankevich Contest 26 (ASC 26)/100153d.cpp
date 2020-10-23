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
#define all(x)  x.begin(),x.end()

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

const int INF = 0x3f3f3f3f;
const ll llINF = (long long)(1e18) + 100;   
const int MAXN = 1e2 + 10;

typedef tuple<int, int, int> tup;

int n;
vector<tup> edges, ans;

int id[MAXN];

void init(){
	for (int i = 0; i < MAXN; i++)
		id[i] = i;
}

int find(int a){
	if (a == id[a]) return a;
	return id[a] = find(id[a]);
}

bool merge(int a, int b){
	a = find(a);
	b = find(b);
	if (a == b) return false;
	id[a] = b;
	return true;
}

int m_flow[MAXN][MAXN];
vii adj[MAXN];

// Se existe o grafo existe uma árvore de Gomory-Hu
// com os mesmos valores. Uma max spanning tree é uma
// resposta, caso haja, pois é a arvore que menos restringe
// o fluxo. Caso haja alguem com fluxo excedente, algum
// par de vértices nesse caminho não seria satisfeito se 
// o fluxo diminuisse, logo, não há resposta.

void kruskal(){ // monta max spanning tree
	init();
	sort(all(edges));
	reverse(all(edges));

	int u, v, w;
	for (auto x : edges){
		tie(w, u, v) = x;
		if (merge(u, v)){
			adj[u].pb({v, w});
			adj[v].pb({u, w});
			ans.pb({u, v, w});
		}
	}
}

bool dfs(int v, int p, int ref, int val){ // checa a árvore obtida
	if (v != p and m_flow[ref][v] != val)
		return false;
	for (auto u : adj[v])
		if (u.fst != p){
			if (dfs(u.fst, v, ref, min(val, u.snd)) == false)
				return false;
		}
	return true;	
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	freopen("matrix.in", "r", stdin); 
	freopen("matrix.out", "w", stdout);
	cin>>n;

	int x;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++){
			cin>>x;
			if (i > j)
				edges.pb({x, i, j});
			m_flow[i][j] = x;
		}

	kruskal();	

	for (int v = 1; v <= n; v++)
		if (!dfs(v, v, v, INF)){
			cout<<"NO"<<endl;
			return 0;
		}

	cout<<"YES"<<endl;	
	cout<<ans.size()<<endl;
	int a, b, c;
	for (auto x : ans){
		tie(a, b, c) = x;
		cout<<a<<' '<<b<<' '<<c<<endl;
	}
}