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
const int MAXN = 4e6 + 10;

int en = 1, tcnt, topo[MAXN], lf[MAXN], lo[MAXN], pa[MAXN], oc[MAXN];
vector<int> lst; // Node of the ocurrence of the pattern
struct no{
	char c;
	int cnt, mrk; // How many pass, how many end
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

inline void init(){t[0] = no(); en = 1; lst.clear();}

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
	lst.pb(u); // This word end in this node
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

void cnt_ocr(string &s){ 
	int v = 0;

    for (int i = 0; i <= en; i++) // Dont do this if multiple tests
        oc[i] = 0;

	for (char c : s){
		while (v != 0 and !t[v].m.count(c))
			v = lf[v];

		if (t[v].m.count(c))
			v = t[v].m[c];
		oc[v]++;
	}

	for (int i = en - 1; i > 0; i--) // In case of multiple texts, propagate at the end! O(|sum of patterns|)
		oc[ lf[topo[i]] ] += oc[topo[i]];
}

void solve(){
    init();

    string txt;
    cin>>txt;

    int n;
    cin>>n;

    fr(i, n){
        string s;
        cin>>s;
        add(0, 0, s);
    }

    aho();

    cnt_ocr(txt);

    for (auto x : lst)
        if (oc[x] > 0)
            cout<<"y"<<endl;
        else
            cout<<"n"<<endl;    

}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T;
    cin>>T;
    while (T--)
        solve();    
}