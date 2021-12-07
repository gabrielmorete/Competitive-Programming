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

int n, freq[500];
string s;

int test(char a, char b){
	int ans = 0;
	bool side = 0;

	for (auto x : s){
		if (x == a and !side){
			side = 1;
			ans++;
		}
		else if (x == b and side){
			side = 0;
			ans++;
		}
	}

	if (side == 1)
		ans--;

	return ans;
}

void solve(){
	cin>>s;
	n = s.size();

	for (char a = '0'; a <= '9'; a++)
		freq[a] = 0;

	int ans = 0;

	for (auto x : s){
		freq[x]++;
		ans = max(ans, freq[x]);
	}

	for (char a = '0'; a <= '9'; a++)
		for (char b = '0'; b <= '9'; b++)
			ans = max(ans, test(a, b));

	cout<<(n - ans)<<endl;
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;
	while (T--)
		solve();
}