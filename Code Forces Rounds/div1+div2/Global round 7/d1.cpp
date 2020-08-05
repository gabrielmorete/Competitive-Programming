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

string s;
int n;

bool test(int p, int q){
	while (p <= q){
		if (s[p] != s[q])
			return false;
		p++;
		q--;
	}
	return true;
}

void solve(){
	cin>>s;

	n = s.size();
	int p, q;

	p = 0;
	q = n - 1;

	while (s[p] == s[q] and p < q){
		p++;
		q--;
	}

	string t;

	t.clear();

	for (int sz = 0; sz < n; sz++){
		if (p + sz <= q and test(p, p + sz)){
			t.clear();
			fr(i, sz + 1)
				t.pb(s[p + i]);
			continue;	
		}
	
		if (q - sz >= p and test(q - sz, q)){
			t.clear();
			fr(i, sz + 1)
				t.pb(s[q - sz + i]);
			continue;
		}
	}

	string ans;
	fr(i, p)
		ans.pb(s[i]);

	ans += t;
	
	for (int i = q + 1; i < n; i++)
		ans.pb(s[i]);	

	cout<<ans<<endl;
}

int32_t main(){
	fastio;
	int T;
	cin>>T;
	while (T--)
		solve();
}