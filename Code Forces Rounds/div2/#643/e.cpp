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
const int MAXN = 1e5 + 10;

ll n, v[MAXN], ca, cb, cm;

ll cost(ll a, ll b){
	ll m = 0;
	if (ca + cb > cm)
		m = min(a, b);
	return (a - m) * ca + (b - m) * cb + m * cm;
}

ll test(ll hgt){
	ll a, b;
	a = b = 0;
	fr(i, n){
		if (v[i] < hgt)
			a += hgt - v[i];
		if (v[i] > hgt)
			b += v[i] - hgt;
	}
	return cost(a, b);
}

int32_t main(){
	fastio;
	cin>>n>>ca>>cb>>cm;

	ll mn, mx;
	mn = llINF;
	mx = 0;

	fr(i, n){
		cin>>v[i];
		mx = max(v[i], mx);
		mn = min(v[i], mn);
	}

	ll ans = llINF, l, r, vl, vr;

	while (mx - mn > 3){
		l = mn + (mx - mn)/3;
		r = mx - (mx - mn)/3;

		vl = test(l);
		vr = test(r);

		if (vl > vr)
			mn = l + 1;
		else if (vl < vr)
			mx = r - 1;
		else{
			mn = l;
			mx = r;
		}
	}

	for (ll x = mn; x <= mx; x++)
		ans = min(ans, test(x));

	cout<<ans<<endl;
}