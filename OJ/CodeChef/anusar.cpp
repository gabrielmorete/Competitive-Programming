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

const int MAXN = 2e5 + 10; // tamanho máximo da string

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

void init(int n){
	en = 1;
	fr(i, 2 * n + 10){
		t[i].f.clear();
		t[i] = no();
	}
}

int sz[2 * MAXN];

int dfs_sz(int v){
	sz[v] = 0;
	if (t[v].f.empty())
		sz[v] = 1;
	

	for (auto it : t[v].f)
		sz[v] += dfs_sz(it.snd);
	return sz[v];
}

ll ans[MAXN];

void dfs(int v){
	if (v != 0){
		ans[sz[v]] += t[v].len() * sz[v]; // coisa do problema
		if (t[v].r == s.size() - 1 and t[v].len() > 0) // desconsiderar o '$'
			ans[sz[v]] -= sz[v];		
		
	}

	for (auto it : t[v].f)
		dfs(it.snd);
}


void solve(){
	cin>>s;
	init(s.size());

	build_suffix_tree();
	dfs_sz(0);

	fr(i, s.size() + 10)
		ans[i] = 0;

	dfs(0);
		
	for (int i = s.size() - 1; i >= 0; i--)
		ans[i] += ans[i + 1];	

	int q, x;
	cin>>q;
	while (q--){
		cin>>x;
		cout<<ans[x]<<endl;
	}		

}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;
	while (T--)
		solve();
}