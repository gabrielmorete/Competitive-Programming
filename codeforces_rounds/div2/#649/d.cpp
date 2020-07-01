#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fst first
#define snd second

#define fr(i,n)     for (int i = 0; i < n; i++)
#define frr(i,n)    for (int i = 1; i <= n; i++)

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

int n, m, k;
vi adj[MAXN];

int cic, pai[MAXN], dist[MAXN];

void dfs1(int v, int p, int dst){
	pai[v] = p;
	dist[v] = dst;
	for (int x : adj[v]){
		if (x != p){
			if (dist[x] > 0){ // achei ciclo
				cic = v;
			}
			else
				dfs1(x, v, dst + 1);
		}
	}
}

int bst, ini, fim;

void dfs2(int v, int p, int dst){
	pai[v] = p;
	dist[v] = dst;
	for (int x : adj[v]){
		if (x != p){
			if (dist[x] == 0)
				dfs2(x, v, dst + 1);
			else if (abs(dist[v] - dist[x]) < bst){
				bst = abs(dist[v] - dist[x]);
				fim = x;
				ini = v;
			}
		}
	}
}


int32_t main(){
	fastio;
	cin>>n>>m>>k;

	int a, b;
	fr(i, m){
		cin>>a>>b;
		adj[a].pb(b);
		adj[b].pb(a);
	}

	dfs1(1, 1, 1);

	if (cic == 0){ // é arovre
		int od = 0;
		frr(i, n)
			if (dist[i] % 2 == 1)
				od++;
		
		k = (k + 1)/2;
		int aux = od >= k? 1 : 0;

		cout<<1<<endl;	

		frr(i, n){
			if (k > 0 and dist[i] % 2 == aux){
				cout<<i<<' ';
				k--;
			}
		}			
		gnl;
		return 0;
	}
	else{
		fill(dist, dist + MAXN, 0);
		bst = n + 10;
		dfs2(cic, cic, 1);

		if (dist[ini] < dist[fim])
			swap(ini, fim);


		vi  ciclo;
		while (ini != fim){
			ciclo.pb(ini);
			ini = pai[ini];
		}
		ciclo.pb(ini);

		if (ciclo.size() <= k){
			cout<<2<<endl;
			cout<<ciclo.size()<<endl;
			for (int x : ciclo)
				cout<<x<<' ';
			gnl;
		}
		else{
			k = (k + 1)/2;

			cout<<1<<endl;	
			for (int i = 0; i < ciclo.size(); i += 2)
				if (k > 0){
					cout<<ciclo[i]<<' ';
					k--;
				}
			gnl;	
		}
	}
}