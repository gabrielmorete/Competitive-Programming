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

#define dbg(x)  cout << #x << " = " << x << endl
#define all(x)  x.begin(), x.end()

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

const int INF = 0x3f3f3f3f;
const ll llINF = (long long)(1e18) + 100;   
const int MAXN = 4e5 + 10;

ll ans[MAXN], n, q, a[MAXN];

bool test(ll val, ll l, ll r, ll d){
	ll cst = 0;
	for (ll i = l; i <= r; i++)
		if (a[i] <= val)
			cst += a[i];

	return cst <= d;
}


signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin>>n>>q;

	frr(i, n)
		cin>>a[i];

	ans[0] = 0;
	frr(i, q){
		ll x, y, z;
		cin>>x>>y>>z;


		ll l = 1 + (x + ans[i - 1] - 1) % n; 
		ll r = 1 + (y + ans[i - 1] - 1) % n;
		ll d = z + ans[i - 1];

		ll ini = 0, fim = 1e9 + 1, bst = 0;

		while (ini <= fim){
			ll mid = (ini + fim)/2;
			if (test(mid, l, r, d)){
				bst = mid;
				ini = mid + 1;
			}
			else
				fim = mid - 1;
		}
	
		for (ll j = l; j <= r; j++)
			if (a[j] <= bst)
				ans[i] += a[j];
	}	

	frr(i, q)
		cout<<ans[i]<<endl;
}