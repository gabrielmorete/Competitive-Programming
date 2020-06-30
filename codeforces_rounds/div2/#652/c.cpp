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

typedef vector<ll> vll;

void solve(){
	int n, k;
	vll v, need;

	cin>>n>>k;

	ll x;
	fr(i, n){
		cin>>x;
		v.pb(x);
	}
	fr(i, k){
		cin>>x;
		need.pb(x);
	}

	sort(all(v));
	sort(all(need));

	ll ans = 0;

	ll val;
	for (int i = 0; i < k; i++){
		val = v.back();
		v.pop_back();
		n--;

		need[i]--;
		ans += val;
		if (need[i] == 0)
			ans += val;
	}

	reverse(all(need));
	
	int p = 0;
	for (int i = 0; i < k; i++){
		if (need[i] == 0)
			continue;
		ans += v[p];
		p += need[i];
	}

	cout<<ans<<endl;

}

int32_t main(){
	fastio;
	int T;
	cin>>T;
	while (T--)
		solve();
}