#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fst first
#define snd second

#define fr(i,n)     for (int i = 0; i < n; i++)
#define frr(i,n)    for (int i = 1; i <= n; i++)

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
const ll mod=1e9+7;

void solve(){
	ll a, b, q, l, r, mdc;
	cin>>a>>b>>q;

	mdc = (a * b)/__gcd(a, b);
	if (a > b)
		swap(a, b);

	ll aux, ans1, ans2;
	while (q--){
		cin>>l>>r;

		if (b % a == 0){
			cout<<0<<' ';
			continue;
		}

		if (r < b){
			cout<<0<<' ';
			continue;
		}

		l = l - 1;

		ans1 = l;
		ans2 = r;

		ans1 -= min(b - 1, l);
		ans2 -= min(b - 1, r);

		aux = l/mdc;
		if (aux > 0){ // corner
			ans1 -= min(l - aux * mdc + 1, b);
			aux--;
		} 
		ans1 -= aux * b;

		aux = r/mdc;
		if (aux > 0){ // corner
			ans2 -= min(r - aux * mdc + 1, b);
			aux--;
		} 
		ans2 -= aux * b;

		cout << ans2 - ans1 << ' ';
	}

	gnl;
}

int32_t main(){
	fastio;
	int T;
	cin>>T;
	while (T--)
		solve();
}