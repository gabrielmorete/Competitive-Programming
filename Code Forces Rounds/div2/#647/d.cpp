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
const int MAXN = 5e5 + 10;
const ll mod = 1e9+7;

int n, m, t[MAXN], ans[MAXN], freq[MAXN];
vi adj[MAXN], tpc[MAXN];

int32_t main(){
	fastio;
	cin>>n>>m;

	int a, b;
	fr(i, m){
		cin>>a>>b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	
	frr(i, n){
		cin>>a;
		t[i] = a;
		tpc[a].pb(i);
	}

	bool ok;
	int cnt = 0, viz;
	for (int cor = 1; cor <= n; cor++){
		for (int v : tpc[cor]){
			viz = 0;
			ok = 1;
			
			for (int x : adj[v])
				if (ans[x] != 0 and freq[ans[x]] != cnt){
					freq[ans[x]] = cnt;
					viz++;
					if (ans[x] == cor)
						ok = 0;
				}
			
			if (viz != cor - 1 or ok == 0){
				cout<<-1<<endl;
				return 0;
			}

			ans[v] = cor;
			cnt++;
		}
	}

	for (int cor = 1; cor <= n; cor++)
		for (int v : tpc[cor])
			cout<<v<<' ';
	gnl;

}