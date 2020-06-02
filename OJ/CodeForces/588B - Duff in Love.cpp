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
const int MAXN = 2e6 + 10;
const ll mod = 1e9+7;

bool check[MAXN];
vector<ll> fac;

void factor(ll n){
	for (ll i = 2; i * i <= n; i++){
		if (!check[i]){
			for (ll j = i; j * j <= n; j += i)
				check[j] = 1;
			if (n % i == 0)
				fac.pb(i);
			while (n % i == 0)
				n /= i;
		}
	}

	fac.pb(n);
}

int32_t main(){
	fastio;

	ll n;
	cin>>n;

	factor(n);

	ll ans = 1;
	for (auto x : fac)
		ans *= x;

	cout<<ans<<endl;
}