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

int id[MAXN], sz[MAXN];

int find(int a){
	if (a == id[a])
		return a;
	return id[a] = find(id[a]);
}

int tot;

void merge(int a, int b){
	a = find(a);
	b = find(b);

	if (a == b) return;

	if (sz[a] < sz[b])
		swap(a, b);

	tot--;

	id[b] = a;
	sz[a] += sz[b];
}

int n, m;
vi adj[MAXN];

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin>>n>>m;

	fr(i, m){
		int x, y;
		cin>>x>>y;

		if (x > y)
			adj[y].pb(x);
		else
			adj[x].pb(y);
	}

	vi ans;

	frr(i, n){
		id[i] = i;
		sz[i] = 1;
	}


	for (int i = n; i > 0; i--){
		ans.pb(tot);

		tot++;

		for (auto x : adj[i])
			merge(i, x);
	}

	reverse(all(ans));

	for (auto x : ans)
		cout<<x<<endl;
}