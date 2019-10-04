#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i,n)     for(int i=0;i<n;i++)
#define frr(i,n)    for(int i=1;i<=n;i++)

#define ms(x,i) memset(x,i,sizeof(x))
#define dbg(x)  cout << #x << " = " << x << endl
#define all(x)  x.begin(),x.end()

#define gnl cout << endl
#define chapa cout << "oi meu chapa" << endl
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
//cout << setprecision(9)<<fixed;

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = (long long)(1e18) + 100;   
const int MAXN = 100100;
const int MAXM = 1001000;
const ll mod=1e9+7;
const int LMAXN = 25;

int n1, n2, cnt;
int v1[111], v2[111];
int memo[111][111];
int pd() {
	for (int i = 0; i <= max(n1,n2); i++)
		memo[0][i] = 0, memo[i][0] = 0;

	for (int i = 1; i <= n1; i++) {
		for (int j = 1; j <= n2; j++) {
			
			if (v1[i] == v2[j]) 
				memo[i][j] = memo[i-1][j-1] + 1;
			else 
				memo[i][j] = max(memo[i][j-1],memo[i-1][j]);
			
		}
	}

	return memo[n1][n2];
}

int main(){
	fastio;

	cin>>n1>>n2;
	while (n1 != 0) {
		for (int i = 1; i <= n1; i++)
			cin>>v1[i];
		for (int i = 1; i <= n2; i++)
			cin>>v2[i];

		cout<<"Twin Towers #"<<++cnt<<endl;
		cout<<"Number of Tiles : "<<pd()<<endl<<endl;

		cin>>n1>>n2;
	}

}