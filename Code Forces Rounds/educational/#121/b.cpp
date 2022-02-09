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

void solve(){
	string s;

	cin>>s;

	int x = (int)(s[0] - '0') + (int)(s[1] - '0');
	string t = to_string(x);

	int sz = s.size() + t.size();
	sz--;

	int n = s.size();
	int lst = 0;

	for (int i = 1; i < n - 1; i++){
		int x = (int)(s[i] - '0') + (int)(s[i + 1] - '0');
		string aux = to_string(x);

		if (aux.size() + s.size() == n + 1)
			continue;
		else{
			lst = i;
		}
	}

	x = (int)(s[lst] - '0') + (int)(s[lst + 1] - '0');
	string aux = to_string(x);

	string ans = s.substr(0, lst) + aux + s.substr(lst + 2);

	cout<<ans<<endl;
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;

	while (T--)
		solve();
}