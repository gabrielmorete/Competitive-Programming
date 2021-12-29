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

int n, lft[MAXN], rgt[MAXN], deg[MAXN];
array<int, 3> ans[MAXN];


void solve(){
	cin>>n;

	fr(i, n)
		cin>>lft[i]>>rgt[i];

	fr(i, n)
		fr(j, n)
			if (i != j and lft[i] <= lft[j] and rgt[j] <= rgt[i])
				deg[j]++;

	int cnt = 0;

	queue<int> fila;

	fr(i, n)
		if (deg[i] == 0)		
			fila.push(i);

	while (!fila.empty()){
		int v = fila.front();
		fila.pop();

		int u = rgt[v];

		fr(j, n)
			if (v != j and lft[v] <= lft[j] and rgt[j] <= rgt[v]){
				deg[j]--;
				if (deg[j] == 0){
					fila.push(j);
					if (rgt[v] == rgt[j])
						u = lft[j] - 1;
					else
						u = rgt[j] + 1;
				}
			}

		ans[cnt++] = {lft[v], rgt[v], u};
	}

	fr(i, cnt)
		cout<<ans[i][0]<<' '<<ans[i][1]<<' '<<ans[i][2]<<endl;	



}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;
	while (T--)
		solve();
}