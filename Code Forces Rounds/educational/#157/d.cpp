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
const int MAXN = 2e6 + 10;

int n, a[MAXN];

int adj[MAXN][2], en = 1;

void add(int v){
	int p = 0;
	for (int i = 20; i >= 0; i--){
		int x = 0; 
		if (v & (1<<i))
			x = 1;	

		if (adj[p][x] == -1)
			adj[p][x] = en++;

		p = adj[p][x];
	}
}

int get_max(int v){
	int p = 0;
	int ans = 0;

	for (int i = 20; i >= 0; i--){
		int x = 0; 
		if (v & (1<<i))
			x = 1;	

		if (adj[p][1 - x] != -1){
			ans += 1<<i;
			p = adj[p][1 - x];
		}
		else
			p = adj[p][x];
	}

	return ans;
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin>>n;

	frr(i, n - 1)
		cin >> a[i];

	frr(i, n - 1)
		a[i] ^= a[i - 1];

	memset(adj, -1, sizeof(adj));	

	fr(i, n)
		add(a[i]);

	fr(x, n)
		if (get_max(x) < n){
			fr(i, n)
				cout << (a[i] ^ x) << ' ';
			gnl;
			return 0;
		}	

}