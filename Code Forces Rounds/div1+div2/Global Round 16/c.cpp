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

void solve(){
	int n;
	string s[2];

	cin>>n;
	cin>>s[0]>>s[1];

	int ans = 0, p = 0;

	while (p < n){
		if ((int)(s[0][p] - '0') + (int)(s[1][p] - '0') == 1){
			ans += 2;
			p++;
		}
		else{
			if ((int)(s[0][p] - '0') + (int)(s[1][p] - '0') == 0){
				ans += 1;
				p++;
				if (p < n and ((int)(s[0][p] - '0') + (int)(s[1][p] - '0') == 2)){
					ans += 1;
					p++;
				}
			}
			else{
				p++;
				if (p < n and ((int)(s[0][p] - '0') + (int)(s[1][p] - '0') == 0)){
					ans += 2;
					p++;
				}
			}
		}
	}

	cout<<ans<<endl;
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;
	while (T--)
		solve();
}