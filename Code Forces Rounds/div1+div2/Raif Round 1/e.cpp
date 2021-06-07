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
const int MAXN = 1e5 + 10;

ll n, k, a[MAXN], d[MAXN];

ll sq(ll x){
	return x * x;
}

ll get_time(ll val, ll dv){ // val <= a[v];
	ll md = val % dv; // numero de pedaços com o teto
	ll teto = (val + dv - 1ll)/dv; // % de pedaços
	ll tme = (dv - md) * sq(val/dv);
	tme = tme + md * sq(teto); 

	return tme;
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin>>n>>k;

	fr(i, n){
		cin>>a[i];
		d[i] = 1;
	}

	priority_queue<pair<ll, ll>> pq;	

	fr(i, n){
		if (a[i] > 1)
			pq.push({sq(a[i]) - get_time(a[i], 2), i});
	}

	ll dlt = k - n;

	ll id;
	while (dlt--){
		tie(ignore, id) = pq.top();
		pq.pop();
		
		d[id]++;
		if (a[id] > d[id]){ // pode dividir mais
			pq.push({ get_time(a[id], d[id]) - get_time(a[id], d[id] + 1), id}); // maximum step
		}
	}

	ll ans = 0;
	fr(i, n)
		ans = ans + get_time(a[i], d[i]);

	cout<<ans<<endl;
}