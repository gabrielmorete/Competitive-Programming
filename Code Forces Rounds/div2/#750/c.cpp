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
	string s;
	cin>>n>>s;

	int ans = n + 1000;

	for (char a = 'a'; a <= 'z'; a++){
		bool ok = 1;
		int now = 0;
		int l = 0, r = n - 1;

		while (l < r){
			if (s[l] == s[r]){
				l++;
				r--;
				continue;
			}

			now++;
			if (s[l] == a){
				l++;
				continue;
			}

			if (s[r] == a){
				r--;
				continue;
			}

			ok = 0;
			break;
		} 

		if (ok)
			ans = min(ans, now);
	}

	if (ans > n)
		cout<<-1<<endl;
	else
		cout<<ans<<endl;
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;
	while (T--)
		solve();
}