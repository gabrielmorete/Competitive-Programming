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

typedef vector< vector<ll> > matrix;

matrix operator*(matrix const &a, matrix const &b){
	matrix c(a.size(), vector<ll>(b[0].size(), INF));
	for (int i = 0; i < a.size(); i++)
		for (int k = 0; k < b.size(); k++)
			for (int j = 0; j < b[0].size(); j++)
				c[i][j] = min(c[i][j], max(a[i][k], b[k][j]));
	return c;
}

matrix fastxp(matrix base, ll exp){
	if (exp == 1)
		return base;

	matrix ans = fastxp(base, exp/2);
	ans = ans * ans;

	if (exp&1)
		ans = ans * base;

	return ans;
}

int n, t, l;

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin>>n>>t>>l;

	matrix A(n, vector<ll>(n, INF));

	frr(i, t){
		int x, y;
		cin>>x>>y;

		A[y - 1][x - 1] = i;
	}

	A = fastxp(A, l);

	matrix B(n, vector<ll>(1, INF));
	B[0][0] = 0;

	matrix X = A * B;

	fr(i, n)
		if (X[i][0] <= t)
			cout<<X[i][0]<<' ';
		else
			cout<<-1<<' ';
	gnl;
}