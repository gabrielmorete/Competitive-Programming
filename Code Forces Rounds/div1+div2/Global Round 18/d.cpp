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
const int MAXN = 2e5 + 10;

typedef tuple<int, int, int> tup;

int n, m;
vector<tup> ans;
vii adj[MAXN];
vi comp[MAXN];

int id[MAXN], sz[MAXN], cor[MAXN];

int find(int a){
	return id[a] = (a == id[a]? a : find(id[a]));
}

bool ok;

void merge(int a, int b, int typ){
	int ida = find(a);
	int idb = find(b);

	if (ida == idb){ // mesma componente, não precisa adicionar aresta
		if ((cor[a] != cor[b]) != typ){ // ciclo impar
			ok = 0;
		}
	}
	else{
		int muda = (cor[a] != cor[b]) != typ; // tem que flipar a cor da menor componente?
		if (sz[ida] < sz[idb])
			swap(ida, idb);
		for (auto v : comp[idb]){
			if (muda)
				cor[v] ^= 1; // muda a cor da menor
			comp[ida].pb(v);
		}
		sz[ida] += sz[idb]; // junta as componentes
		id[idb] = ida;
	}
}


void dfs(int v, int p, int val){
	if (val == -1 and v != p) // preciso determinar o valor da aresta
		ans.pb({v, p, cor[v] ^ cor[p]});

	for (auto &[x, c] : adj[v])
		if (x != p)
			dfs(x, v, c);
}

void solve(){
	ans.clear();
	ok = 1;

	cin>>n>>m;

	frr(i, n){
		id[i] = i;
		sz[i] = 1;
		cor[i] = 0;
		comp[i] = {i};
		adj[i].clear();
	}

	fr(i, n - 1){
		int a, b, c;
		cin>>a>>b>>c;
		adj[a].pb({b, c});
		adj[b].pb({a, c});

		if (c >= 0){
			ans.pb({a, b, c});
			merge(a, b, (int)(__builtin_popcount(c)) % 2);	
		}
	}

	fr(i, m){
		int a, b, c;
		cin>>a>>b>>c;
		merge(a, b, c);
	}

	if (!ok){
		cout<<"NO"<<endl;
		return;
	}		

	dfs(1, 1, -1);

	cout<<"YES"<<endl;

	for (auto &[a, b, c] : ans)
		cout<<a<<' '<<b<<' '<<c<<endl;
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;
	while (T--)
		solve();
}