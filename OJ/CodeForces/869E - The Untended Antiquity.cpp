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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MAXN = 3e3 + 10;


#define int long long

// Segtree 2d iterativa
// complexidade:
// 		build O(nm)
// 		update O(log(n)log(m))
// 		query O(log(n)log(m))


// operações no quadrado [0, n) x [0, m)

#define oper(a, b) a ^ b // operação
#define NEUT 0 // elemento neutro

int n, m;
ll a[MAXN][MAXN], seg[2*MAXN][2*MAXN];
void build(){
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			seg[i + n][j + m] = a[i][j];
	for (int i = 0; i < n; i++)
		for (int j = m - 1; j > 0; j--)	
			seg[i + n][j] = oper(seg[i+n][j<<1], seg[i+n][j<<1|1]);
	for (int i = n - 1; i > 0; i--)
		for (int j = 0; j < m<<1; j++)	
			seg[i][j] = oper(seg[i<<1][j], seg[i<<1|1][j]);
}

void update(int x, int y, int v){
	seg[x + n][y + m] = v; // define o valor
	for (int j = y + m; j > 1; j >>= 1)
		seg[x + n][j>>1] = oper(seg[x+n][j], seg[x+n][j^1]);
	for (int i = x + n; i > 1; i >>= 1)
		for (int j = y + m; j > 0; j>>= 1)
			seg[i>>1][j] = oper(seg[i][j], seg[i^1][j]);
}

// query no quadado [x0, x1) x [y0, y1), aberto acima e na direita
ll query(int x0, int x1, int y0, int y1){
	ll r = NEUT;
	for(int i0 = x0 + n, i1 = x1 + n; i0 < i1; i0>>=1, i1>>=1){
		int t[4], q = 0;
		if (i0 & 1) t[q++] = i0++;
		if (i1 & 1) t[q++] = --i1;
		for (int k = 0; k < q; k++)
			for (int j0 = y0 + m, j1 = y1 + m; j0 < j1; j0>>=1, j1>>=1){
				if (j0 & 1) r = oper(r, seg[t[k]][j0++]);
				if (j1 & 1) r = oper(r, seg[t[k]][--j1]);
			}
	}
	return r;
}


int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int q;
	
	cin>>n>>m>>q;
	n++;
	m++;

	int x1, x2, y1, y2, t;
	while (q--){
		cin>>t>>x1>>y1>>x2>>y2;
		x1--;
		y1--;
		if (t == 1){
			ll val = uniform_int_distribution<ll>(0, llINF)(rng);
			update(x1, y1, val);
			update(x1, y2, val);
			update(x2, y1, val);
			update(x2, y2, val);
		}
		else if (t == 2){
			update(x1, y1, 0);
			update(x1, y2, 0);
			update(x2, y1, 0);
			update(x2, y2, 0);
		}
		else{
			if (query(0, x1 + 1, 0, y1 + 1) == query(0, x2, 0, y2))
				cout<<"Yes"<<endl;
			else
				cout<<"No"<<endl;
		}
	}
}