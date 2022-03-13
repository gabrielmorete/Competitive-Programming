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
const int MAXN = 4e5 + 10;

int mx[4] = {+1, -1, 0, 0};
int my[4] = {0, 0, +1, -1};

int n;
vii v, ans;
map<pii, int> crd;

int vis[MAXN];

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin>>n;

	fr(i, n){
		int x, y;
		cin>>x>>y;
		v.pb({x, y});
		crd[{x, y}] = i;
	}

	fr(i, n)
		ans.pb({INF, INF});

	queue<int> fila;

	fr(i, n){
		pii p = {INF, INF};

		fr(k, 4){
			int x = v[i].fst + mx[k];
			int y = v[i].snd + my[k];
			if (!crd.count({x, y})) // free neighbour
				p = {x, y};
		}

		if (p != make_pair(INF, INF)){
			ans[i] = p;
			fila.push(i);
			vis[i] = 1;
		}
	}

	while (!fila.empty()){
		int u = fila.front();
		fila.pop();

		fr(k, 4){
			int x = v[u].fst + mx[k];
			int y = v[u].snd + my[k];

			if (crd.count({x, y}) and !vis[crd[{x, y}]]){
				ans[crd[{x, y}]] = ans[u];
				vis[crd[{x, y}]] = 1;
				fila.push(crd[{x, y}]);
			}
		}		
	}

	fr(i, n)
		cout<<ans[i].fst<<' '<<ans[i].snd<<endl;
}