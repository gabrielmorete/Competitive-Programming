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
int n, m, a, b, c;
ll cst[212345];
vi adj[212345];

void bfs(int st, int *dist){
	frr(i, n)
		dist[i] = -1;

	queue<int> fila;
	
	fila.push(st);
	dist[st] = 0;

	int vtx;
	while (!fila.empty()){
		vtx = fila.front();
		fila.pop();
		
		for (int x : adj[vtx]){
			if (dist[x] == -1){
				dist[x] = dist[vtx] + 1;
				fila.push(x);
			}
		}
	}
}

void solve(){
	cin>>n>>m>>a>>b>>c;
	frr(i, n)
		adj[i].clear();
	
	frr(i, m)
		cin>>cst[i];		
	
	int x, y;
	fr(i, m){
		cin>>x>>y;
		adj[y].pb(x);
		adj[x].pb(y);
	}

	sort (cst + 1, cst + m + 1);
	frr(i, m){
		cst[i] += cst[i - 1];
	}
	
	int dist[3][212345];

	bfs(a, dist[0]);
	bfs(b, dist[1]);
	bfs(c, dist[2]);


	ll ans = llINF;

	int bx, ax, cx;
	frr(i, n){
		ax = dist[0][i];
		bx = dist[1][i];
		cx = dist[2][i];
		if (ax + bx + cx > m)
			continue;
		ans = min(ans, cst[bx] + cst[ax + bx + cx]);
	}
	cout<<ans<<endl;
}

int main(){
	fastio;
	int t;
	cin>>t;
	while (t--)
		solve();
}