// Segtree 2d iterativa
// complexidade:
// 		build O(nm)
// 		update O(log(n)log(m))
// 		query O(log(n)log(m))
// operações no quadrado [0, n) x [0, m)

const int MAXN = 5e3 + 10;

#define oper(a, b) a + b // operação
#define NEUT 0 // elemento neutro

int n, m;
ll a[MAXN][MAXN], seg[2*MAXN][2*MAXN];
void build(){
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			seg[i + n][j + m] = a[i][j]; // valor inicial
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
ll query(int x0, int y0, int x1, int y1){
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