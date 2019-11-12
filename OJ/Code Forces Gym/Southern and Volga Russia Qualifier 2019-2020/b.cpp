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

int n, k, pa[212345], pode[212345], seen[212345];
bool color[212345];
vi adj[212345];

void dfs( int v){
	int vis = 0;
	for (auto x : adj[v]) {
		if (x == pa[v])
			continue;
		if (seen[x] == -1) {
			pa[x] = v;
			dfs(x);
		}
		if (seen[x] == 0)
			pode[v] = 0;
		else
			vis += seen[x];
	}
	if (color[v])
		vis++;

	if (pa[v] == -1 and vis == k and pode[v] == -1){ 
		pode[v] = 1;
	}

	if (pode[v] == -1 and k - vis > 0)
		pode[v] = 1;
	seen[v] = vis;		
}


int main(){
	fastio;
	cin>>n>>k;

	int x;

	ms(pode, -1);
	
	fr(i,k){
		cin>>x;
		color[x] = true;
	}

	int y;
	fr(i,n - 1){
		cin>>x>>y;
		adj[x].pb(y);
		adj[y].pb(x);
	}

	ms( seen, -1);
	ms( pode, -1);
	frr(i,n){
		if(seen[i] == -1 and color[i] == 0){
			pa[i] = -1;
			dfs(i);
			break;
		}
	}
	
	int ans = 0;

	frr(i,n)
		if (pode[i] > 0 and color[i] == 0)
			ans++;

	cout<<ans<<endl;	
	frr(i,n)
		if(pode[i] > 0 and color[i] == 0)
			cout<<i<<' ';
	gnl;	
}