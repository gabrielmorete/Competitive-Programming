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
const int MAXN = 4e5 + 10;

int n, k, lft[MAXN], rgt[MAXN];
string s;

vector<pair<int, char>> ans;

char nxt[MAXN];

void dfs1(int v){
	if (v == 0) return;
	dfs1(lft[v]);
	ans.pb({v, s[v - 1]});
	dfs1(rgt[v]);
}

int pai[MAXN], dup[MAXN];

void dfs2(int v, int cst){
	if (v == 0)
		return;
	pai[lft[v]] = v;
	pai[rgt[v]] = v;


	dfs2(lft[v], cst + 1);

	if (!dup[v] and s[v - 1] < nxt[v] and cst <= k){
		k -= cst;
		cst = 0;
		int u = v;
		while (u != 1 and !dup[u]){
			dup[u] = 1;
			u = pai[u];
		}
		dup[u] = 1;
	}

	if (dup[v])
		dfs2(rgt[v], 1);
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin>>n>>k;
	cin>>s;

	frr(i, n)
		cin>>lft[i]>>rgt[i];
	
	dfs1(1);

	nxt[ans.back().fst] = 0;
	char a = ans.back().snd;
	char b = 0;	

	for (int i = n - 2; i >= 0; i--){
		int u = ans[i].fst;
		char c = ans[i].snd;

		if (c != a){
			nxt[u] = a;
			b = a;
			a = c;
		}
		else
			nxt[u] = b;
	}

	dfs2(1, 1);

	for (auto x : ans){
		cout<<x.snd;
		if (dup[x.fst])
			cout<<x.snd;
	}
	gnl;
}