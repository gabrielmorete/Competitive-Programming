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
const int MAXN = 1e3 + 10;

// O(nmBlog(b)) B = upper bound na demanda de um vértice
// algoritmo usa dijkstra, não funciona para custo negativo

typedef ll tf; // tipo de fluxo
typedef ll tc; // tipo de custo
const tf INFFLOW=1e9;
const tc INFCOST=1e9;
struct MCF{
	int n;
	vector<tc> prio, pot; vector<tf> curflow; vector<int> prevedge,prevnode;
	priority_queue<pair<tc, int>, vector<pair<tc, int>>, greater<pair<tc, int>>> q;
	struct edge{int to, rev; tf f, cap; tc cost;};
	vector<vector<edge>> g;
	MCF(int n):n(n),prio(n),curflow(n),prevedge(n),prevnode(n),pot(n),g(n){}
	void add_arc(int s, int t, tf cap, tc cost) { // src, dest, cap, cost
		g[s].pb((edge){t,int(g[t].size()),0,cap,cost});
		g[t].pb((edge){s,int(g[s].size())-1,0,0,-cost});
	}
	pair<tf,tc> get_flow(int s, int t) {
		tf flow=0; tc flowcost=0;
		while(1){
			q.push({0, s});
			fill(all(prio),INFCOST); 
			prio[s]=0; curflow[s]=INFFLOW;
			while(!q.empty()) {
				auto cur=q.top();
				tc d=cur.fst;
                int u=cur.snd;
				q.pop();
				if(d!=prio[u]) continue;
				for(int i=0; i<(int)(g[u].size()); ++i) {
					edge &e=g[u][i];
					int v=e.to;
					if(e.cap<=e.f) continue;
					tc nprio=prio[u]+e.cost+pot[u]-pot[v];
					if(prio[v]>nprio) {
						prio[v]=nprio;
						q.push({nprio, v});
						prevnode[v]=u; prevedge[v]=i;
						curflow[v]=min(curflow[u], e.cap-e.f);
					}
				}
			}
			if(prio[t]==INFCOST) break;
			for(int i = 0; i < n; i++) pot[i]+=prio[i];
			tf df=min(curflow[t], INFFLOW-flow);
			flow+=df;
			for(int v=t; v!=s; v=prevnode[v]) {
				edge &e=g[prevnode[v]][prevedge[v]];
				e.f+=df; g[v][e.rev].f-=df;
				flowcost+=df*e.cost;
			}
		}
		return {flow,flowcost};
	}
};

int n, frq[MAXN];

void solve(){
	cin>>n;

	fr(i, n + 10)
		frq[i] = 0;

	int src = 0;
	int snk = n + 1;

	int x;
	fr(i, n){
		cin>>x;
		frq[x]++;
	}

	MCF flow(n + 2);

	frr(i, n)
		flow.add_arc(src, i, frq[i], 0); // src dst cap cst
	frr(i, n)
		flow.add_arc(i, snk, 1, 0);
	int m;
	cin>>m;

	while (m--){
		int x, y;
		cin>>x>>y;

		flow.add_arc(x, y, n, 1);
		flow.add_arc(y, x, n, 1);
	}	
		
	cout<<flow.get_flow(src, snk).snd<<endl;
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;
	while (T--)
		solve();
}