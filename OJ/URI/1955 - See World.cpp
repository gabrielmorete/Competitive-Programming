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
#define all(x)  x.begin(),x.end()

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

const int INF = 0x3f3f3f3f;
const ll llINF = (long long)(1e18) + 100;   
const int MAXN = 1e3 + 10;

int n, vis[MAXN];
vector<int> adj[MAXN];

bool dfs(int v, int cor){
	vis[v] = cor;

	for (int x : adj[v]){
		if (vis[x] == 0){
			if (dfs(x, cor == 1? 2 : 1) == false)
				return false;
		}
		else if (vis[x] == cor) // circuito impar
			return false;
	}	

	return true;	
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	
	cin>>n;

	int x;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++){
			cin>>x;
			if (x == 0) // grafo complementar
				adj[i].pb(j);
		}

	memset(vis, 0, sizeof vis);

	bool bip = 1;

	for (int i = 0; i < n; i++)	
		if (vis[i] == 0)
			bip &= dfs(i, 1);

	if (bip)
		cout<<"Bazinga!"<<endl;
	else
		cout<<"Fail!"<<endl;	
}