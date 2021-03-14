// Algoritmo de Ukkonen para árvore de sufixos
// Complexidade : O(|texto|)
// Memoria : O(2|texto|)

#include "bits/stdc++.h"
using namespace std;

const int MAXN = 1e6 + 10; // tamanho máximo da string
const int MAXS = 1; // número máximo de strings

string S[MAXS];

struct no {
	int l, r, p, suf, id;
	map<char, int> f;
	no() : l(0), r(-1), p(0), id(0){}
	no(int _l, int _r, int _p, int _id) : l(_l), r(_r), p(_p), id(_id) {}
	inline int len() { return r - l + 1;}
	inline char operator[](int i){ return S[id][i + l]; }
} t[2 * MAXN];

#error mude o operator[] quando for usar inteiros, overflow!!

int en = 1;
void init(){ en = 1; t[0].f.clear(); t[0] = no();}

inline int new_node(int l, int r, int p, int id){
	t[en] = no(l, r, p, id);
	t[en].f.clear();
	return en++;
}

void build_suffix_tree(int id, string &s){
	s.push_back((char)('!' + id));
	S[id] = s;
	
	int n = s.size();
	int i = 0;
	int cn = 0, cd = 0, ns = 0;
	for (int j = i; j < n; j++){
		while (i <= j){
			if (cd == t[cn].len() and t[cn].f.count(s[j])){
				cn = t[cn].f[s[j]];
				cd = 0;
			}
			if (cd < t[cn].len() and t[cn][cd] == s[j]){ // caso 1, percorre
				cd++;
				break;
			}
			else if (cd == t[cn].len()){ // caso 2, adiciona uma folha
				t[cn].f[s[j]] = new_node(j, n - 1, cn, id);
				if (cn){
					cn = t[cn].suf; // vai pro suffix link, s[i + 1, j - 1]
					cd = t[cn].len();
				}
			}
			else{ // caso 3, quebra aresta
				int mid = new_node(t[cn].l, t[cn].l + cd - 1, t[cn].p, t[cn].id); // no intermediario
				t[t[mid].p].f[t[mid][0]] = mid;
				t[mid].f[s[j]] = new_node(j, n - 1, mid, id);
				t[mid].f[t[cn][cd]] = cn;
				t[cn].p = mid;
				t[cn].l += cd;
				if (ns)
					t[ns].suf = mid; // cria suffix link
			
				cn = t[mid].p;
				int g; // vou para s[i + 1, j - 1]
				if (cn){
					g = j - cd;
					cn = t[cn].suf;
				}
				else
					g = i + 1;

				while (g < j and g + t[t[cn].f[s[g]]].len() <= j){
					cn = t[cn].f[s[g]];
					g += t[cn].len();
				}
				if (g == j){
					ns = 0;
					t[mid].suf = cn;
					cd = t[cn].len();
				}
				else{ // meio a aresta, criar no
					ns = mid; // criar suffix link
					cn = t[cn].f[s[g]];
					cd = j - g;
				}
			}
			i++;
		}
	}
}
