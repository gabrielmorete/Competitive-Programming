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

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m, mat[55][55];

	cin>>n>>m;
	fr(i, n)
		fr(j, m)
			cin>>mat[i][j];

	bool ok = 1;		

	for (int a = 0; a < n; a++)
		for (int b = a + 1; b < n; b++)
			for (int c = 0; c < m; c++)
				for (int d = c + 1; d < m; d++)
					if (mat[a][c] + mat[b][d] > mat[a][d] + mat[b][c])
						ok = 0;

	cout<<(ok?"Yes":"No")<<endl;
}