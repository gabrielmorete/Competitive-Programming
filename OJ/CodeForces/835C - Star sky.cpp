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

int n, q, c;
int m[11][110][110];

int main(){
	fastio;
	cin>>n>>q>>c;
	c++;

	int a, b, s;
	fr(i, n){
		cin>>a>>b>>s;
		m[s][a][b]++;
	}

	fr(p, c){
		frr(i, 100)
			frr(j, 100)
				m[p][i][j] += m[p][i - 1][j] + m[p][i][j - 1] - m[p][i - 1][j - 1];		
	}

	int ans, bgt, amn;
	int d, e, t;
	while (q--){
		cin>>t>>a>>b>>d>>e;
		ans = 0;
		fr(p, c){
			bgt = (p + t)%c;
			amn = (m[p][d][e] + m[p][a - 1][b - 1] - m[p][a - 1][e] - m[p][d][b - 1]);
			ans += bgt * amn;
		}
		cout<<ans<<endl;	
	}
}