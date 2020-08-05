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

ll n, h;

ll rec(ll l, ll r,ll p, ll hgt){
	if (l == r)
		return 0;

	ll meio = (l + r)/2;

	if (n <= meio and p == 0)
		return rec(l, meio, 1, hgt + 1) + 1;

	else if(n <= meio and p == 1)
		return rec(l, meio, 1, hgt + 1) + (1ll<<(h - hgt));

	if (p == 0){
		return rec(meio + 1, r, 0, hgt + 1) + (1ll<<(h - hgt));
	}
	else
		return rec(meio + 1, r, 0, hgt + 1) + 1;
}


int main(){
	fastio;
	cin>>h>>n;

	cout<<rec(1, 1ll<<h, 0, 0) 	<<endl;
}