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

int n, k;
int id[MAXN], sz[MAXN], tme[MAXN];
map<int, vii> lin, col;

int find(int a){
	if (a == id[a])
		return a;
	return id[a] = find(id[a]);
}

void merge(int a, int b){
	a = find(a);
	b = find(b);
	if (a == b)
		return;

	if (sz[a] < sz[b])
		swap(a, b);

	id[b] = a;
	sz[a] += sz[b];
	tme[a] = min(tme[a], tme[b]);
}


void solve(){
	lin.clear();
	col.clear();

	cin>>n>>k;

	frr(i, n){
		id[i] = i;
		sz[i] = 1;
	}

	frr(i, n){
		int x, y, z;
		cin>>x>>y>>z;

		tme[i] = z;

		lin[x].pb({y, i});
		col[y].pb({x, i});
	}

	for (auto e : lin){
		vii &v = e.snd;

		sort(all(v));
		int p = 0;
		int m = v.size();
		
		fr(i, m){
			p = max(p, i);
			merge(v[i].snd, v[p].snd);
			while (p < m - 1 and v[p + 1].fst - v[i].fst <= k){
				p++;
				merge(v[i].snd, v[p].snd);
			}
		}
	}

	for (auto e : col){
		vii &v = e.snd;

		sort(all(v));
		int p = 0;
		int m = v.size();
		
		fr(i, m){
			p = max(p, i);
			merge(v[i].snd, v[p].snd);
			while (p < m - 1 and v[p + 1].fst - v[i].fst <= k){
				p++;
				merge(v[i].snd, v[p].snd);
			}
		}
	}

	vi v;
	frr(i, n)
		if (find(i) == i){
			v.pb(tme[i]);
		}

	sort(all(v));
	
	int m = v.size();

	int p = 0;
	int q = m - 1;
	fr(t, n + 1){
		while (p < m and v[p] <= t) // expludiu naturalmente
			p++;
		q--; // componente expludiu na mao

		if (q < p){
			cout<<t<<endl;
			return;
		}
	}	
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;
	while (T--)
		solve();
}