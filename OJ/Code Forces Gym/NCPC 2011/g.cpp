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
int n;
vi ids;
vi adj[1123];
vi adjr[1123];
 
bool vis[1123];
 
void dfsr(int v){
	vis[v] = 1;
	for (auto x : adjr[v]){
		if (vis[x])
			continue;
		dfsr(x);	
	}
}
 
void dfs(int v){
	vis[v] = 1;
	for (auto x : adj[v]){
		if (vis[x])
			continue;
		dfs(x);	
	}
}
 
int main(){
	fastio;
	cin>>n;
 
	int id, m, a;
	fr(i,n){
		cin>>id>>m;
		ids.pb(id);
		fr(j,m){
			cin>>a;
			adj[id].pb(a);
			adjr[a].pb(id);
		}
	}
 
	bool ok = 1;
	ms(vis,0);
	dfsr(0);
	for (auto x : ids)
		if (!vis[x]){
			cout<<"TRAPPED "<<x<<endl;
			ok = 0;
		}
 
	ms(vis,0);
	dfs(0);
	for (auto x : ids)
		if (!vis[x]){
			cout<<"UNREACHABLE "<<x<<endl;
			ok = 0;
		}
		
	if (ok)
		cout<<"NO PROBLEMS"<<endl;	
 
}