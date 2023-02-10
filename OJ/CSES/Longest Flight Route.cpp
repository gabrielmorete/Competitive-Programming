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

int n, m, indeg[MAXN], ans[MAXN], pai[MAXN];
vector<int> adj[MAXN];

void print(int v){
	if (v == 0) return;
	print(pai[v]);
	cout<<v<<' ';
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin>>n>>m;
	fr(i, m){
		int a, b;
		cin>>a>>b;
		indeg[b]++;
		adj[a].pb(b);
	}

	queue<int> fila;

	frr(i, n)
		ans[i] = -n;

	ans[1] = 1;

	frr(i, n)
		if (indeg[i] == 0)
			fila.push(i);

	while (!fila.empty()){
		int v = fila.front();
		fila.pop();

		for (auto x : adj[v]){
			indeg[x]--;
			if (ans[x] < ans[v] + 1){
				ans[x] = ans[v] + 1;
				pai[x] = v;
			}
			if (indeg[x] == 0)
				fila.push(x);
		}
	}	

	if (ans[n] < 0)
		cout<<"IMPOSSIBLE"<<endl;
	else{
		cout<<ans[n]<<endl;
		print(n);
		gnl;
	}
}