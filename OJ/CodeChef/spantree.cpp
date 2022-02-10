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
const int MAXN = 4e5 + 10;

int n, id[MAXN], ncmp;
vi cmp[MAXN];

int find(int a){
	if (a == id[a])
		return a;
	return id[a] = find(id[a]);
}

void merge(int a, int b){
	a = find(a);
	b = find(b);

	if (a == b) return;

	if (cmp[a].size() < cmp[b].size())
		swap(a, b);

	id[b] = a;
	for (auto x : cmp[b])
		cmp[a].pb(x);
	cmp[b].clear();
}


typedef array<ll, 3> edge;

void answer(ll val){
	cout<<"2 "<<val<<endl;
	exit(0);
}

edge query_cmp(int r){
	r = find(r);

	int m = (n - (int)(cmp[r].size()));
	// optimization, always ask smaller
	if (cmp[r].size() <= m){ 
		cout<<"1 "<<cmp[r].size()<<' '<<m<<endl;
		for (auto x : cmp[r])
			cout<<x<<' ';
		cout<<endl;
		frr(i, n)
			if (find(i) != r)
				cout<<i<<' ';
		cout<<endl;
	}
	else{
		cout<<"1 "<<m<<' '<<cmp[r].size()<<endl;
		frr(i, n)
			if (find(i) != r)
				cout<<i<<' ';
		cout<<endl;
		for (auto x : cmp[r])
			cout<<x<<' ';
		cout<<endl;
	}

	ll u, v, w;
	cin>>u>>v>>w;
	assert(u != -1); // disconnected

	return {w, u, v};
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin>>n;
	frr(i, n){
		id[i] = i;
		cmp[i] = {i};
	}

	ncmp = n;
	ll ans = 0;

	while (ncmp > 1){ // at most logn iterations
		vector<edge> edges;
		frr(i, n)
			if (find(i) == i){
				edge e = query_cmp(i); // I will query the smallest edge crossing the cut of component i
				edges.pb(e);
			}

		sort(all(edges)); // sorting by cost

		for (auto e : edges)
			if (find(e[1]) != find(e[2])){
				ans += e[0];
				merge(e[1], e[2]);
				ncmp--;
			}	
	}

	answer(ans);
}