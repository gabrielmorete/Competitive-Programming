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

int n, m;
int color[112345];
vi adj[112345];
bool vis[112345];

void marc_vis(int v) {
	ms(vis,0);
	for( auto x : adj[v])
		vis[x] = 1;
}

int main(){
	fastio;
	cin>>n>>m;

	int a,b;
	fr(i,m){
		cin>>a>>b;
		adj[a].pb(b);
		adj[b].pb(a);
	}

	int id = 0;
	
	frr(i,n){
		if(!color[i]){
			marc_vis(i);
			id++;

			for(int j = i; j <= n; j++) {
				if(!vis[j]) {
					//cout<<i<<' '<<j<<endl;
					if (color[j] != 0){
						cout<<-1<<endl;
						return 0;
					}
					color[j] = id;
				}
			}
		}

		if(id>3){
			cout<<-1<<endl;
			return 0;
		}
	}

	if(id != 3){
		cout<<-1<<endl;
		return 0;
	}

	frr(i,id){
		int j = 1;
		while(color[j] != i)
			j++;

		sort(all(adj[j]));

		for(int k = j+1; k<= n;k++)
			if(color[k] == i){

				if(adj[j].size() != adj[k].size()){
					cout<<-1<<endl;
					return 0;
				}

				sort(all(adj[k]));
				
				for(int l = 0; l < adj[j].size();l++){
					if(adj[j][l] != adj[k][l]){
						cout<<-1<<endl;
						return 0;
					}
				}

			}
	}
	
	frr(i,n)
		cout<<color[i]<<' ';
	gnl;

}