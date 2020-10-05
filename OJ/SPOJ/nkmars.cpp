#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fst first
#define snd second

#define fr(i,n)     for (int i = 0; i < n; i++)
#define frr(i,n)    for (int i = 1; i <= n; i++)

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
const int MAXN = 5e4 + 10;


#define int ll

int top[MAXN], bot[MAXN];

int lazy[4 * MAXN];
pair<ll, ll> seg[4 * MAXN];

pair<ll, ll> combine(pii b, pii c){
	pii ans;
	if (b.fst == c.fst){
		ans = b;
		ans.snd += c.snd;
	}
	else{
		if (b.fst < c.fst)
			ans = b;
		else
			ans = c;
	}
	return ans;
}

void unlazy(int node, int l, int r){
	if (l != r){
		lazy[node<<1] += lazy[node];
		lazy[node<<1|1] += lazy[node];
	}
	seg[node].fst += lazy[node];
	lazy[node] = 0;
}

void build(int node, int l, int r){
	if (l == r){
		seg[node] = {0, 1};
		return;
	}

	int meio = (l + r)/2;

	build(node<<1, l, meio);
	build(node<<1|1, meio + 1, r);
	seg[node] = combine(seg[node<<1], seg[node<<1|1]);
}

void modfy(int node, int l, int r, int ql, int qr, int val){
	unlazy(node, l, r);
	if (r < ql or qr < l)
		return;
	if (ql <= l and r <= qr){
		lazy[node] = val;
		unlazy(node, l, r);
		return;
	}

	int meio = (l + r)/2;

	modfy(node<<1, l, meio, ql, qr, val);
	modfy(node<<1|1, meio + 1, r, ql, qr, val);
	seg[node] = combine(seg[node<<1], seg[node<<1|1]);
}

pair<ll, ll> query(int node, int l, int r, int ql, int qr){
	unlazy(node, l, r);
	if (r < ql or qr < l)
		return {INF, 0};
	
	if (ql <= l and r <= qr)
		return seg[node];
	
	int meio = (l + r)/2;

	return combine(	query(node<<1, l, meio, ql, qr), 
		query(node<<1|1, meio + 1, r, ql, qr));
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int n, x1, y1, x2, y2;
	vector<tuple<int, int, int>> event;

	cin>>n;

	fr(i, n){
		cin>>x1>>y1>>x2>>y2; // bottom l top r
		event.pb({x1, 0, i});
		event.pb({x2, 1, i});
		top[i] = y2 + 1;
		bot[i] = y1 + 1;
	}

	sort(all(event));

	build(1, 1, MAXN);

	int x, typ, id, p = 0;
	int xx, ttyp;	
	int lst = 0, ans = 0;
	
	while (p < (int)event.size()){
		tie(x, typ, id) = event[p];
		
		xx = x;
		ttyp = typ;

		int dy = MAXN - seg[1].snd;

		ans += (x - lst) * dy;
		lst = x;

		if (p == ((int)event.size()) - 1) // acabou
			break;

		while (x == xx and ttyp == 0){ //adiciona
			modfy(1, 1, MAXN, bot[id], top[id] - 1, 1);
			tie(xx, ttyp, id) = event[++p]; // ok, so acaba quando sai	
		}

		if (xx != x)
			continue;

		while (x == xx and ttyp == 1){ //remove
			modfy(1, 1, MAXN, bot[id], top[id] - 1, -1);
			if (p < ((int)event.size()) - 1)
				tie(xx, ttyp, id) = event[++p];
			else 
				break;
		}
	}

	cout<<ans<<endl;
}