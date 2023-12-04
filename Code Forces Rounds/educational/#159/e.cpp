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
const int MAXN = 2e6 + 10;

int en = 1, pa[MAXN];
vector<int> lst; // Node of the ocurrence of the pattern
struct no{
	char c;
	int cnt, mrk; // How many pass, how many end
	map<char, int> m;
	no(){mrk = cnt = 0; m.clear();}
} t[MAXN];

inline int new_node(int p, char c){
	t[en] = no();
	pa[en] = p;
	t[en].c = c;
	return en++;
}

inline void init(){t[0] = no(); en = 1; lst.clear();}

void add(int v, int pos, string &s){
	while (pos < s.size()){
		if (!t[v].m.count(s[pos]))
			t[v].m[s[pos]] = new_node(v, s[pos]);
		v = t[v].m[s[pos]];
		t[v].cnt++;
		pos++;
	}
	t[v].mrk = 1;
	lst.pb(v); // This word end in this node
}

ll getans(string &s){
	int v = 0;
	ll ans = 0;

	for (auto x : s){
		if (!t[v].m.count(x))
			break;
		v = t[v].m[x];
		ans += t[v].cnt;
	}

	return ans;
}

int n;
vector<string> words;

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin>>n;

	words.resize(n);

	fr(i, n)
		cin>>words[i];


	ll ans = 0;
	for (auto s : words){
		add(0, 0, s);	
		ans += s.size();
	}

	ans *= 2 * n;

	for (auto s : words){
		reverse(all(s));
		ans -= 2 * getans(s);
	}

	cout << ans << endl;
}