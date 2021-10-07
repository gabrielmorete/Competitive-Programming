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

int n;
vi adj[MAXN];

vii edges;

void dfs(int v, int p){
	for (auto x : adj[v])
		if (x != p){
			edges.pb({v, x});
			dfs(x, v);
		}
}

int query(int r){
	set<int> q;

	fr(i, r + 1){
		q.insert(edges[i].fst);
		q.insert(edges[i].snd);
	}

	cout<<"? "<<q.size()<<' ';
	while (!q.empty()){
		cout<<*q.begin()<<' ';
		q.erase(q.begin());
	}
	cout<<endl;

	int x;
	cin>>x;

	return x;
}


signed main(){
	// ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin>>n;

	int x, y;
	fr(i, n - 1){
		cin>>x>>y;
		adj[x].pb(y);
		adj[y].pb(x);
	}

	dfs(1, 1);

	int val = query(n - 2);

	int ini = 0, fim = n - 2, bst = n - 2;

	while (ini <= fim){
		int meio = (ini + fim)/2;

		int aux = query(meio);

		if (aux != val)
			ini = meio + 1;
		else{
			bst = meio;
			fim = meio - 1;			
		}
	}

	cout<<"! "<<edges[bst].fst<<' '<<edges[bst].snd<<endl;
}