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
const int MAXN = 2e6 + 10;

int n, m;
vector< array<int, 3> > a, b;

int nxt[MAXN];
vi adj[MAXN];

void swap_atk_def(vector< array<int, 3> > &v){
	for (auto &x : v)
		swap(x[0], x[1]);
}

int vis[MAXN];

void dfs(int v){
	vis[v] = 1;

	for (auto x : adj[v])
		dfs(x);
}

void solve(){
	cin>>n;

	a.resize(n);

	fr(i, n)
		cin>>a[i][0];

	fr(i, n)
		cin>>a[i][1];

	fr(i, n)
		a[i][2] = i;

	cin >> m;	

	b.resize(m);

	fr(i, m)
		cin>>b[i][0];

	fr(i, m)
		cin>>b[i][1];

	fr(i, m)
		b[i][2] = n + i;

	// build the graph	
	swap_atk_def(a);
	sort(all(a));	

	sort(all(b));
	{
		int p = m, bst = -1;
		for (int i = n - 1; i >= 0; i--){
			while (p > 0 and b[p - 1][0] > a[i][0]){
				p--;
				if (bst == -1 or b[p][1] > b[bst][1])
					bst = p;
			}

			if (bst != -1){
				nxt[ a[i][2] ] = b[bst][2];
				adj[ b[bst][2] ].push_back( a[i][2] );
			}
			else
				nxt[a[i][2]] = -1;
		}
	}

	swap_atk_def(a); // back to original
	sort(all(a));	

	swap_atk_def(b);
	sort(all(b));


	int p = n, bst = -1;
	for (int i = m - 1; i >= 0; i--){
		while (p > 0 and a[p - 1][0] > b[i][0]){
			p--;
			if (bst == -1 or a[p][1] > a[bst][1])
				bst = p;
		}

		if (bst != -1){
			nxt[ b[i][2] ] = a[bst][2];
			adj[ a[bst][2] ].push_back( b[i][2] );
		}
		else
			nxt[b[i][2]] = -1;
	}

	swap_atk_def(b);
	sort(all(b));

	// fr(i, n + m)
	// 	dbg(nxt[i]);

	// graph is built, find the answer

	int ansa = 0;
	for (int i = 0; i < n; i++)
		if (nxt[i] == -1) //winning
			dfs(i);

	fr(i, n)
		ansa += vis[i];

	fr(i, n + m)
		vis[i] = 0;

	int ansb = 0;
	for (int i = n; i < n + m; i++){
		if (nxt[i] == -1) //winning
			dfs(i);
	}

	fr(i, n)
		ansb += vis[i];

	cout << ansa << ' ' << (n - ansa - ansb) << ' ' << ansb << endl;

	fr(i, n + m + 10){
		vis[i] = 0;
		adj[i].clear();
	}
}


signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int t;
	cin>>t;

	while (t--)
		solve();
}