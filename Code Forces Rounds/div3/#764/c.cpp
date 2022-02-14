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
const int MAXN = 70;

vector<int> adju[MAXN];
int matchu[MAXN], matchv[MAXN];
int vis[MAXN], iter;
int m, n;


bool dfs(int u){
	vis[u] = iter;
	if (u == 0) return true;
		for (int &v : adju[u]){
			if (vis[matchv[v]] < iter and dfs(matchv[v])){
				matchv[v] = u; 
				matchu[u] = v;
				return true;
			}
		}
	return false;
}

int kuhn(){
	memset(&matchu, 0, sizeof matchu);
	memset(&matchv, 0, sizeof matchv);
	memset(&vis, 0, sizeof vis);
	iter = 0;
	int result = 0;
	for (int u = 1; u <= m; u++){
		iter++;
		if (matchu[u] == 0 and dfs(u)) 
			result++;
	}
	return result;
}



void solve(){
	cin>>m;
	n = m;

	frr(i, n)
		adju[i].clear();

	frr(i, n){
		ll x;
		cin>>x;

		while (x > 0){
			if (x <= n)
				adju[i].pb(x);
			x >>= 1;
		}
	}

	if (kuhn() == n)
		cout<<"Yes"<<endl;
	else
		cout<<"No"<<endl;
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;
	while (T--)
		solve();
}