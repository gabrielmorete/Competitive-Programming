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
#define oper(a, b) a + b // opreação
#define NEUT 0 // elemento neutro

namespace seg{
	vector<int> seg(1, NEUT), lft(1, 0), rgt(1, 0); 
	int rt(0); // ultima raiz

	void init(){ seg = vector<int>(1, NEUT); lft = vector<int>(1, 0); rgt = vector<int>(1, 0); rt = 0;}

	int new_node(int v, int l = 0, int r = 0){
		seg.pb(v);
		lft.pb(l);
		rgt.pb(r);
		return (int)(seg.size()) - 1;
	}

	int update(int nd, int l, int r, int pos, int val){
		int ks = new_node(seg[nd], lft[nd], rgt[nd]);
		if (l == r){
			seg[ks] = val;
			return ks;
		}
		
		int m = (l + r)/2, ps;
		if(pos <= m)
		    ps = update(lft[nd], l, m, pos, val), lft[ks] = ps;
		else 
			ps = update(rgt[nd], m + 1, r, pos, val), rgt[ks] = ps;
		
		seg[ks] = oper(seg[lft[ks]], seg[rgt[ks]]);
		return ks;
	}

	int query(int nd, int l, int r, int ql, int qr){
		if(r < ql or qr < l)
			return NEUT;
		if(ql <= l and r <= qr)
			return seg[nd];
		int m = (l + r)/2;
		return oper(query(lft[nd], l, m, ql, qr), query(rgt[nd], m + 1, r, ql, qr));
	}

	int update(int l, int r, int pos, int val){ return rt = update(rt, l, r, pos, val); } // ultima raiz
} 

int n, k, a[MAXN], prv[MAXN];
queue<int> pos[MAXN];

vi prvin[MAXN];	


int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin>>n>>k;
	frr(i, n)
		cin>>a[i];

	frr(i, n){
		if (pos[a[i]].size() == k){
			prv[i] = pos[a[i]].front();
			pos[a[i]].pop();
		}
		pos[a[i]].push(i);
		prvin[prv[i]].pb(i);
	}

	vi root;

	fr(i, n + 1){
		int rt = -1;
		for (auto x : prvin[i])
			rt = seg::update(0, n, x, 1);

		if (rt == -1)
			root.pb(root.back());
		else
			root.pb(rt);
	}


	int q, l, r, lst;

	lst = 0;

	cin>>q;
	while (q--){
		cin>>l>>r;
		l = ((l + lst) % n) + 1;
		r = ((r + lst) % n) + 1;
		if (l > r) swap(l, r);

		lst = seg::query(root[l - 1], 0, n, l, r);
		cout<<lst<<endl;
	}
}