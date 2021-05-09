#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fst first
#define snd second

#define fr(i,n)     for (int i = 0; i < n; i++)
#define frr(i,n)    for (int i = 1; i <= n; i++)

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
const int MAXN = 1e6 + 10;

vector<ll> v[MAXN], adj[MAXN];
ll vis[MAXN];

void dfs(int v, int c){
	vis[v] = c;

	if (c == 1)
		c = 2;
	else
		c = 1;

	for (auto x : adj[v])
		if (vis[x] == 0)
			dfs(x, c);
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	ll n;
	cin>>n;

	if (n % 2 == 0){
		cout<<"First"<<endl;
		for (int i = 0; i < 2 * n; i++)
			cout<<((i % n) + 1)<<' ';
		cout<<endl;
	}
	else{
		cout<<"Second"<<endl;
		ll x;
		frr(i, 2 * n){
			cin>>x;
			v[x].pb(i);
		}

		frr(i, n){
			adj[i].pb(i + n);
			adj[i + n].pb(i);
		}

		frr(i, n){
			adj[v[i][0]].pb(v[i][1]);
			adj[v[i][1]].pb(v[i][0]);
		}

		frr(i, 2*n)
			if (vis[i] == 0)
				dfs(i, 1);

		ll sum = 0;	
		frr(i, 2 * n)	
			if (vis[i] == 1)
				sum += i;
		if (sum % 2*n == 0){
			frr(i, 2 * n)
				if (vis[i] == 1)
					cout<<i<<' ';
			gnl;	
		}
		else{
			frr(i, 2 * n)
				if (vis[i] == 2)
					cout<<i<<' ';
			gnl;
		}	
	}
}