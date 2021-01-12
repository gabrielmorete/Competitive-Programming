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
const int MAXN = 1e5 + 10;

int n, k, m, b[22], p[22][22], q[22][22];
int base[1<<20][22];
double memo[1<<20][22][2];

double pd(){
	
	for (int mask = 0; mask < (1 << (n - 1)); mask++){
		for (int lft = k; lft >= 0; lft--){
			if (base[mask][n - 1] >= 0)
				memo[mask][lft][1] = 1;
			else if (base[mask][n - 1] <= -m)
				memo[mask][lft][1] = 0;
			else{
				double prb = ((double) abs(base[mask][n - 1])) / m; // prob de ser negativo
				memo[mask][lft][1] = 1.0 - prb;
				if (lft > 0)
					memo[mask][lft][1] = 1.0 - (prb * prb);
			}
		}
	}

	for (int pos = n - 2; pos >= 0; pos--){
		for (int mask = 0; mask < (1 << pos); mask++){
			for (int lft = k; lft >=0; lft--){
				double prb; // prob de ser negativo
				double &pdm = memo[mask][lft][0];
				int val = base[mask][pos];

				if (val >= 0) prb = 1;
				else if (val <= -m) prb = 0;
				else prb = 1 + (((double) val) / m);

				pdm = prb * memo[mask|(1 << pos)][lft][1] + (1 - prb) * memo[mask][lft][1];

				if (lft > 0){
					if (val >= 0) prb = 1;
					else if (val <= -m) prb = 0;
					else prb = 1 - (((double) val) / m) * (((double) val) / m);

					double aux = prb * memo[mask|(1 << pos)][lft - 1][1]+ (1.0 - prb) * memo[mask][lft - 1][1];

					pdm = max(pdm, aux);

					if (val >= 0) prb = 1;
					else if (val <= -m) prb = 0;
					else prb = (1 + (((double)val) / m)) * (1 + (((double) val) / m));

					aux = prb * memo[mask|(1 << pos)][lft - 1][1] + (1 - prb) * memo[mask][lft - 1][1];

					pdm = max(pdm, aux);
				}
			}
		}

		for (int mask = 0; mask < (1 << pos); mask++)
			for (int lft = k; lft >= 0; lft--)
				memo[mask][lft][1] = memo[mask][lft][0];
	}

	return memo[0][k][0];
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin>>n>>k>>m;

	fr(i, n){
		cin>>b[i];
		for (int j = i + 1; j < n; j++)
			cin>>p[i][j];
		for (int j = i + 1; j < n; j++)
			cin>>q[i][j];	
	}

	for (int mask = 0; mask < (1 << n); mask++){
		for (int i = 0; i < n; i++){
			base[mask][i] = b[i];
			for (int j = 0; j < i; j++)
				if (mask & (1<<j))
					base[mask][i] += p[j][i];
				else
					base[mask][i] += q[j][i];
		}
	}

	cout<<setprecision(6)<<fixed;			
	cout<<pd()<<endl;			
}	
