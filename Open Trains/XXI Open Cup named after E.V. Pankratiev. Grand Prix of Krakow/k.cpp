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

const int INF = 1e5;
const ll llINF = (long long)(1e18) + 100;   
const int MAXN = 2e3 + 10;

int n, k, dist[MAXN][MAXN];
bool used[MAXN];
vi line[MAXN];

void solve(){
	cin>>n>>k;

	frr(i, k){
		used[i] = 0;
		line[i].clear();	
		int m, x;
		cin>>m;
		fr(j, m){
			cin>>x;
			line[i].pb(x);
		}
	}

	int q;
	vi v;

	cin>>q;
	fr(i, q){
		int x;
		cin>>x;
		v.pb(x);
		used[x] = 1;
	}

	frr(i, k)
		if (!used[i])
			v.pb(i);

	reverse(all(v));

	vi ans;

	for (int i = 1; i <= n + k; i++)
		for (int j = 1; j <= n + k; j++)
			dist[i][j] = INF;	

	frr(i, n + k)
		dist[i][i] = 0;

	for (auto x : v)
		for (auto e : line[x]){
			dist[e][x + n] = 1; // do vertice pra linha
			dist[x + n][e] = 0; // da linha pro vertice
		}

	for (int x = 1; x <= n; x++)
		for (int i = 1; i <= n + k; i++)
			for (int j = 1; j <= n + k; j++)
				if (dist[i][j] > dist[i][x] + dist[x][j])
					dist[i][j] = dist[i][x] + dist[x][j];	
	

	for (auto x : v){
		for (int i = 1; i <= n + k; i++)
			for (int j = 1; j <= n + k; j++)
				if (dist[i][j] > dist[i][x + n] + dist[x + n][j])
					dist[i][j] = dist[i][x + n] + dist[x + n][j];
		
		int dst = 0;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (dist[i][j] < INF)
					dst = max(dst, dist[i][j]);

		if (!used[x])
			ans.clear();
		ans.pb(dst);		
	}

	reverse(all(ans));

	for (auto x : ans)
		cout<<max(x - 1, 0)<<endl;
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;
	while (T--)
		solve();
}