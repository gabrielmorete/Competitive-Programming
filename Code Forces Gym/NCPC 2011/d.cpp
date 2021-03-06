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
 
int f, s, g, u , d;
vi adj[1123456];
int dist[1123456];
 
void bfs(int s){
	ms(dist,-1);
	queue<int> q;
	q.push(s);
	dist[s] = 0;
 
	int aux;
	while(!q.empty()){
		aux = q.front();
		q.pop();
		for(auto x : adj[aux]){
			if(dist[x] != -1)
				continue;
			dist[x] = dist[aux] + 1;
			q.push(x);	
		}
	}
}
 
int main(){
	fastio;
	cin>>f>>s>>g>>u>>d;
	frr(i,f){
		if (i - d >= 1)
			adj[i].pb(i - d);
		if (i + u <= f)
			adj[i].pb(i + u);	
		}
	bfs(s);
	if (dist[g] == -1)
		cout<< "use the stairs"<<endl;
	else
		cout<<dist[g]<<endl;		
}