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

pii operator+(pii a, pii b){
	return {a.fst + b.fst, a.snd + b.snd};	
}

int n;
vi adj[MAXN];
pii memo[MAXN][2];

pii best(int v){
	if (memo[v][0].fst > memo[v][1].fst)
		return memo[v][0];
	if (memo[v][0].fst < memo[v][1].fst)
		return memo[v][1];

	return {memo[v][0].fst, min(memo[v][0].snd, memo[v][1].snd)};
}

pii dfs(int v, int p, int state){
	if (memo[v][state].fst != -1)
		return memo[v][state];

	pii &pdm = memo[v][state];

	if (state){
		pdm = {1, adj[v].size()};

		for (auto x : adj[v])
			if (x != p)
				pdm = pdm + dfs(x, v, 0);
	}
	else{
		pdm = {0, 1};

		for (auto x : adj[v])
			if (x != p){
				dfs(x, v, 0);
				dfs(x, v, 1);

				pdm = pdm + best(x);
			}
	}

	return pdm;
}

ll val[MAXN];

void rec(int v, int p, int state){
	if (state){
		val[v] = adj[v].size();
		for (auto x : adj[v])
			if (x != p)
				rec(x, v, 0);
	}else{
		val[v] = 1;
		for (auto x : adj[v])
			if (x != p){
				if (best(x) == memo[x][0])
					rec(x, v, 0);
				else
					rec(x, v, 1);
			}
	}
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin>>n;

	if (n == 2){
		cout<<"2 2"<<endl;
		cout<<"1 1"<<endl;
		return 0;
	}

	fr(i, n - 1){
		int a, b;
		cin>>a>>b;
		
		adj[a].pb(b);
		adj[b].pb(a);
	}

	frr(i, n)
		fr(j, 2)
			memo[i][j] = {-1, -1};

	dfs(1, 1, 1);
	dfs(1, 1, 0);

	pii ans = best(1);

	if (ans == memo[1][0])
		rec(1, 1, 0);
	else
		rec(1, 1, 1);

	cout<<ans.fst<<' '<<ans.snd<<endl;

	frr(i, n)
		cout<<val[i]<<' ';
	gnl;
}