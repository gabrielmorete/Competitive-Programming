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

#define dbg(x)  cout << #x << " = " << x << endl
#define all(x)  x.begin(), x.end()

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

const int INF = 0x3f3f3f3f;
const ll llINF = (long long)(1e18) + 100;   
const int MAXN = 1e5 + 10;

int n, clk, sn, id;
int pre[MAXN], lo[MAXN], stk[MAXN], scc[MAXN]; // scc[v] é a componente forte de v
vii adj[MAXN];

vector<tuple<int, int, pii>> adjscc[MAXN];


void dfs_scc(int v){
	pre[v] = lo[v] = clk++;
	stk[sn++] = v;
	for (auto x : adj[v]){
		if (pre[x.fst] == -1)
			dfs_scc(x.fst);
		lo[v] = min(lo[v], lo[x.fst]);
	}
	if (lo[v] == pre[v]){
		int u;
		do {
			u = stk[--sn];
			scc[u] = id;
			lo[u] = INF;
		} while (u != v);
		id++;
	}
}

int findscc(){
	fill(pre, pre + n + 2, -1);
	clk = sn = id = 0;
	for (int v = 1; v <= n; v++) // 0 indexed
		if (pre[v] == -1)
			dfs_scc(v);
	return id;	
}

set<int> deg[MAXN];

// constoi arvore das scc
void build_scc_graph(){
	for (int v = 1; v <= n; v++)
		for (auto x : adj[v])
			if (scc[v] != scc[x.fst]){
				adjscc[scc[x.fst]].push_back({scc[v], x.snd, {v, x.fst}}); // paga no reverso
				adjscc[scc[v]].push_back({scc[x.fst], 0, {v, x.fst}}); // não paga no padrão
				
				deg[scc[v]].insert(scc[x.fst]);
			}
}

ll dist[MAXN];

pii gotme[MAXN];
bool vis[MAXN];

void solve(){
	cin>>n;
	fr(i, n + 10){
		adj[i].clear();
		adjscc[i].clear();
		deg[i].clear();
	}

	frr(i, n)
		frr(j, n){
			int x;
			cin>>x;

			if (x > 0){
				adj[i].pb({j, x});
			}
		}	

	if (n == 1){
		cout<<"YES"<<endl<<"0 0"<<endl;
		return;
	}

	if (n == 2){
		cout<<"NO"<<endl;
		return;
	}

	findscc();
	build_scc_graph();

	int st = 0, en = 0;

	fr(i, id){
		if (deg[st].size() > deg[i].size()) st = i;
		if (deg[en].size() < deg[i].size()) en = i;
	}

	assert(deg[en].size() == (id - 1));
	assert(deg[st].size() == 0);


	priority_queue<tuple<ll, int, pii>, vector<tuple<ll, int, pii>>, greater<tuple<ll, int, pii>>> pq;
	
	fr(i, id)
		dist[i] = -1;

	pq.push({0, st, {0, 0}});
	
	ll dst;
	int vtx;
	pii edg;
	while (!pq.empty()){
		tie(dst, vtx, edg) = pq.top();
		pq.pop();

		if (dist[vtx] == -1){
			dist[vtx] = dst;
			gotme[vtx] = edg;

			for (auto x : adjscc[vtx])
				if (dist[get<0>(x)] == -1)
					pq.push({dst + (ll)get<1>(x), get<0>(x), get<2>(x)});
		}	
	}	

	ll val = dist[en];
	assert(val >= 0);

	vii ans;
	while (en != st){
		int nxt = scc[gotme[en].fst];

		if (nxt == en)
			nxt = scc[gotme[en].snd];

		assert(en != nxt);

		if (dist[en] != dist[nxt])
			ans.pb(gotme[en]);

		en = nxt;
	}

	cout<<"YES"<<endl;
	cout<<ans.size()<<' '<<val<<endl;
	for (auto x : ans)
		cout<<x.fst<<' '<<x.snd<<endl;

}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;
	while (T--)
		solve();
}