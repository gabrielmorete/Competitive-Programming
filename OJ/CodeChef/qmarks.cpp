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

const int MAXN = 2e3;

// lf é o maior sufixo proprio da string 
// lo é o maior sufixo proprio da string que é ocorrencia

int en = 1, tcnt, topo[MAXN], lf[MAXN], lo[MAXN], pa[MAXN], oc[MAXN];
struct no{
	char c;
	int mrk, cnt;
	map<char, int> m;
	no(){mrk = cnt = 0; m.clear();}
} t[MAXN];

inline int new_node(int p, char c){
	t[en] = no();
	lf[en] = lo[en] = oc[en] = 0;
	pa[en] = p;
	t[en].c = c;
	return en++;
}

inline void init(){t[0] = no(); en = 1;}

vi lst;

void add(int v, int pos, string &s){
	int u = v;

	while (pos < s.size()){
		if (!t[u].m.count(s[pos]))
			t[u].m[s[pos]] = new_node(u, s[pos]);
		u = t[u].m[s[pos]];
		t[u].cnt++;
		pos++;
	}
	t[u].mrk += 1;
	lst.pb(u);
}

void aux_link(int v){
	lf[v] = lf[pa[v]];
	while (lf[v] != 0 and !t[ lf[v] ].m.count(t[v].c))
		lf[v] = lf[lf[v]];
	
	if (t[ lf[v] ].m.count(t[v].c))
		lf[v] = t[ lf[v] ].m[t[v].c];

	if (t[ lf[v] ].mrk)
		lo[v] = lf[v];
	else
		lo[v] = lo[lf[v]];
}

void aho(){
	queue<int> q;

	for (auto it : t[0].m)
		q.push(it.second);
	
	tcnt = 0;
	while (!q.empty()){
		int v = q.front();
		q.pop();
		topo[tcnt++] = v;
		
		for (auto it : t[v].m){
			aux_link(it.second);
			q.push(it.second);
		}
	}
}

int nlo[MAXN];

void dfs_lo(int v){
	nlo[v] = 0;

	int u = lo[v];
	while (u){
		nlo[v] += t[u].mrk;
		u = lo[u];
	}

	nlo[v] += t[v].mrk;

	for (auto it : t[v].m)
		dfs_lo(it.snd);
}


string s;
int memo[MAXN][MAXN];

int next_vtx(int v, char c){
	while (v != 0 and !t[v].m.count(c))
		v = lf[v];

	if (t[v].m.count(c))
		v = t[v].m[c];

	return v;
}

int pd(int vtx, int pos){
	if (pos == s.size())
		return 0;

	int &pdm = memo[vtx][pos];
	if (pdm != -1)
		return pdm;

	pdm = 0;
	if (s[pos] != '?'){
		int v = next_vtx(vtx, s[pos]);
		pdm = nlo[v] + pd(v, pos + 1);
	}
	else{
		for (char a = 'a'; a <= 'z'; a++){
			int v = next_vtx(vtx, a);
			pdm = max(pdm, nlo[v] + pd(v, pos + 1));
		}
	}
	
	return pdm;
}

string tans;

void rec_ans(int vtx, int pos){
	if (pos == s.size())
		return;
	if (s[pos] != '?'){
		int v = next_vtx(vtx, s[pos]);
		tans.pb(s[pos]);
		rec_ans(v, pos + 1);
	}
	else{
		int val = -1, nxt = -1;
		char g;
		for (char a = 'a'; a <= 'z'; a++){
			int v = next_vtx(vtx, a);
			if (nlo[v] + pd(v, pos + 1) > val){
				val = nlo[v] + pd(v, pos + 1);
				nxt = v;
				g = a;
			}
		}
		tans.pb(g);
		rec_ans(nxt, pos + 1);
	}
}


void solve(){
	init();

	int n, m;

	cin>>n>>m;

	cin>>s;

	string ts;
	fr(i, m){
		cin>>ts;
		add(0, 0, ts);
	}

	aho();

	dfs_lo(0);

	fr(i, en + 10)
		fr(j, n + 10)
			memo[i][j] = -1;

	cout<<pd(0, 0)<<endl;
	
	tans.clear();
	rec_ans(0, 0);

	cout<<tans<<endl;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;
	while (T--)
		solve();	
}