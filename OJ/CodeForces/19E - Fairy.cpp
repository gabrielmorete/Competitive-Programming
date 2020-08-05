#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fst first
#define snd second

#define fr(i,n)     for (int i = 0; i < n; i++)
#define frr(i,n)    for (int i = 1; i <= n; i++)

#define endl '\n'
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
const int MAXN = 1e4 + 10;
const ll mod = 1e9+7;

int n, m, c0, edge;
int cor[MAXN], even[MAXN], odd[MAXN], hgt[MAXN], pai[MAXN];
vii adj[MAXN];

void dfs(int v){
	int od, ev;
	od = ev = 0;
	for (auto aux : adj[v]){
		int x = aux.fst;
		if (x == pai[v])
			continue;
		
		if (cor[x] == 0){
	
			pai[x] = v;
			hgt[x] = hgt[v] + 1;
			cor[x] = cor[v] == 1? 2 : 1;
			dfs(x);
	
			od += odd[x];
			ev += even[x];
			continue;
		}

		if (hgt[v] < hgt[x]){ // meu descendente
			if (cor[v] == cor[x])
				od--;
			else // circuito acaba aqui
				ev--;
		}
		else{ // meu ancestral
			if (cor[v] == cor[x]){ // achei circuito_f impar
				od++;
				c0++;
				edge = aux.snd;
			}
			else
				ev++;
		}
	}
	
	even[v] = ev;
	odd[v] = od;
}

int32_t main(){
	fastio;
	cin>>n>>m;
	
	int a, b;
	fr(i, m){
		cin>>a>>b;
		adj[a].pb({b, i + 1});
		adj[b].pb({a, i + 1});
	}

	frr(i, n)
		if (cor[i] == 0){
			pai[i] = i;
			hgt[i] = 0;
			cor[i] = 1;
			dfs(i);
		}

	if (c0 == 0){ // o grafo é bipartido
		cout<<m<<endl;
		frr(i, m)
			cout<<i<<' ';
		gnl;	
		return 0;
	}

	vi ans;
	if (c0 == 1)
		ans.pb(edge);

	frr(v, n)
		for(auto x : adj[v]){
			a = x.fst; b = x.snd;
			if (pai[a] != v)
				continue;

			if (odd[a] == c0 and even[a] == 0)
				ans.pb(b);
		}

	sort(all(ans));	

	cout<<ans.size()<<endl;
	for (int x : ans)
		cout<<x<<' ';
	gnl;

}