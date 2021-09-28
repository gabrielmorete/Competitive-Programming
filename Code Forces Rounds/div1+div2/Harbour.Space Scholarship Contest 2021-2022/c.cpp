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

string s;


bool valid(int msk){
	fr(i, 10){
		if (s[i] == '?')
			continue;
		int x = (msk&(1<<i)) != 0;
		if ((int)(s[i] - '0') != x)
			return false;
	}
	return true;
}

int test(int msk){
	int l = 5, r = 5;
	int p = 0, q = 0;

	for (int i = 0; i < 10; i++){
		int x = (msk&(1<<i)) != 0;
		if (i % 2){
			l--;
			p += x;
		}
		else{
			r--;
			q += x;
		}

		if (l + p < q) return i + 1;
		if (r + q < p) return i + 1;
	}

	return 10;
}

void solve(){
	cin>>s;

	int ans = 10;

	for (int msk = 0; msk < (1<<10); msk++){
		if (valid(msk))
			ans = min(ans, test(msk));
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