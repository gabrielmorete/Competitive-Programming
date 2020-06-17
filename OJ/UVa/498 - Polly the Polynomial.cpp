#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fst first
#define snd second

#define fr(i,n)     for (int i = 0; i < n; i++)
#define frr(i,n)    for (int i = 1; i <= n; i++)

//#define endl '\n'
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

vector<ll> v, x;

int32_t main(){
	fastio;

	string s, t;
	while (getline(cin, s)){
		v.clear();
		x.clear();

		stringstream ss(s);

		ll val;
		while (ss >> val){
			v.pb(val);
		}

		reverse(all(v));

		getline(cin, s);
		
		ss = (stringstream) s;
		while (ss >> val)
			x.pb(val);

		bool ok = 1;
		ll ans, deg;
		for (ll a : x){
			ans = 0, deg = 1;
			for (ll b : v){
				ans += deg * b;
				deg *= a;
			}
			if (ok == 0)
				cout<<' ';
			ok = 0;

			cout<<ans;
		}
		gnl;
	}
}