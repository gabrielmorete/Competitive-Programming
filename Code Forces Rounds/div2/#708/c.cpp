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

vi ans;

void solve3(int n){
	if (n == 3){
		ans.pb(1);
		ans.pb(1);
		ans.pb(1);
		return;
	}
	if (n == 4){
		ans.pb(2);
		ans.pb(1);
		ans.pb(1);
		return;
	}

	if (n % 2){
		int a = (n - 1)/2;
		ans.pb(a);
		ans.pb(a);
		ans.pb(1);
	}
	else{
		int a = (n / 2);
		if (a % 2){
			ans.pb(a - 1);
			ans.pb(a - 1);
			ans.pb(2);
		}
		else{
			ans.pb(a);
			ans.pb(a/2);
			ans.pb(a/2);
		}
	}
}

void solve(){
	ans.clear();
	int n, k;

	cin>>n>>k;

	int aux = k - 3;
	fr(i, aux){
		n--;
		ans.pb(1);
	}

	solve3(n);

	for (auto x : ans)
		cout<<x<<' ';
	gnl;
}


int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;
	while (T--)
		solve();
}