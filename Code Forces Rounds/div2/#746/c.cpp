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
const int MAXN = 1e5 + 10;

int n, k, a[MAXN], val, xr[MAXN], num;
map<int, int> freq;

vi adj[MAXN];

bool ok, tem;

bool dfs1(int v, int p){
	xr[v] = a[v];

	bool got = 0;

	for (auto x : adj[v])
		if (x != p){
			got |= dfs1(x, v);

			xr[v] = xr[v]^xr[x];


			if ((val^xr[x]) == xr[x])//achei
				ok = 1;
		}

	if (xr[v] == val and !got){
		num++;
		got = 1;
	}

	if (xr[v] == 0 and got){
		tem = 1;
	}


	freq[xr[v]]++;

	return got;
}

void solve(){
	freq.clear();

	cin>>n>>k;

	num = 0;

	val = 0;
	frr(i, n){
		cin>>a[i];
		val ^=a[i];
	}

	frr(i, n){
		adj[i].clear();
		xr[i] = 0;
	}

	fr(i, n - 1){
		int x, y;
		cin>>x>>y;
		adj[x].pb(y);
		adj[y].pb(x);
	}

	ok = 0, tem = 0;

	dfs1(1, 1);	


	if (k > 2 and num > 1)
		ok = 1;	


	if (k > 2 and tem)
		ok = 1;	


	if (ok)
		cout<<"yes"<<endl;
	else
		cout<<"no"<<endl;

}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;
	while (T--)
		solve();
}