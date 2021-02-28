// Algoritmo de Ukkonen para árvore de suffixo
// complexidade : O(|s|)

#include "bits/stdc++.h"
using namespace std;

const int MAXN = 5e5 + 10; // tamanho máximo da string

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
		while (i <= j){
			if (cd == t[cn].len() and t[cn].f.count(s[j])){
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
				t[t[mid].p].f[t[mid][0]] = mid; // pai ponta pro meio
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
					cn = t[cn].f[s[g]];
					cd = j - g;
				}
			}
			i++;
		}
	}
}

int sum;

void dfs(int v){
	sum += t[v].len();
	for (auto it : t[v].f)
		dfs(it.second);
}

void solve(){
	cin>>s;

	sum = 0;
	for (int i = 0; i < 2 * MAXN; i++){
		t[i] = no();
		t[i].f.clear();
	}


	build_suffix_tree();

	dfs(0);
	sum -= s.size();
	cout<<sum<<endl;
}

int main(){
	int T;
	cin>>T;

	while (T--)
		solve();
}