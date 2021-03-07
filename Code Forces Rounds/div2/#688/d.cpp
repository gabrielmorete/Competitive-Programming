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

int ans[2020];

void solve(){
	ll k;

	fr(i, 2000)
		ans[i] = 0;

	cin>>k;

	if (k % 2){
		cout<<-1<<endl;
		return;
	}


	ll pos;
	pos = 1;

	ans[0] = 1;

	while (k){
		ll x = 1;

		while ((1ll<<(x + 1ll)) - 2ll <= k)
			x++;
	
		pos += x - 1;
		k -= (1ll<<x) - 2ll;

		ans[pos - 1] = 1; 
	}

	cout<<pos - 1<<endl;

	fr(i, pos - 1)
		cout<<ans[i]<<' ';
	gnl;	
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;
	while (T--)
		solve();
}