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
const int MAXN = 2e5 + 10;

int n, q, a[MAXN];
ll tam[MAXN];
set<int> itv;

ll seg[4 * MAXN];

ll comb(ll x){ return ((x) * (x + 1))/2;}


void update(int node, int l, int r, int p, ll v){
	if (p < l or r < p)
		return;

	if (l == r){
		seg[node] = v;
		return;
	}

	int m = (l + r)/2;

	update(node<<1, l, m, p, v);
	update(node<<1|1, m + 1, r, p, v);
	seg[node] = seg[node<<1] + seg[node<<1|1];
}

ll query(int node, int l, int r, int ql, int qr){
	if (qr < l or r < ql)
		return 0;
	if (ql <= l and r <= qr)
		return seg[node];

	int m = (l + r)/2;
	return query(node<<1, l, m, ql, qr) + query(node<<1|1, m + 1, r, ql, qr);
}

void apaga(int p){
	if (p < 1) 
		return;
	itv.erase(p);
	tam[p] = 0;
	update(1, 1, n, p, 0);
}

void bota(int p, ll v){
	itv.insert(p);
	tam[p] = v;
	update(1, 1, n, p, comb(v));
}


void update(int p, int v){
	auto it = itv.lower_bound(p);
	
	int r = *it;
	int l = r - tam[r];

	apaga(r);

	if (l != p - 1 and p > 1)
		bota(p - 1, p - l - 1);
	if (r != p)
		bota(r, r - p);

	a[p] = v;

	if (a[p - 1] <= a[p] and a[p] <= a[p + 1]){
		auto itt = itv.lower_bound(p);
		r = *itt;
		tam[r] += tam[p - 1] + 1;
		update(1, 1, n, r, comb(tam[r]));
		apaga(p - 1);
	}
	else if (a[p - 1] <= a[p]){
		bota(p, tam[p - 1] + 1);
		apaga(p - 1);
	}
	else if (a[p] <= a[p + 1]){
		auto itt = itv.lower_bound(p);
		tam[*itt]++;
		update(1, 1, n, *itt, comb(tam[*itt]));
	}
	else{
		bota(p, 1);
	}
}

ll query(ll ql, ll qr){
	ll l = *itv.lower_bound(ql);
	ll r = *itv.lower_bound(qr);
	
	if (l == r)
		return comb(qr - ql + 1);


	l++;
	r -= tam[r];
	
	ll ans = 0;

	if (l <= r)
		ans = query(1, 1, n, l, r);

	l = *itv.lower_bound(ql);
	r = *itv.lower_bound(qr);
	r -= tam[r] - 1;

	ans += comb(l - ql + 1);
	ans += comb(qr - r + 1);

	return ans;
}


signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin>>n>>q;

	frr(i, n)
		cin>>a[i];

	int p = 1;
	while (p <= n){
		int q = p;
		while (q < n and a[q + 1] >= a[q])
			q++;

		bota(q, q - p + 1);
	
		p = q + 1;
	}	

	int t, l, r;

	while (q--){
		cin>>t>>l>>r;
		if (t == 1)
			update(l, r);
		else
			cout<<query(l, r)<<endl;
	}
}