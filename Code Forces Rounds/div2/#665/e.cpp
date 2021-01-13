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
#define all(x)  x.begin(),x.end()

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

const int INF = 0x3f3f3f3f;
const ll llINF = (long long)(1e18) + 100;   
const int MAXN = 1e6 + 10;

int n, m;
vii he, hr, vd, vu;


int seg[8 * MAXN];

void update(int node, int l, int r, int pos){
	if (r < pos or pos < l)
		return;
	if (l == r){
		seg[node]++;
		return;
	}

	int meio = (l + r)/2;
	update(node<<1, l, meio, pos);
	update(node<<1|1, meio + 1, r, pos);
	seg[node] = seg[node<<1] + seg[node<<1|1];
}

int query(int node, int l, int r, int ql, int qr){
	if (qr < l or r < ql)
		return 0;
	if (ql <= l and r <= qr)
		return seg[node];

	int meio = (l + r)/2;

	return query(node<<1, l, meio, ql, qr) + query(node<<1|1, meio + 1, r, ql, qr);
}


int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin>>n>>m;

	ll ans = 0;

	int a, b, c;
	fr(i, n){
		cin>>a>>b>>c;
		if (b <= 0)
			he.pb({a, c});
		else if (c >= (int)1e6)
			hr.pb({a, b});
		if (b <= 0 and c >= (int)1e6)
			ans++;
	}

	fr(i, m){
		cin>>a>>b>>c;
		if (b <= 0)
			vd.pb({c, a}); /// INVERTIDOO
		else if (c >= (int)1e6)
			vu.pb({b, a}); /// INVERTIDOO
		if (b <= 0 and c >= (int)1e6)
			ans++;
	}


	sort(all(he)); // baixo para cima
	sort(all(hr)); 
	sort(all(vd)); 
	sort(all(vu)); 


	// subindo esquerda

	int p = 0;

	int hgt, wgt;
	for (auto x : vd){
		tie(hgt, wgt) = x;
		while (p < he.size() and he[p].fst <= hgt)
			update(1, 1, 1e6, he[p++].snd);
		ans += query(1, 1, 1e6, wgt, 1e6); // de wgt para frente
	}

	memset(seg, 0, sizeof seg);

	p = 0;
	for (auto x : vd){
		tie(hgt, wgt) = x;
		while (p < hr.size() and hr[p].fst <= hgt)
			update(1, 1, 1e6, hr[p++].snd);
		ans += query(1, 1, 1e6, 0, wgt);
	}

	reverse(all(he)); // cima para baixo
	reverse(all(hr));
	reverse(all(vu));

	memset(seg, 0, sizeof seg);
	p = 0;

	for (auto x : vu){
		tie(hgt, wgt) = x;
		while (p < he.size() and he[p].fst >= hgt)
			update(1, 1, 1e6, he[p++].snd);
		ans += query(1, 1, 1e6, wgt, 1e6);
	}

	memset(seg, 0, sizeof seg);
	p = 0;

	for (auto x : vu){
		tie(hgt, wgt) = x;
		while (p < hr.size() and hr[p].fst >= hgt)
			update(1, 1, 1e6, hr[p++].snd);
		ans += query(1, 1, 1e6, 0, wgt);
	}

	cout<<ans + 1<<endl;
}