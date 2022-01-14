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

int n, k;
vi pos;
vii v;

int seg[4 * MAXN];
void update(int node, int l, int r, int p, int val){
	if (p < l or r < p)
		return;

	if (l == r){
		seg[node] = val;
		return;
	}

	int m = (l + r)/2;

	update(node<<1, l, m, p, val);
	update(node<<1|1, m + 1, r, p, val);
	seg[node] = max(seg[node<<1], seg[node<<1|1]);;
}

int query(int node, int l, int r, int ql, int qr){
	if (qr < l or r < ql)
		return -INF;
	if (ql <= l and r <= qr)
		return seg[node];

	int m = (l + r)/2;

	return max(query(node<<1, l, m, ql, qr), query(node<<1|1, m + 1, r, ql, qr));
}


pii get_itv(int p, int dst){
	int dl = -dst;
	int dr = dst;
	
	if (p != n){
		dl += pos[p];
		dr += pos[p];
	}

	int l = int(lower_bound(all(pos), dl) - pos.begin());
	int r = int(upper_bound(all(pos), dr) - pos.begin());
	r--;

	if (l == n) // só acontece no caso zero
		return {1, 0};

	return {l, r};
}

vii adj[MAXN][28];
int dist[MAXN][28], rev[MAXN];
bool visible[MAXN][28];


vii getk(int l, int r){
	vii ans;

	fr(i, k){
		ll aux = query(1, 0, n - 1, l, r);
		if (aux < 0)
			break;

		ans.pb({aux, rev[aux]});
		update(1, 0, n - 1, rev[aux], -10);
	}

	for (auto x : ans)
		update(1, 0, n - 1, x.snd, x.fst);

	return ans;
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin>>n>>k;

	frr(i, n){
		int x;
		cin>>x;
		v.pb({x, i});
	}

	sort(all(v)); // por posição

	for (int i = 0; i < n; i++){
		pos.pb(v[i].fst);
		rev[v[i].snd] = i;
		update(1, 0, n - 1, i, v[i].snd); // nessa posição do vetor temos esse valor
	}

	// caso zero
	int dst = 1, l, r;
	for (int pwr = 0; pwr < 28; pwr++){ // potencia
		// dbg(dst);
		tie(l, r) = get_itv(n, dst);
		dst <<= 1;

		if (l > r) continue; // vazio

		vii q = getk(l, r);

		for (auto x : q)
			adj[n][pwr].pb({x.snd, pwr});
	}

	for (int i = 0; i < n; i++){
		dst = 1;
		for (int pwr = 0; pwr < 28; pwr++){ // potencia
			tie(l, r) = get_itv(i, dst);

			assert(l <= r);

			vii q = getk(l, r);

			for (auto x : q){
				adj[i][pwr].pb({x.snd, pwr});
				if (x.snd == i)
					visible[i][pwr] = 1;
			}

			dst <<= 1;
		}
	}	

	memset(dist, -1, sizeof dist);
	queue<pii> fila;
	dist[n][0] = 0;
	fila.push({n, 0});// custo zero, no zero, com zoom zero

	int vtx, zm;
	while (!fila.empty()){
		tie(vtx, zm) = fila.front();
		fila.pop();

		for (auto x : adj[vtx][zm])
			if (dist[x.fst][x.snd] == -1){
				dist[x.fst][x.snd] = dist[vtx][zm] + 1;
				fila.push({x.fst, x.snd});
			}

		if (zm > 0 and dist[vtx][zm - 1] == -1){
			dist[vtx][zm - 1] = dist[vtx][zm] + 1;
			fila.push({vtx, zm - 1});
		}	
	
		if (zm < 27 and dist[vtx][zm + 1] == -1){
			dist[vtx][zm + 1] = dist[vtx][zm] + 1;
			fila.push({vtx, zm + 1});
		}	
		adj[vtx][zm].clear();
	}

	frr(i, n){
		dst = INF;
		if (dist[rev[i]][0] != -1)
			dst = dist[rev[i]][0] + 1;

		fr(pwr, 28)
			if (dist[rev[i]][pwr] != -1 and visible[rev[i]][pwr])
				dst = min(dst, dist[rev[i]][pwr]);
		
		if (dst == INF)
			dst = -1;	
		cout<<dst<<endl;
	}
}