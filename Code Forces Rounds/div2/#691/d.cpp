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
const int MAXN = 1e4 + 10;

int n, a[MAXN], b[MAXN];

int memo[2][110][MAXN]; //pos, k, capacity

void pd(){
	for (int k = 0; k <= n; k++)
		for (int l = 0; l < MAXN; l++)
			memo[1][k][l] = -INF;
	memo[1][0][0] = 0; // com zero litros e zero capacidade

	for (int pos = 0; pos < n; pos++){
		for (int k = 1; k <= n; k++){
			for (int l = 0; l < MAXN; l++){
				int &pdm = memo[0][k][l];
				pdm = memo[1][k][l]; // não pegar

				if (l - a[pos] >= 0)
					pdm = max(pdm, memo[1][k - 1][l - a[pos]] + b[pos]);
			}
		}
		
		for (int k = 1; k <= n; k++)
			for (int l = 0; l < MAXN; l++)
				memo[1][k][l] = memo[0][k][l];
	}	
}


int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin>>n;

	int sum = 0;
	fr(i, n){
		cin>>a[i]>>b[i]; // capacity and water
		sum += b[i];
	}

	pd();
	
	cout<<setprecision(9)<<fixed;

	for (int k = 1; k <= n; k++){
		double ans = 0;
		int aux, val;
		for (int l = 0; l < MAXN; l++){
			val = memo[0][k][l];
			aux = sum - val;
			// if (val > 0){
			// 	dbg(aux);
			// 	dbg(val);
			// 	dbg(l);
			// }

			ans = max(ans, min<double>(l, (double) val + (double)( ((double) aux)/2.0 )));
		}
		cout<<ans<<' ';
	}	
	gnl;
}