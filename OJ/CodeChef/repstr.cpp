// Algoritmo de Ukkonen para árvore de suffixo
// complexidade : O(|s|)

#include "bits/stdc++.h"
using namespace std;

#define dbg(x)  cout << #x << " = " << x << endl

const int MAXN = 1e5 + 10; // tamanho máximo da string

string s;

struct no {
	int l, r, p, suf;
	map<char, int> f;
	no() : l(0), r(-1), p(0){}
	no(int _l, int _r, int _p) : l(_l), r(_r), p(_p) {}
	inline int len() { return r - l + 1;}
	inline char operator[](int i){ return s[i + l]; }
} t[2 * MAXN];

int en = 1;

inline int new_node(int l, int r, int p){
	t[en] = no(l, r, p);
	return en++;
}

void build_suffix_tree(){
	s += '$'; // cada sufixo tem uma folha própria
	int n = s.size();
	int i = 0;
	int cn = 0, cd = 0, ns = 0;
	for (int j = i; j < n; j++){
		// dbg(i);
		while (i <= j){
			// dbg(j);
			if (cd == t[cn].len() and t[cn].f.count(s[j])){
				// dbg(j);
				cn = t[cn].f[s[j]];
				cd = 0;
			}
			if ( cd < t[cn].len() and t[cn][cd] == s[j]){ // caso 1, percorre
				cd++;
				break;
			}
			else if (cd == t[cn].len()){ // caso 2, preciso adicionar uma folha
				t[cn].f[s[j]] = new_node(j, n - 1, cn); // cria folha
				if (cn){ // nó interno
					cn = t[cn].suf; // vai pro suffix link
					cd = t[cn].len(); // percorre a aresta, está em i + 1, j - 1
				}
			}
			else{ // caso 3, quebrar aresta
				int mid = new_node(t[cn].l, t[cn].l + cd - 1, t[cn].p); // cria nó no meio da aresta
				// dbg(t[mid].l);
				t[t[mid].p].f[t[mid][0]] = mid; // pai ponta pro meio
				// dbg(j);
				// dbg(cd);
				t[mid].f[s[j]] = new_node(j, n - 1, mid); // cria folha com s[j]
				t[mid].f[t[cn][cd]] = cn; // aponta pro filho anterior
				t[cn].p = mid;
				t[cn].l += cd;
				if (ns)
					t[ns].suf = mid; // tinha suffix link faltando
			
				cn = t[mid].p;
				int g; // vou até [i + 1, j - 1] para continuar
				if (cn){
					g = j - cd;
					cn = t[cn].suf;
				}
				else
					g = i + 1;

				while (g < j and g + t[t[cn].f[s[g]]].len() <= j){ // percorre aresta completamente
					// dbg(g);
					cn = t[cn].f[s[g]];
					g += t[cn].len();
				}
				if (g == j){ // nó existe [i + 1, j - 1] exite nesses limites
					ns = 0; // nó existe, não preciso de suffix link
					t[mid].suf = cn;
					cd = t[cn].len();
				}
				else{ // acabou no meio da aresta, precisamos criar um nó
					ns = mid;  // mid precisa de um suffix link
					// dbg(g);
					cn = t[cn].f[s[g]];
					cd = j - g;
				}
			}
			i++;
		}
	}
}

int mn, mx, sz[2 * MAXN];
int ansfr, anssz;

int dfs_sz(int v){
	sz[v] = 0;

	if (t[v].f.empty()){
		if (t[v].p != 0)
			sz[v] = 1;
		if (t[v].p == 0 and t[v].len() > 1)
			sz[v] = 1;
	}

	for (auto it : t[v].f)
		sz[v] += dfs_sz(it.second);

	return sz[v];
}

void update(int tam, int freq){
	if (freq > ansfr){
		ansfr = freq;
		anssz = tam;
	}
	else if (freq == ansfr)
		anssz = max(anssz, tam);
}

void dfs(int v, int hgt){
	if (hgt > mx) // fora do intervalo
		return;
	
	if (hgt + t[v].len() >= mn) // aresta está dentro dos limites
		update( min(hgt + t[v].len(), mx), sz[v]); // o maximo que da ou tudo

	for (auto it : t[v].f)
		dfs(it.second, hgt + t[v].len());
}

void init(){
	en = 1; // reinicia contagem de no
	for (int i = 0; i < 2 * MAXN; i++){ // limpa a árvore
		t[i] = no();
		t[i].f.clear();
	}
}

void solve(){
	cin>>s;

	init();

	build_suffix_tree();

	dfs_sz(0);

	ansfr = anssz = 0;

	dfs(0, 0);	

	cout<<ansfr<<' '<<anssz<<endl;
}

int32_t main(){
	while (cin>>mn>>mx and mn != 0)
		solve();
}