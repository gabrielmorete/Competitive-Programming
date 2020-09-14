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
#define all(x)  x.begin(),x.end()

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

const int INF = 0x3f3f3f3f;
const ll llINF = (long long)(1e18) + 100;   
const int MAXN = 3e2 + 10;

int n, m, k, cst[MAXN];

int mx[4] = {1, -1, 0, 0};
int my[4] = {0, 0, -1, 1};

bool valid(int x, int y){return (x >= 0 and y >= 0) and (x < n and y < m);}

int crd(int x, int y){ return x * m + y;}

vi nxt[1<<10][MAXN];
int memo[1<<10][MAXN];

char ans[MAXN][MAXN];

void pans(int msk, int v){ // preenche o tabuleiro
	int x, y;
	tie(x, y) = make_pair(v / m, v % m);
	ans[x][y] = 'X';

	if (nxt[msk][v].size() == 1){ // trocou a raiz
		pans(msk, nxt[msk][v].back());
	}
	else if (nxt[msk][v].size() == 2){ // dividiu em 2 mask
		pans(nxt[msk][v][0], v);
		pans(nxt[msk][v][1], v);
	}
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	
	cin>>n>>m>>k;

	fr(i, n)
		fr(j, m){
			ans[i][j] = '.';
			cin>>cst[crd(i, j)];
		}

	memset(memo, INF, sizeof memo);

	vi term;			
	fr(i, k){
		int x, y;
		cin>>x>>y;
		term.pb(crd(x - 1, y - 1));
	}

	if (k == 1){
		cout<<cst[term.back()]<<endl;
		pans(0, term.back());
		fr(i, n){
			fr(j, m)
				cout<<ans[i][j];
			gnl;	
		}
		return 0;
	}

	fr(i, k) // valor inicial somente os terminais
		memo[1<<i][term[i]] = cst[term[i]];

	for (int mask = 1; mask < (1<<k); mask++){
		for (int v = 0; v < n * m; v++){
			for (int smask = (mask - 1)&mask; smask > 0; smask = (smask - 1)&mask)
				if (memo[mask][v] > memo[smask][v] + memo[mask^smask][v] - cst[v]){
					memo[mask][v] = memo[smask][v] + memo[mask^smask][v] - cst[v];
					nxt[mask][v] = {smask, mask ^ smask};
				}
		}
		
		fr(iter, n * m + 10){ 
			fr(i, n)
			fr(j, m)
			fr(l, 4){
				int x, y, aux;
				x = i + mx[l];
				y = j + my[l];
				if (valid(x, y)){
					aux = memo[mask][crd(i, j)] + cst[crd(x, y)];
					if (memo[mask][crd(x, y)] > aux){
						memo[mask][crd(x, y)] = aux;
						nxt[mask][crd(x, y)] = {crd(i, j)};
					}
				}
			}
		}
	}		

	int v = 0, mn = INF;
	fr(u, n * m)
		if (memo[(1<<k) - 1][u] < mn){
			v = u;
			mn = memo[(1<<k) - 1][u];
		}

	cout<<mn<<endl;
	pans((1<<k) - 1, v);
	
	fr(i, n){
		fr(j, m)
			cout<<ans[i][j];
		gnl;	
	}
}