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

ll n, k;
map<int, int> frq;
ll val[212345], freq[212345];
ll aval[212345], afreq[212345];


int main(){
	fastio;
	cin>>n>>k;

	int x;
	fr(i, n){
		cin>>x;
		frq[x]++;
	}

	int cnt = 1;
	for (auto a : frq){
		val[cnt] = a.fst;
		freq[cnt] = a.snd;
		aval[cnt] = val[cnt]*freq[cnt] + aval[cnt - 1];
		afreq[cnt] = freq[cnt] + afreq[cnt - 1];
		cnt++;
	}

	n = cnt - 1;

	ll up, down, cup, cdown, ans = llINF, delta;
	frr(i, n){ // fixing val[i]
		delta = max( 0ll, k - freq[i]); // # of elements to move
		if (delta == 0){
			ans = 0;
			continue;
		}
		
		up = min(delta, afreq[i - 1]);

		if (up > 0){
			cup = (val[i] - 1ll)*afreq[i - 1] - aval[i - 1] + up;
			down = min(delta - up, afreq[n] - afreq[i]);
			
			cdown = 0;
			if (down > 0)
				cdown = aval[n] - aval[i] - (val[i] + 1ll)*(afreq[n] - afreq[i]) + down;
			ans = min(ans, cup + cdown);
		}

		down = min(delta, afreq[n] - afreq[i]);

		if (down > 0){
			cdown = aval[n] - aval[i] - (val[i] + 1ll)*(afreq[n] - afreq[i]) + down;
			up = min(delta - down, afreq[i - 1]);
			cup = 0;
			if (up > 0)	
				cup = (val[i] - 1ll)*afreq[i - 1] - aval[i - 1] + up;
			ans = min(ans, cup + cdown);
		}
	}

	cout<<ans<<endl;
}