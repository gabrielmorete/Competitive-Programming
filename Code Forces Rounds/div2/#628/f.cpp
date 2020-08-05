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
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
//cout << setprecision(9)<<fixed;

#define dbg(x)  cout << #x << " = " << x << endl
#define all(x)  x.begin(),x.end()

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

const int INF = 0x3f3f3f3f;
const ll llINF = (long long)(1e18) + 100;   
const int MAXN = 1e5 + 10;

int N;
int n, m, is[MAXN], hgt[MAXN];
vi adj[MAXN], seq;



void dfs(int v){
	seq.pb(v);
	hgt[v] = seq.size();
	for (int x : adj[v]){
		if (hgt[x] == 0)
			dfs(x);
		else if (hgt[v] - hgt[x] + 1 >= N){
			
			cout<<2<<endl;
			cout<<hgt[v] - hgt[x] + 1<<endl;

			for (int i = hgt[x] - 1; i < hgt[v]; i++)
				cout<<seq[i]<<' ';
			gnl;
			exit(0);
		}
	}

	if (!is[v]){
		for (int x : adj[v])
			is[x] = 1;
	}

	seq.pop_back();
}

int32_t main(){
	fastio;
	cin>>n>>m;

	int a, b;
	fr(i, m){
		cin>>a>>b;
		adj[a].pb(b);
		adj[b].pb(a);
	}

	while (N * N < n)
		N++;

	dfs(1);

	cout<<1<<endl;
	frr(i, n)
		if (!is[i] and N){
			cout<<i<<' ';
			N--;
		}
	gnl;	
}