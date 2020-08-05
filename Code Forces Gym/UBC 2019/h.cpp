#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i,n)     for(ll i=0;i<n;i++)
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

vector<ll> p;
ll primo[2100010];

void crivo(){
	for(ll i = 2; i < 2100010; i++){
		if(primo[i] == 0){
			p.pb(i);

			for(ll j = 2; j*i < 2100010; j++){
				primo[j*i] = 1;
			}
		}
	}
}

int main(){
	fastio;

	ll c;
	cin >> c;

	crivo();

	ll ans = 1;

	fr(i, p.size()){
		int exp = 0;

		while(c%p[i] == 0){
			exp++;
			c/=p[i];
		}

		if(exp%2 == 1){
			ans*=p[i];
		}
	}

	ll s = sqrt(c);
	if(s*s != c && (s-1)*(s-1) != c && (s+1)*(s+1) != c) ans*=c;

	cout << ans << endl;
}