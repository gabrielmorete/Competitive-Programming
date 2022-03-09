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

bool test(ll a, ll b, ll c, ll d){
	ll t1 = (c + b - 1)/b;
	ll t2 = (a + d - 1)/d;

	return t1 <= t2;
}

void solve(){
	ll hc, dc, hm, dm, k, w, a;
	cin>>hc>>dc>>hm>>dm>>k>>w>>a;

	hc += k * a;

	bool ok = 0;
	k++;
	while (k--){
		ok |= test(hc, dc, hm, dm);
		hc -= a;
		dc += w;
	}

	if (ok)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;
	while (T--)
		solve();
}