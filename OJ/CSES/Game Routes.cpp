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
const int MAXN = 4e5 + 10;

const ll mod = 1000000007;

ll n, m, indeg[MAXN], ans[MAXN];
vector<int> adj[MAXN];

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin>>n>>m;
	fr(i, m){
		int a, b;
		cin>>a>>b;
		indeg[b]++;
		adj[a].pb(b);
	}

	queue<int> fila;

	ans[1] = 1;

	frr(i, n)
		if (indeg[i] == 0)
			fila.push(i);

	while (!fila.empty()){
		int v = fila.front();
		fila.pop();

		for (auto x : adj[v]){
			indeg[x]--;
			ans[x] += ans[v];
			ans[x] %= mod;
			
			if (indeg[x] == 0)
				fila.push(x);
		}
	}	

	cout<<ans[n]<<endl;
}