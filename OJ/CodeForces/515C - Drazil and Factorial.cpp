#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fst first
#define snd second

#define fr(i,n)     for (int i = 0; i < n; i++)
#define frr(i,n)    for (int i = 1; i <= n; i++)

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
const ll mod = 1e9+7;

int32_t main(){
	fastio;

	int n;
	string s;

	cin>>n;
	cin>>s;

	vi ans;

	fr(i, n){
		int aux = s[i] - '0';

		if (aux > 1){
			if (aux <= 3 or aux == 5 or aux == 7){
				ans.pb(aux);
			}
			if (aux == 4){
				ans.pb(3);
				ans.pb(2);
				ans.pb(2);
			}
			if (aux == 6){
				ans.pb(5);
				ans.pb(3);
			}
			if (aux == 8){
				ans.pb(7);
				ans.pb(2);
				ans.pb(2);
				ans.pb(2);
			}
			if (aux == 9){
				ans.pb(7);
				ans.pb(3);
				ans.pb(3);
				ans.pb(2);
			}
		}
	}

	sort(all(ans));
	reverse(all(ans));

	for (auto x : ans)
		cout<<x;
	gnl;

}