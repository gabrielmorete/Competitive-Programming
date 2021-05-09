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

// Otimização de Knuth
// Resolve o problema de dividir um vetor em m pontos
// Complexidade : O(n^2)

// Recorrência : pd(i, j) = min_{i < k < j} {pd(i, k) + pd(k, j)} + c[i][j], O(n^3)
// Podemos otimizar se vale que A[i][j - 1] <= A[i][j] <= A[i + 1][j], em que A[i][j] 
// é o ponto de divisão ótimo (o k da recorrência) para o intervalo v[1...j].
// Outra condição : C[a][c] + C[b][d] <= C[a][d] + C[b][c], a <= b <= c <= d.
//                  C[b][c] <= C[a][d]    

// Problema, descobrir a ordem otima de particinar uma string em m pontos dados 
// tal que o custo de particionar no ponto i é o tamanho do intervalo


int n, m, cuts[MAXN];
int memo[MAXN][MAXN], mid[MAXN][MAXN];

int pd(){
	for (int sz = 0; sz <= m; sz++){ // tamanho do intervalo
		for (int l = 0; l <= m - sz; l++){
			int r = l + sz;
			if (sz < 2){
				memo[l][r] = 0;
				mid[l][r] = l;
				continue;
			}
			int midl = mid[l][r - 1];
			int midr = mid[l + 1][r];
			memo[l][r] = INF;
			mid[l][r] = l;
			for (int k = midl; k <= midr; k++){ // tenta todas as divisões
				int aux = memo[l][k] + memo[k][r] + cuts[r] - cuts[l];
				if (memo[l][r] > aux){
					memo[l][r] = aux;
					mid[l][r] = k;
				}
			}
		}
	}
	return memo[0][m];
}


int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	while (cin>>n>>m){
		frr(i, m)
			cin>>cuts[i];

		cuts[m + 1] = n;
		m++;
		cout<<pd()<<endl;
	}
}