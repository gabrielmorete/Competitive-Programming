#include "bits/stdc++.h"
using namespace std;

const int MAXN = 1e2 + 10;

vector<int> adju[MAXN];
int matchu[MAXN], matchv[MAXN], coverv[MAXN], coveru[MAXN];
int vis[MAXN], iter;
int m, n;

bool dfs(int u){
    vis[u] = iter;
    if (u == 0) return true;
   	for (int &v : adju[u]){
        if (vis[matchv[v]] < iter and dfs(matchv[v])){
            matchv[v] = u; 
            matchu[u] = v;
            return true;
        }
    }
    return false;
}

void min_cover(){
	iter++;
	for (int u = 1; u <= m; u++)
		if (matchu[u] == 0)
			dfs(u);
	for (int u = 1; u <= m; u++){
		coveru[u] = false;
		if (vis[u] < iter)
			coveru[u] = true;	
	}	
	for (int v = 1; v <= n; v++){
		coverv[v] = false;
		if (vis[matchv[v]] == iter)
			coverv[v] = true;
	}	
}

int kuhn(){
    memset(&matchu, 0, sizeof matchu);
    memset(&matchv, 0, sizeof matchv);
 	iter = 0;
    int result = 0;
    for (int u = 1; u <= m; u++){
        iter++;
        if (matchu[u] == 0 and dfs(u)) 
        	result++;
    }
    min_cover();
    return result;
}

int main(){
	int madj[MAXN][MAXN];

	cin>>m;
	n = m;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin>>madj[i][j];

	for (int k = 1; k <= n; k++) // compute transitive closure
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				madj[i][j] |= madj[i][k] & madj[k][j];

	for (int i = 1; i <= n; i++) // build bip graph of dilworth's theorem
		for (int j = 1; j <= n; j++)
			if (madj[i][j] and i != j)
				adju[i].push_back(j);

	cout<<(n - kuhn())<< endl; // size of longest antichain			

	for (int i = 1; i <= n; i++) // both copies aren't in min cover
		if (coveru[i] == 0 and coverv[i] == 0)
			cout<<i<<' ';
	cout<<endl;	
}

// My old solution using dinitz's algorithm 

// #define ms(x,i) memset(x,i,sizeof(x))

// int ned, first[MAXN], work[MAXN], dist[MAXN], q[MAXN];
// int cap[MAXM], to[MAXM], nxt[MAXM];

// void init() {
//    memset(first, -1, sizeof first);
//    ned = 0;
// }

// void add(int u, int v, int f) {
// 	to[ned] = v, cap[ned] = f;
// 	nxt[ned] = first[u];
// 	first[u] = ned++;
	
// 	to[ned] = u, cap[ned] = 0;
// 	nxt[ned] = first[v];
// 	first[v] = ned++;
// }

// int dfs(int u, int f, int t) {
// 	if (u == t) return f;
// 	for(int &e = work[u]; e != -1; e = nxt[e]) {
// 		int v = to[e];
// 		if (dist[v] == dist[u] + 1 && cap[e] > 0) {
// 			int df = dfs(v, min(f, cap[e]), t);
// 			if (df > 0) {
// 				cap[e] -= df;
// 				cap[e^1] += df;
// 				return df;
// 			}
// 		}
// 	}
// 	return 0;
// }

// bool bfs(int s, int t) {
// 	memset(&dist, -1, sizeof dist);
// 	dist[s] = 0;
// 	int st = 0, en = 0;
// 	q[en++] = s;
// 	while (en > st) {
// 		int u = q[st++];
// 		for(int e = first[u]; e!=-1; e = nxt[e]) {
// 			int v = to[e];
// 			if (dist[v] < 0 && cap[e] > 0) {
// 				dist[v] = dist[u] + 1;
// 				q[en++] = v;
// 			}
// 		}
// 	}
// 	return dist[t] >= 0;
// }

// int dinic(int s, int t) {
// 	int result = 0, f;
// 	while (bfs(s, t)) {
// 		memcpy(work, first, sizeof work);
// 		while (f = dfs(s, INF, t)) result += f;
// 	}
// 	return result;
// }

// int src, snk, n, match[212];
// bool cover[212], vis[212];
// void dfsm(int v) {
// 	vis[v] = 1;
// 	for (int e = first[v]; e != -1; e = nxt[e]) {
// 		if (to[e] != src and cap[e] and !vis[to[e]]){
// 			vis[to[e]] = 1;
// 			if (match[to[e]] != -1)
// 			dfsm(match[to[e]]);
// 		}
// 	}		
// }

// int main(){
// 	fastio;
// 	init();
// 	int m[112][112];

// 	cin>>n;

// 	int x;
// 	frr(i,n)
// 		frr(j,n){
// 			cin>>m[i][j];
// 		}
	
// 	src = 0;
// 	snk = 2*n + 1;

// 	frr(k,n)
// 		frr(i,n)
// 			frr(j,n)
// 				m[i][j] |= m[i][k]&m[k][j];

// 	frr(i,n){
// 		frr(j,n){
// 			if (m[i][j] and i != j)
// 				add( i, j + n, 1);
// 		}
// 	}

// 	frr(i,n)
// 		add( src, i, 1), add( i + n, snk, 1);	

// 	cout<< n - dinic( src, snk)<< endl;			

// 	ms(vis, 0);
// 	ms(cover, 0);
// 	ms(match, -1);

// 	for (int i = 1; i <= n; i++)
// 		for (int e = first[i]; e != -1; e = nxt[e])
// 			if (!cap[e] and to[e] != src)
// 				 match[i] = to[e], match[to[e]] = i;

// 	for (int e = first[src]; e != -1; e = nxt[e]) {
// 		if (cap[e]) {
// 			vis[to[e]] = 1;
// 			for (int a = first[to[e]]; a != -1; a = nxt[a]) {
// 				if (to[a] != src) {
// 					vis[to[a]] = 1;
// 					if (match[to[a]] != -1)
// 						dfsm(match[to[a]]);
// 				}
// 			}	
// 		}
// 	}

// 	for (int i = 1; i <= n; i++)
// 		if (!vis[i])
// 			cover[i] = 1;	

// 	for (int i = n + 1; i <= 2*n; i++)
// 		if (vis[i])
// 			cover[i] = 1;	

// 	bool ans[212];
// 	ms( ans, 0);

// 	for (int i = 1; i <= n; i++)
// 		if (cover[i])
// 			ans[i] = 1;

// 	for (int i = n + 1; i <= 2*n; i++)
// 		if (cover[i])
// 			ans[i - n] = 1;	
	
// 	for (int i = 1; i <= n; i++)
// 		if (!ans[i])
// 			cout<<i<<' ';
// 	gnl;	
// }