#include "bits/stdc++.h"
using namespace std;

#define pb push_back
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
typedef vector<pii> vii;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = (long long)(1e18) + 100;   
const int MAXN = 1e5 + 10;
const ll mod=1e9+7;

void solve(){
	ll n, k, d1, d2;
	cin>>n>>k>>d1>>d2;

	if (n % 3){
		cout<<"no"<<endl;
		return;
	}

	n /= 3; 

	ll a, b, c;

	// Caso a >= b >= c
	b = k - d1 + d2;
	if (b % 3 == 0 and b >= 0){
		b /= 3;
		a = d1 + b;
		c = b - d2;
		if (a >= b and b >= c and c >= 0){ // correct case
			if (a <= n){
				cout<<"yes"<<endl;
				return;
			}
		}
	}

	// Caso b >= a , b >= c
	b = k + d1 + d2;  // a + b + c + b - a + b - c = 3b
	if (b % 3 == 0){
		b /= 3; 
		a = b - d1;
		c = b - d2;
		if (b >= a and b >= c and a >= 0 and c >= 0){
			if (b <= n){
				cout<<"yes"<<endl;
				return;
			}
		}
	}

	// Caso a >= b c >= b
	a = k + 2*d1 - d2; // a + b + c + 2a - 2b + b - c = 2a
	if (a % 3 == 0 and a >= 0){
		a /= 3;
		b = a - d1;
		c = d2 + b;
		if (a >= b and c >= b and b >= 0){
			if (a <= n and c <= n){
				cout<<"yes"<<endl;
				return;
			}
		}
	}

	// Caso c >= b >= a
	b = k + d1 - d2; // a + b + c + b - a + b - c
	if (b % 3 == 0 and b >= 0){
		b /= 3;
		a = b - d1;
		c = d2 + b;
		if (c >= b and b >= a and a >= 0){
			if (c <= n){
				cout<<"yes"<<endl;
				return;
			}
		}
	}

	cout<<"no"<<endl;
}

int32_t main(){
	fastio;
	int T;
	cin>>T;
	while (T--)
		solve();
}