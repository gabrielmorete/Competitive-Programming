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

ll ways[2123];
vi adj[21234];
int freq[212345];

bool vis[2123];
void dfs(int v){
	vis[v] = 1;
	for (auto x : adj[v]){
		if (vis[x])
			continue;
		dfs(x);
	}
}

int main(){
	fastio;
	int n, l;
	cin>>n>>l;

	int k, x;
	frr(i,l){
		cin>>k;
		fr(j,k){
			cin>>x;
			adj[i].pb(x);
			freq[x]++;
		}
	}

	queue<int> fila;

	frr(i,n)
		if(freq[i] == 0)
			fila.push(i);

	ways[1] = 1;
	int aux;
	while (!fila.empty()) {
		aux = fila.front();
		fila.pop();

		for (auto x : adj[aux]) {
			ways[x] = (ways[x] + ways[aux]) % mod;
			freq[x]--;
			if (freq[x] == 0)
				fila.push(x);
		}
	}

	ll ans = 0;
	for (int i = l + 1; i <= n; i++)
		ans = (ans + ways[i]) % mod;	
	cout<<ans<<' ';

	vis[1] = 1;
	dfs(1);

	ans = 0;
	for (int i = l + 1; i <= n; i++)
		ans += vis[i];
	cout<<ans<<endl;
}