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

const int MAXN = 3e6;

int en = 1, tcnt, topo[MAXN], lf[MAXN], lo[MAXN], pa[MAXN], oc[MAXN];
struct no{
	char c;
	int mrk, cnt;
	map<char, int> m;
	no(){mrk = cnt = 0; m.clear();}
} t[MAXN];

inline int new_node(int p, char c){
	t[en].m.clear();
	t[en].mrk = t[en].cnt = 0;
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
	t[u].mrk = 1;
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

void cnt_ocorrencias(string &s){
	int v = 0;

	for (char c : s){
		while (v != 0 and !t[v].m.count(c))
			v = lf[v];

		if (t[v].m.count(c))
			v = t[v].m[c];
		oc[v]++;
	}

	// for (int i = en - 1; i > 0; i--) // cuidado com mtos padrões, propaga no final
	// 	oc[ lf[topo[i]] ] += oc[topo[i]];
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n;
	cin>>n;

	init();

	vector<string> words;

	string ts;
	fr(i, n){
		cin>>ts;
		words.pb(ts);
		add(0, 0, ts);
	}

	aho();

	int m;
	cin>>m;
	string s;
	fr(i, m){
		cin>>s;
		cnt_ocorrencias(s);
	}

	for (int i = en - 1; i > 0; i--)
		oc[ lf[topo[i]] ] += oc[topo[i]];

	for (auto x : lst)
		cout<<oc[x]<<endl;
}