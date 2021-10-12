#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fst first
#define snd second

#define fr(i,n)     for (int i = 0; i < n; i++)
#define frr(i,n)    for (int i = 1; i <= n; i++)

// #define endl '\n'
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
const int MAXN = 1e3 + 10;
const ll mod = 998244353;

ll n, m, k, a[MAXN], freq[MAXN];
map<pii, int> crd;

vi adj[MAXN];

bool rec(int v, int p, int d){
	if (v == d)
		return true;

	for (auto x : adj[v]){
		if (x != p){
			if (rec(x, v, d)){
				freq[ crd[{v, x}] ]++;
				return true;
			}
		}
	}

	return false;
}

vi item;

ll memo[300100];


signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin>>n>>m>>k;

	frr(i, m)
		cin>>a[i];

	int x, y;
	fr(i, n - 1){
		cin>>x>>y;
		adj[x].pb(y);
		adj[y].pb(x);
	
		crd[{x, y}] = crd[{y, x}] = i + 1;
	}	

	frr(i, m){
		rec(a[i], a[i], a[i + 1]);
	}


	int s = 0;	
	frr(i, n - 1){
		if (freq[i] > 0){
			s += freq[i];
			item.pb(freq[i]);
		}
	}

	int f = (s + k)/2;

	if ((s + k) % 2){
		cout<<0<<endl;
		return 0;
	}

	if (f < 0 or f > 200000){
		cout<<0<<endl;
		return 0;
	}	


	ll ans = 0;
	ll h = 0;
	memo[0] = 1;
	for (int i = 0; i < item.size(); i++){
		for (int j = h; j >= 0; j--){
			memo[j + item[i]] = (memo[j] + memo[j + item[i]]) % mod;
		}
		h += item[i];
	}

	ans = memo[f];


	frr(i, n - 1)
		if (freq[i] == 0){
			ans = (ans * 2) % mod;
		}

	cout<<ans<<endl;
}