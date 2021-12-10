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

vector<int> lp(2000000);
vector<int> pr;

void crivo(){
	for (int i=2; i <= 2000000; ++i) {
	    if (lp[i] == 0) {
	        lp[i] = i;
	        pr.push_back(i);
	    }
	    for (int j=0; j < (int)pr.size() && pr[j] <= lp[i] && i*pr[j] <= 2000000; ++j) {
	        lp[i * pr[j]] = pr[j];
	    }
	}
}

int n, e, a[MAXN], resto[MAXN], rgt[MAXN], lft[MAXN];

void solve(){
	cin>>n>>e;

	frr(i, n)
		cin>>a[i];

	fr(i, e) resto[i] = 0;
	
	frr(i, n){
		lft[i] = resto[i%e];
		if (a[i] == 1)
			resto[i % e]++;	
		else
			resto[i%e] = 0;
	}

	fr(i, e) resto[i] = 0;
	
	for (int i = n; i > 0; i--){
		rgt[i] = resto[i%e];
		if (a[i] == 1)
			resto[i % e]++;	
		else
			resto[i%e] = 0;
	}

	ll ans = 0;

	for (int i = 1; i <= n; i++){
		if (lp[a[i]] != a[i])
			continue;

		ll l = lft[i];
		ll r = rgt[i];

		ans += l * (1 + r);
		ans += r;
	}

	cout<<ans<<endl;
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	crivo();

	int T;
	cin>>T;
	while (T--)
		solve();
}