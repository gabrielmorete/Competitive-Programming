// Min cost free integer flow
// Resolve o problema : Dado uma rede com capacidades e custos
// inteiros qual o menor custo de algum fluxo?
// Resolve : https://vjudge.net/problem/UVA-11613
// Caderno : https://github.com/victorsenam/caderno/blob/master/code/min_cost.cpp
// Complexidade : // O(nm + min(f, nm) mn) f = fluxo

#include "bits/stdc++.h"
using namespace std;

typedef long long int ll;

const int INF = 0x3f3f3f3f;
const int MAXN = 5e2 + 10;

typedef ll val; // tipo de fluxo
typedef ll num; // tipo de custo

const int N = MAXN, M = MAXN * MAXN * 2; 
const num eps = 0;
struct mcmf {
	int es[N], to[M], nx[M], en = 2, pai[N], seen[N], tempo, qu[N];
	val fl[M], cp[M], flow; num cs[M], d[N], tot;
	val spfa(int s, int t) {
		tempo++; int a = 0, b = 0;
		for(int i = 0; i < N; i++) d[i] = numeric_limits<num>::max();
		d[s] = 0; qu[b++] = s; seen[s] = tempo;
		while(a != b) {
			int u = qu[a++]; if(a == N) a = 0; seen[u] = 0;
			for(int e = es[u]; e; e = nx[e]) if(cp[e] - fl[e] > val(0) && d[u] + cs[e] < d[to[e]] - eps) {
				d[to[e]] = d[u] + cs[e]; pai[to[e]] = e ^ 1;
				if(seen[to[e]] < tempo) { seen[to[e]] = tempo; qu[b++] = to[e]; if(b == N) b = 0; }
			}
		}
		if(d[t] > 0) return false; // Para de aumentar quando o custo do caminho é positivo
		val mx = numeric_limits<val>::max();
		for(int u = t; u != s; u = to[pai[u]])
			mx = min(mx, cp[pai[u] ^ 1] - fl[pai[u] ^ 1]);
		if (d[t] * val(mx) > 0) return 0;
		tot += d[t] * val(mx);
		for(int u = t; u != s; u = to[pai[u]])
			fl[pai[u]] -= mx, fl[pai[u] ^ 1] += mx;
		return mx;
	}
	// public $
	num min_cost(int s, int t) {
		tot = 0; flow = 0;
		while(val a = spfa(s, t)) flow += a;
		return tot;
	}
	void add_arc(int u, int v, val c, num s) {
		fl[en] = 0; cp[en] = c; to[en] = v; nx[en] = es[u]; cs[en] =  s; es[u] = en++;
		fl[en] = 0; cp[en] = 0; to[en] = u; nx[en] = es[v]; cs[en] = -s; es[v] = en++;
	}
	void reset_flow() { memset(fl, 0, sizeof(val) * en); }
	void init(int n) { en = 2; memset(es, 0, sizeof(int) * n); } // XXX must be called
};

mcmf flow;

ll n, m, a[MAXN], b[MAXN], c[MAXN], d[MAXN], e[MAXN];
void solve(){
	cin>>n>>m;

	for (int i = 1; i <= n; i++)
		cin>>a[i]>>b[i]>>c[i]>>d[i]>>e[i];

	int src = 0;
	int snk = 2 * n + 1;	

	flow.init(2 * n + 2);

	for (int i = 1; i <= n; i++){
		flow.add_arc(src, i, b[i], a[i]); // paga pra produzir
		flow.add_arc(i + n, snk, d[i], -c[i]); // ganha por vender
	
		flow.add_arc(i, i + n, INF, 0);

		for (int j = i + 1; j <= min(i + e[i], n); j++)
			flow.add_arc(i, j + n, INF, m * (j - i)); // paga para guardar
	}

	cout<<-flow.min_cost(src, snk)<<endl;
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;
	for (int i = 1; i <= T; i++){
		cout<<"Case "<<i<<": ";
		solve();
	}
}