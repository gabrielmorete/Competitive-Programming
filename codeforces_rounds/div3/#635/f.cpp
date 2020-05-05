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
const int LMAXN = 23;

int n, m, nm, memo[1123456][LMAXN], ans[1123456];
bool color[1123456];

int crd(int x, int y){
	return x*m + y;
}

void solve(){
	cin>>n>>m;
	nm = n*m;

	string s;
	fr(i, n){
		cin>>s;
		fr(j, m)
			color[crd(i, j)] = s[j] - '0';
	}

	fr(i, n){
		cin>>s;
		fr(j, m){
			if (s[j] == 'U'){
				memo[crd(i,j)][0] = crd(i - 1, j);
			} else if (s[j] == 'D'){
				memo[crd(i,j)][0] = crd(i + 1, j);
			} else if (s[j] == 'L'){
				memo[crd(i,j)][0] = crd(i, j - 1);
			} else {
				memo[crd(i,j)][0] = crd(i, j + 1);
			}
		}
	}

	frr(i, LMAXN - 1)
		fr(j, nm)
			memo[j][i] = memo[ memo[j][i - 1] ][i - 1];
			
	int tot, black;
	tot = black = 0;		
	fr(i, nm)
		ans[i] = 0;

	int to;			
	fr(i, nm){
		to = memo[i][LMAXN - 1];
		if (ans[to] == 2)
			continue;

		if (color[i] == 0){
			if (ans[to] == 0)
				tot++;
			black++;
			ans[to] = 2;
		}
		else if (ans[to] == 0){
			ans[to] = 1;
			tot++;
		}
	}
	cout<<tot<<' '<<black<<endl;			
}

int main(){
	fastio;
	int t;
	cin>>t;
	while (t--)
		solve();
}