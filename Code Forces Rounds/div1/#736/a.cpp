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
const int MAXN = 2e5 + 10;

int deg[MAXN], ans;

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m;

	cin>>n>>m;

	int u, v;
	fr(i, m){
		cin>>u>>v;
		if (u > v)
			swap(u, v);
		deg[u]++;
	}

	frr(i, n)
		if (deg[i] > 0){
			ans++;
		}

	int q;
	cin>>q;

	int typ;
	while (q--){
		cin>>typ;

		if (typ == 1){
			cin>>u>>v;
			if (u > v)
				swap(u, v);
			if (deg[u] == 0)
				ans++;

			deg[u]++;
		}
		else if (typ == 2){
			cin>>u>>v;

			if (u > v)
				swap(u, v);
			deg[u]--;
			if (deg[u] == 0)
				ans--;
		}
		else{
			cout<<n - ans<<endl;
		}
	}	

}