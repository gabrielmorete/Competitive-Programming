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
const ll mod=1e9+9;
const int LMAXN = 25;

ll fastxp(ll base, ll exp){
	if (exp == 1)
		return base;
	ll aux = fastxp(base, exp/2);
	aux = (aux*aux)%mod;
	if (exp%2)
		aux = (aux*base)%mod;
	return aux;
}

int main(){
	fastio;
	ll n, m, k;
	cin>>n>>m>>k;


	ll ed = m - ((n - (n%k))*(k - 1))/k - n%k;

	if (ed <= 0){
		cout<<m<<endl;
		return 0;
	}

	ll ans = (mod + (k*(fastxp(2ll, ed + 1ll) - 2ll)%mod) + m - ed*k)%mod;
	cout<<ans<<endl;
}