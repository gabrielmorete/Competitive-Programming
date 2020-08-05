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
const ll mod = 998244353;
const int LMAXN = 25;

string s, t;
ll freq[212345];

ll fastxp(ll base, ll exp){
	if (exp == 0)
		return 1ll;
	ll aux = fastxp(base, exp/2ll);
	aux = (aux*aux)%mod;
	if (exp%2ll)
		aux = (aux*base)%mod;
	return aux;
}

int main(){
	fastio;
	int n, m;
	cin>>n>>m;
	cin>>s>>t;

	ll ac = 0;

	reverse(all(s));
	reverse(all(t));

	for (int i = m - 1; i >= 0; i--){
		if (t[i] == '1')
			ac++;
		freq[i] = ac;
	}


	ll ans = 0;

	for (int i = n - 1; i >= 0; i--){
		if (s[i] == '1' and freq[i] > 0){
			ll aux = fastxp(2, i);
			aux = (aux*freq[i])%mod;
			ans =  (ans + aux)%mod;
		}
	}
	cout<<ans<<endl;
}