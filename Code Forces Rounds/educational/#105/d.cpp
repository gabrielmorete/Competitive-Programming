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
const int MAXN = 1e3 + 10;

int n, id[MAXN], sz[MAXN], val[MAXN][MAXN], mn[MAXN];

int find(int a){
	if (a == id[a])
		return a;
	return id[a] = find(id[a]);
}

bool merge(int a, int b){
	a = find(a);
	b = find(b);
	if (a == b) return false;
	if (sz[a] < sz[b]) swap(a, b);
	sz[a] += sz[b];
	id[b] = a;
	return true;
}

int get_min(int v){
	int ans = -1;
	fr(i, n)
		if (find(i) != find(v)){
			if (ans == -1)
				ans = val[find(v)][find(i)];
			ans = min(ans, val[find(v)][find(i)]);
		}

	return ans;	
}

int pai[MAXN], sal[MAXN], k, emp[MAXN], nemp[MAXN];
bool mrg[MAXN];


int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	fr(i, MAXN){
		id[i] = i;
		sz[i] = 1;
		emp[i] = i;
	}

	cin>>n;

	fr(i, n)
		fr(j, n)
			cin>>val[i][j];

	fr(i, n)
		sal[i] = val[i][i];		

	int actv = n;
	k = n;

	while (actv > 1){
		// dbg(actv);
	
		int mng = -1;	
		vi act;
		fr(i, n){
			if (i == find(i)){
				mn[find(i)] = get_min(find(i));
				if (mng == -1)
					mng = mn[find(i)];
				mng = min(mng, mn[find(i)]);

				act.pb(i);
				mrg[i] = 0;
			}
		}

		for (int u : act)
			for (int v : act)
				if (u != v){
					if (mn[u] == mn[v] and val[u][v] == mn[u] and mn[u] == mng){ // juntar
						if (merge(u, v)){
							mrg[u] = mrg[v] = 1;
							actv--;
						}
					}
				}	

		for (int x : act)
			if (x == find(x) and mrg[x]){
				nemp[x] = k++;
				sal[nemp[x]] = mn[x];		
			}
			
		for (int x : act)		
			if (mrg[x])
				pai[emp[x]] = nemp[find(x)];
			

		for (int x : act)
			if (x == find(x) and mrg[x])
				emp[x] = nemp[x];
	}		

	
	cout<<k<<endl;
	fr(i, k)
		cout<<sal[i]<<' ';
	gnl;	
	cout<<k<<endl;
	fr(i, k - 1)
		cout<<i + 1<<' '<<pai[i] + 1<<endl;

}