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

int n, deg[MAXN], val[MAXN];
vii adj[MAXN];

int32_t main(){
	fastio;
	cin>>n;

	int a, b;
	fr(i, n - 1){
		cin>>a>>b;
		adj[a].pb({b, i + 1});
		adj[b].pb({a, i + 1});
		deg[a]++;
		deg[b]++;
	}

	fill(val, val + MAXN, -1);
	
	int cnt = 0;
	frr(v, n) // Coloca nas folhas
		if (deg[v] == 1 and val[ adj[v][0].snd ] == -1){
			val[ adj[v][0].snd ] = cnt++;
		}

	frr(i, n - 1)
		if (val[i] == -1)
			val[i] = cnt++;	
	
	frr(i, n - 1)
		cout<<val[i]<<endl;	
}