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
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
//cout << setprecision(9)<<fixed;

#define dbg(x)  cout << #x << " = " << x << endl
#define all(x)  x.begin(),x.end()

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

const int INF = 0x3f3f3f3f;
const ll llINF = (long long)(1e18) + 100;   
const int MAXN = 1e5 + 10;

void solve(){
	int n, m, x, y;

	cin>>n>>m>>x>>y;

	int ans = 0;
	y = min(y, 2 * x);

	string s;
	while (n--){
		cin>>s;
		for (int i = 0; i < m; i++){
			if (i < m - 1 and s[i] == '.' and s[i + 1] == '.'){
				s[i + 1] = '*';
				ans += y;
			}
			else if (s[i] == '.'){
				ans += x;				
			}
		}
	}
	cout<<ans<<endl;
}

int32_t main(){
	fastio;
	int T;
	cin>>T;
	while (T--)
		solve();
}