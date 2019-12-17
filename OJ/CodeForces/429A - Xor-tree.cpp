#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i,n)     for(int i=0;i<n;i++)
#define frr(i,n)    for(int i=1;i<=n;i++)

#define ms(x,i) memset(x,i,sizeof(x))
#define dbg(x)  cout << #x << " = " << x << endl
#define all(x)  x.begin(),x.end()

#define gnl cout << endl
#define chapa cout << "oi meu chapa" << endl
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
//cout << setprecision(9)<<fixed;

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = (long long)(1e18) + 100;   
const int MAXN = 100100;
const int MAXM = 1001000;
const ll mod=1e9+7;
const int LMAXN = 25;

vi adj[112345], flip;
int n, ini[112345], goal[112345], vis[112345];

void dfs(int v, int hgt, int fi, int fp){
	vis[v] = 1;

	if ((hgt%2 and fi) or (hgt%2 == 0 and fp))
		ini[v] = 1 - ini[v];
	if (ini[v] != goal[v]){
		flip.pb(v);
		if (hgt%2)
			fi = 1 - fi;
		else
			fp = 1 - fp;
	}
	for (int x : adj[v])
		if (!vis[x])
			dfs(x, hgt + 1, fi, fp);
}


int main(){
	fastio;
	cin>>n;
	int a, b;
	fr(i,n - 1){
		cin>>a>>b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	frr(i, n)
		cin>>ini[i];
	frr(i, n)
		cin>>goal[i];
	dfs(1, 0, 0, 0);
	cout<<flip.size()<<endl;
	for (int x : flip)
		cout<<x<<endl;	
}