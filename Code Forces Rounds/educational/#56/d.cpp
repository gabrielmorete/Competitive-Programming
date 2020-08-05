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

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;  
const int MAXN = 300100;
const ll mod=998244353;
const int LMAXN = 20;
bool vis[MAXN],ok,par[MAXN];
ll P,I;
vi adj[MAXN];

void dfs(int v,bool pai){
	vis[v]=1; 
	par[v]= !pai;

	if(pai==0)
		P++; 
	if(pai==1)
		I++;

	for(auto x: adj[v]){
		if(vis[x] && par[x]==par[v]){
			ok=0;
			return;
		}
	
		if(vis[x])
			continue; 

		dfs(x,par[v]);
	}

}

ll fastxp(ll base,ll exp){
	if(exp==0)
		return 1; 

	ll aux=fastxp(base,exp/2); 
	aux=(aux*aux)%mod; 

	if(exp%2ll)
		aux=(aux*base)%mod;

	return aux;

}

void solve(){
	int n,m,a,b;
	cin>>n>>m;

	fr(i,n+2){
		adj[i].clear();
		vis[i]=0;
	}
	



	fr(i,m){
		cin>>a>>b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	ll ans=1,aux;


	frr(i,n){
		if(vis[i]==0){
	
			P=0;I=0;ok=1;
			dfs(i,1);

			if(ok){
				aux=fastxp(2,I)%mod;
				aux=(aux+fastxp(2,P))%mod;
				ans=(ans*aux)%mod;
			}
			else{
				cout<<0<<endl;
				return;
			}


		}
	}

	cout<<ans<<endl;
}


int main(){
	fastio; 
	int t; 
	cin>>t; 
	while(t--) solve();
}