#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i,n)     for(int i=0;i<n;i++)
#define frr(i,n)    for(int i=1;i<=n;i++)

#define ms(x,i) memset(x,i,sizeof(x))
#define dbg(x)  cout << #x << " = " << x << endl
#define all(x)  x.begin(),x.end()

#define gnl cout << endl
#define chapa cout << "oi meu chapa" << endl
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
//cout << setprecision(9)<<fixed;

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = (long long)(1e18) + 100;   
const int MAXN = 100100;
const int MAXM = 1001000;
const ll mod=1e9+7;
const int LMAXN = 25;

ll a, b, q, mdc;

vll divi;
void find_divi(ll n){
	for (ll i = 1; i*i <= n; i++){
		if (n%i == 0){
			divi.pb(i);
			if (i != n/i) 
				divi.pb(n/i);
		}
	}
}

ll gcd (ll a, ll b) {
    return b ? gcd (b, a % b) : a;
}

int main(){
	fastio;
	cin>>a>>b;
	mdc = __gcd(a, b);
	find_divi(mdc);


	sort(all(divi));

	cin>>q;

	while (q--){
		cin>>a>>b;
		if (a > mdc){
			cout<<-1<<endl;
			continue;
		}

		// auto it = lower_bound(all(divi), b);
		// int p = (int) (it - divi.begin());

		// if (p == divi.size());
		// 	p--;

		// if (divi[p] > b)
		// 	p--;

		// if (p < 0){
		// 	cout<<-1<<endl;
		// 	continue;
		// }

		// if (divi[p] < a){
		// 	cout<<-1<<endl;
		// }
		// else
		// 	cout<<divi[p]<<endl;
		ll aux = -1;
		for (ll x : divi)
			if (a <= x and x <= b)
				aux = x;
		cout<<aux<<endl;			
	
	}

}