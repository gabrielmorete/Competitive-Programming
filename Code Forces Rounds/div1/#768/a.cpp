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

int n, k, used[MAXN];
vii ans;

void solve(){
	ans.clear();

	cin>>n>>k;

	if (k == n - 1 and n == 4){
		cout<<-1<<endl;
		return;
	}

	if (k == n - 1){
		ans.pb({n - 1, n - 2});
		ans.pb({n - 3, 1});
		ans.pb({0, 2});


		for (int i = n - 4; i >= n/2; i--){
			int p = n - i - 1;
			ans.pb({i, p});
		}

		int val = 0;

		for (auto x : ans){
			cout<<x.fst<<' '<<x.snd<<endl;;
			val += x.fst & x.snd;
		}
		assert(val == k);

		return;
	}	



	fr(i, n){
		used[i] = 0;
	}

	// chapa;
	// dbg(k);
	ans.pb({k, n - 1});
	used[k] = 1; used[n - 1] = 1;

	for (int i = n - 2; i >= 0; i--){
		int p = n - i - 1;

		if (!used[i] and !used[p]){
			ans.pb({i, p});
			used[i] = used[p] = 1;
			continue;
		}

		if (used[i] and !used[p]){
			used[p] = 1;
			used[0] = 1;
			ans.pb({0, p});
			continue;
		}

		if (used[p] and !used[i]){
			used[i] = 1;
			used[0] = 1;
			ans.pb({i, 0});
			continue;
		}
	}

	int val = 0;

	for (auto x : ans){
		cout<<x.fst<<' '<<x.snd<<endl;;
		val += x.fst & x.snd;
	}
	assert(val == k);

	// chapa;
	// dbg(val);
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;

	while (T--)
		solve();
}