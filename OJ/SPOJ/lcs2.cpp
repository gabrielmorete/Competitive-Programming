#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fst first
#define snd second

#define fr(i,n)     for (int i = 0; i < n; i++)
#define frr(i,n)    for (int i = 1; i <= n; i++)

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

const int MAXN = 1e6 + 10; // tamanho máximo da string
const int MAXS = 11; // número máximo de strings

// problema infernal de suffix tree
// essa é a coisa mais otimizada


char S[MAXS][MAXN];
int sze[MAXS];

struct no {
	int l, r, p, suf, id;
	int f[40];
	no() : l(0), r(-1), p(0), id(0){}
	no(int _l, int _r, int _p, int _id) : l(_l), r(_r), p(_p), id(_id) {}
	inline int len() { return r - l + 1;}
	inline char operator[](int i){ return S[id][i + l]; }
} t[2 * MAXN];

int en = 1;

inline int new_node(int l, int r, int p, int id){
	t[en] = no(l, r, p, id);
	memset(t[en].f, -1, sizeof t[en].f);
	return en++;
}

void build_suffix_tree(int id){
	int n = strlen(S[id]);
	S[id][n] = ((char)('W' + id));
	S[id][n + 1] = '\0';
	n++;
	sze[id] = n;
	int i = 0;
	int cn = 0, cd = 0, ns = 0;
	for (int j = i; j < n; j++){
		while (i <= j){
			if (cd == t[cn].len() and t[cn].f[S[id][j] - 'W'] != -1){
				cn = t[cn].f[S[id][j] - 'W'];
				cd = 0;
			}
			if (cd < t[cn].len() and t[cn][cd] == S[id][j]){ // caso 1, percorre
				cd++;
				break;
			}
			else if (cd == t[cn].len()){ // caso 2, preciso adicionar uma folha
				t[cn].f[S[id][j] - 'W'] = new_node(j, n - 1, cn, id); // cria folha
				if (cn){ // nó interno
					cn = t[cn].suf; // vai pro suffix link
					cd = t[cn].len(); // percorre a aresta, está em i + 1, j - 1
				}
			}
			else{ // caso 3, quebrar aresta
				int mid = new_node(t[cn].l, t[cn].l + cd - 1, t[cn].p, t[cn].id); // cria nó no meio da aresta
				t[t[mid].p].f[t[mid][0] - 'W'] = mid; // pai ponta pro meio
				t[mid].f[S[id][j] - 'W'] = new_node(j, n - 1, mid, id); // cria folha com s[j]
				t[mid].f[t[cn][cd] - 'W'] = cn; // aponta pro filho anterior
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

				while (g < j and g + t[t[cn].f[S[id][g] - 'W']].len() <= j){ // percorre aresta completamente
					cn = t[cn].f[S[id][g] - 'W'];
					g += t[cn].len();
				}
				if (g == j){ // nó existe [i + 1, j - 1] exite nesses limites
					ns = 0; // nó existe, não preciso de suffix link
					t[mid].suf = cn;
					cd = t[cn].len();
				}
				else{ // acabou no meio da aresta, precisamos criar um nó
					ns = mid;  // mid precisa de um suffix link
					cn = t[cn].f[S[id][g] - 'W'];
					cd = j - g;
				}
			}
			i++;
		}
	}
}

int n, msk[2 * MAXN], ans;

void dfs(int v, int hgt){
	msk[v] = 0;

	hgt += t[v].len();
	for (char c = 'W'; c <= 'z'; c++){
		if (t[v].f[c - 'W'] != -1){
			dfs(t[v].f[c - 'W'], hgt);
			msk[v] |= msk[t[v].f[c - 'W']];
		}	
	}

	if (msk[v] == 0){
		msk[v] = (1<<t[v].id);
		hgt--;
	}

	if (msk[v] == (1<<n) - 1)
		ans = max(ans, hgt);	
}

int32_t main(){
	memset(t[0].f, -1, sizeof t[0].f);
	n = 0;
	ans = 0;
	while (gets(S[n])){
		build_suffix_tree(n);
		n++;
	}

	dfs(0, 0);
    
    printf("%d\n", ans);
}