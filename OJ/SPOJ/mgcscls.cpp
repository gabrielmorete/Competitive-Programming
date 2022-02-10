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
const int MAXN = 4e5 + 10;

int n, m, l, p, val[55][55], memo[55][MAXN];

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin>>n>>l>>p;

	fr(i, l)
		fr(j, n)
			cin>>val[i][j];

	fr(i, p)
		fr(j, n){
			cin>>val[l + i][j];
			val[l + i][j] *= -1;
		}
		
	m = l + p;


	int sft = 125001;		
	int maxv = 2*sft + 10;

	fr(k, maxv)
		memo[0][k] = INF;

	memo[0][sft] = n; // tira tudo da coluna 0;	

	int sum = 0;
	fr(j, n){
		sum += val[0][j];
		memo[0][sum + sft] = min(memo[0][sum + sft], n - 1 - j);
	}

	for (int i = 1; i < m; i++){
		fr(k, maxv)
			memo[i][k] = INF;

		int sum = 0;
		for (int j = 0; j <= n; j++){
			int cst = n - j;

			for (int k = 0; k < maxv; k++)
				if (k - sum >= 0)
					memo[i][k] = min(memo[i][k], memo[i - 1][k - sum] + cst);

			if (j < n)
				sum += val[i][j];
		}	
	}		

	cout<<memo[m - 1][sft]<<endl;
}