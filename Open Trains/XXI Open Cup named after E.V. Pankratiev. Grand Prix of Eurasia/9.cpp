#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fst first
#define snd second

#define fr(i,n)     for (int i = 0; i < n; i++)
#define frr(i,n)    for (int i = 1; i <= n; i++)

// #define endl '\n'
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
const int MAXN = 2e3 + 10;

int n, m, val[MAXN][MAXN], memo[MAXN][MAXN];
vector<string> mapa;

void propagate(int lin){
	int p = 0;
	while (p < m){
		int q = p; 
		int mx = -INF;
		while (q < m and mapa[lin][q] != '@'){
			mx = max(memo[lin][q], mx);
			q++;
		}

		while (p < q){
			memo[lin][p] = mx;
			p++;
		}
	
		p = q + 1; // its the end or it is a @
	}
}

void relax(int lin){
	fr(j, m)
		if (mapa[lin][j] != '@')
			memo[lin + 1][j] = memo[lin][j] + val[lin][j];
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin>>n>>m;

	mapa.resize(n);
	fr(i, n)
		cin>>mapa[i];

	// preprocessing step	
	fr(i, n){
		int p = 0;
		while (p < m){
			int q = p; 
			int pega = 0;
		
			while (q < m and mapa[i][q] != '@'){
				if (mapa[i][q] == 'm')
					pega++;
				q++;
			}

			while (p < q){
				val[i][p] = pega;
				p++;
			}
		
			p = q + 1; // its the end or it is a @
		}
	}


	int slin = 0;

	fr(i, n)
		fr(j, m){
			memo[i][j] = -INF;
			if (mapa[i][j] == 'S'){
				slin = i;
				memo[i][j] = 0;
			}
		}

	for (int i = slin; i < n; i++){
		propagate(i); // propagate the answer in this line	
		relax(i); // relax next line
	}	

	// fr(i, n){
	// 	fr(j, m)
	// 		cout<<max(memo[i][j], -1)<<' ';
	// 		gnl;
	// }

	fr(i, n)
		fr(j, m)
			if (mapa[i][j] == 'E'){
				cout<<max(-1, memo[i][j] + val[i][j])<<endl;
			}
}