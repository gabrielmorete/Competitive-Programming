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
const int MAXN = 4e5 + 10;

ll n, x;
vector<ll> v, ad, av;

int32_t main(){
	fastio;
	cin>>n>>x;

	ll a;
	fr(i, n){
		cin>>a;
		v.pb(a);
	}

	fr(i, n)
		v.pb(v[i]);

	v.pb(0);	

	reverse(all(v));

	av.pb(0);
	ad.pb(0);

	frr(i, 2 * n){
		ad.pb(ad[i - 1] + v[i]);
		av.pb(av[i - 1] + (v[i] * (v[i] + 1ll))/2);
	}

	ll ans = 0;
	
	ll p, aux, aux2;
	for (int i = 1; i <= n; i++){
		p = upper_bound(all(ad), ad[i - 1] + x) - ad.begin(); // cara que eu acabo

		aux = av[p] - av[i - 1]; // tudo desses caras

		aux2 = ad[i - 1] + x - ad[p - 1];
		aux2 = v[p] - aux2;
		aux -= (aux2 * (aux2 + 1ll))/2;
		ans = max(ans, aux);
	}	

	cout<<ans<<endl;



}