#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i,n)     for(int i=0;i<n;i++)
#define frr(i,n)    for(int i=1;i<=n;i++)

#define ms(x,i) memset(x,i,sizeof(x))
#define dbg(x)  cout << #x << " = " << x << endl
#define all(x)  x.begin(),x.end()

#define gnl cout << endl
#define chapa cout << "oi meu chapa" << endl
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
//cout << setprecision(9)<<fixed;

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = (long long)(1e18) + 100;   
const int MAXN = 100100;
const int MAXM = 1001000;
const ll mod=1e9+7;
const int LMAXN = 25;

int n, m, pai[212345], in[212345], out[212345], clk;
vii v;
vi adj[212345];

void dfs(int v){
	in[v] = clk++;
	for (int x : adj[v]){
		if (x != pai[v]){
			pai[x] = v;
			dfs(x);
		}
	}
	out[v] = clk++;
}

int main(){
	fastio;
	cin>>n>>m;
	frr(i, n)
		adj[i].clear();
	int a, b;
	fr(i, n - 1){
		cin>>a>>b;
		adj[a].pb(b);
		adj[b].pb(a);
	}

	clk = 0;
	pai[1] = 1;
	dfs(1);

	int k;
	while (m--){
		v.clear();

		cin>>k;
		fr(i, k){
			cin>>a;
			v.pb({in[pai[a]], out[pai[a]]});
		}
		sort(all(v));

		int e, s;

		bool ok = 1;
		int out = get<1>(v[0]);

		frr(i, v.size() - 1){
			e = get<0>(v[i]);
			
			if (e > out)
				ok = 0;
			out = get<1>(v[i]);
		}
		if (ok)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}

}