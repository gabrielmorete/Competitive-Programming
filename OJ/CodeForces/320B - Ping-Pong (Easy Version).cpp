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

vi adj[123];

vii v;

bool vis[123];
bool dfs(int a, int b){
	if (a == b) return true;
	
	vis[a] = 1; 

	for (auto x : adj[a]){
		if(vis[x])
			continue;
		if(dfs(x,b))
			return true;
	}
	return false;

}

int main(){
	fastio;

	int n; cin>>n;

	int a,b,op,c,d;
	while(n--){
		cin>>op>>a>>b;
		if(op == 1){
			fr(i,v.size()){
				c = v[i].fst;
				d = v[i].snd;
				if((c < a and a < d) or (c < b and b < d))
					adj[v.size()].pb(i);
				if((a < c and c < b) or ((a < d and d < b)))
					adj[i].pb(v.size());
			}
			v.pb({a,b});
		}
		else{
			ms(vis,0);
			a--;b--;
			cout<<(dfs(a,b)?"YES":	"NO")<<endl; 
		}
	}

}