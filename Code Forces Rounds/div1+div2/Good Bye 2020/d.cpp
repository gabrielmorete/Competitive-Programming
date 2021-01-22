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
#define all(x)  x.begin(),x.end()

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

const int INF = 0x3f3f3f3f;
const ll llINF = (long long)(1e18) + 100;   
const int MAXN = 2e5 + 10;

int deg[MAXN];
ll w[MAXN];

void solve(){
	int n;
	cin>>n;

	frr(i, n + 10)
		deg[i] = -1;

	ll ans = 0;	

	frr(i, n){
		cin>>w[i];	
		ans += w[i];
	}

	int u, v;	
	fr(i, n - 1){
		cin>>u>>v;
		deg[u]++;
		deg[v]++;
	}

	priority_queue<pii> pq;

	frr(i, n)
		if (deg[i] > 0)
			pq.push({w[i], i});

	cout<<ans<<' ';

	int vtx;
	while (!pq.empty()){
		tie(ignore, vtx) = pq.top();
		pq.pop();

		while (deg[vtx] > 0){
			ans += w[vtx];
			cout<<ans<<' ';
			deg[vtx]--;
		}
	}

	gnl;
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int T;
	cin>>T;

	while (T--)
		solve();
}