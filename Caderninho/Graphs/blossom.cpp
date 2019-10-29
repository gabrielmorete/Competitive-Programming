#include <bits/stdc++.h>
using namespace std;
const int M = 500;//max vertex
struct struct_edge{
	int v;
	struct_edge* n;
};
typedef struct_edge* edge;
struct_edge pool[M*M*2];
edge top=pool,adj[M];
int V,E,match[M],st,en,q[M],pai[M],base[M];
bool inq[M],inb[M],ed[M][M];

void add_edge(int u,int v) {
	top->v=v,top->n=adj[u],adj[u]=top++;
	top->v=u,top->n=adj[v],adj[v]=top++;
}

int LCA(int root,int u,int v) {
	static bool inp[M];
	memset(inp,0,sizeof(inp));
	while(1)
	{
		inp[u=base[u]]=true;
		if (u==root) 
			break;
		u=pai[match[u]];
	}
	while(1)
	{
	if (inp[v=base[v]]) 
		return v;
	v=pai[match[v]];
	}
}

void mark_blossom(int lca,int u) {
	while (base[u]!=lca) {
		int v=match[u];
		inb[base[u]]=inb[base[v]]=true;
		u=pai[v];
		if (base[u]!=lca) 
			pai[u]=v;
	}
}

void blossom_contraction(int s,int u,int v) {
	int lca=LCA(s,u,v);
	memset(inb,0,sizeof(inb));
	mark_blossom(lca,u);
	mark_blossom(lca,v);
	if (base[u]!=lca)
		pai[u]=v;
	if (base[v]!=lca)
		pai[v]=u;
	for (int u=0;u<V;u++)
	if (inb[base[u]]) {
		base[u]=lca;
		if (!inq[u])
			inq[q[en++]=u]=true;
	}
}

void augment_path( int t) {
	int x, w;
	do {
		x = pai[t];
		w = match[x];
		match[x] = t;
		match[t] = x;
		t = w;
	} while (t != -1);
}

bool find_augmenting_path(int s) {
	memset(inq,0,sizeof(inq));
	memset(pai,-1,sizeof(pai));
	for (int i=0;i<V;i++) 
		base[i]=i;
	st = en = 0;
	q[en++] = s;
	inq[s]=true;
	while (st<en) {
		int u=q[st++];
		for (edge e=adj[u];e;e=e->n) {
			int v=e->v;
			if (base[u]!=base[v]&&match[u]!=v) {
				if ((v==s)||(match[v]!=-1 && pai[match[v]]!=-1))
					blossom_contraction(s,u,v);
				else if (pai[v]==-1) {
					pai[v]=u;
					if (match[v]==-1){
						augment_path(v);
						return true;
					}
					if (!inq[match[v]])
						inq[q[en++]=match[v]]=true;
				}
			}	
		}
	}
return false;
}

int blossom() {
	int matchc=0;
	memset(match,-1,sizeof(match));
	for (int u=0;u<V;u++)
	if (match[u]==-1 && find_augmenting_path(u))
		matchc++;
	return matchc;
}

// V -> number of vertices, E -> number of edges
// Use add_edge(u,v) to add edge.
// blossom() returns the value of the matching
// the matching is stored in matching[]

// Based (almost a copy) from : https://codeforces.com/blog/entry/49402