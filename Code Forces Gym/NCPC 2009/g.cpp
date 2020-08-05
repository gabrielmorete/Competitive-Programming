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
vi adj[3000];
vii edge;
int comp[5000];

void dfs_cmp(int v, int pai, int c){ // marca as componentes
	comp[v] = c;
	for (int x : adj[v]){
		if (x != pai)
			dfs_cmp(x, v, c);
	}
}

int dist[3000], dist_aux[3000];
void dfs_dist(int v, int pai, int c, int dst){ //acha distâcia navegando pela mesma componente
	dist[v] = dst;
	for (int x : adj[v]){
		if (x != pai and comp[x] == c){
			dfs_dist(x, v, c, dst + 1);
		}
	}
}

int main(){
	fastio;

	cin>>n;

	int a, b;
	fr(i, n - 1){
		cin>>a>>b;
		adj[a].pb(b);
		adj[b].pb(a);
		edge.pb({a, b});
	}

	int ans = 5000;
	int ina, inb, outa, outb;
	
	int centa, centb, dsta, dstb, aux;
	
	fr(i, n - 1){
		a = edge[i].fst;
		b = edge[i].snd;

		dfs_cmp(a, b, 0);
		dfs_cmp(b, a, 1); //componentes marcadas


		dfs_dist(a, a, 0, 0);
		dsta = 0;
		frr(i, n)
			if (comp[i] == 0 and dist[i] >= dsta){
				dsta = dist[i];
				aux = i;
			}

		dfs_dist(aux, aux, 0, 0);
		dsta = 0;
		frr(i, n){
			if (comp[i] == 0 and dist[i] >= dsta){
				dsta = dist[i];
				aux = i;
			}
			dist_aux[i] = dist[i];
		}	

		dfs_dist(aux, aux, 0, 0);

		frr(i, n)
			if (comp[i] == 0 and abs(dist[i] - dist_aux[i]) <= 1 and dist[i] + dist_aux[i] == dsta)
				centa = i;	

		// Achei diametro do lado 'a' e o vértice do meio
		
		dfs_dist(b, a, 1, 0);
		
		dstb = 0;
		frr(i, n)
			if (comp[i] == 1 and dist[i] >= dstb){
				dstb = dist[i];
				aux = i;
			}

		
		dfs_dist(aux, aux, 1, 0);
		
		dstb = 0;
		frr(i, n){
			if (comp[i] == 1 and dist[i] >= dstb){
				dstb = dist[i];
				aux = i;
			}
			dist_aux[i] = dist[i];
		}	
		

		dfs_dist(aux, aux, 1, 0);

		// cout<<a<<' '<<b<<endl;
		// dbg(dstb);
		frr(i, n)
			if (comp[i] == 1 and abs(dist[i] - dist_aux[i]) <= 1 and dist[i] + dist_aux[i] == dstb){
				centb = i;	
			}


		// chapa;	
		// cout<<a<< ' '<<b<<endl;
		// cout<<centa<<' '<<centb<<endl;
		// cout<<dsta<<' '<<dstb<<endl;	

		aux = max({dsta, dstb, 1 + (dsta + 1)/2 + (dstb + 1)/2 });
			
		if (ans > aux){
			ans = aux;
			ina = centa; 
			inb = centb;
			outa = a;
			outb = b;
		}			
	}

	cout<<ans<<endl;
	cout<<outa<<' '<<outb<<endl;
	cout<<ina<<' '<<inb<<endl;
}