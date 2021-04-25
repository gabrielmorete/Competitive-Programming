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

const double EPS = 1e-8;
int sign(double x) { return (x > EPS) - (x < -EPS); }

int n, r, m, t[55], d[55];
double p[55];

double guess, memo[55][10000];

double pd(){
	for (int j = 0; j < r; j++)
		memo[m][j] = n - t[m - 1];

	for (int i = m - 1; i >= 0; i--){
		double dlt = (i > 0? t[i] - t[i - 1] : t[i]);
		for (int j = 0; j < r; j++){
			if (j + d[i] < r)	
				memo[i][j] = dlt + p[i] * memo[i + 1][j] + (1.0 - p[i]) * min(guess, (double) d[i] + memo[i + 1][j + d[i]]);
			else
				memo[i][j] = dlt + p[i] * memo[i + 1][j] + (1.0 - p[i]) * guess;
		}
	}

	return memo[0][0];
}



int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin>>n>>r>>m;

	r -= n; // atraso maximo

	fr(i, m)
		cin>>t[i]>>p[i]>>d[i];

	
	double ini = 0, fim = INF;
	
	fr(i, 170){
		guess = (ini + fim) / 2.0;

		double aux = pd();

		if (sign(aux - guess) > 0)
			ini = guess;
		else
			fim = guess;
	}	
	
	cout<<setprecision(9)<<fixed;
	cout<<ini<<endl;

}