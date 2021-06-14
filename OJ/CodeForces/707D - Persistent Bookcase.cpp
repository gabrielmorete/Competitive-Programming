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

typedef bitset<1001> bit;

#define oper(a, b) a + b // opreação
#define NEUT 0 // elemento neutro

bit refbit;

namespace seg{
	vector<int> seg(1, NEUT), lft(1, 0), rgt(1, 0); 
	vector<bit> seg2(1);
	int rt(0); // ultima raiz

	void init(){ seg = vector<int>(1, NEUT); lft = vector<int>(1, 0); rgt = vector<int>(1, 0); rt = 0;}

	int new_node(int v, int id, int l = 0, int r = 0){
		seg.pb(v);
		lft.pb(l);
		rgt.pb(r);
		seg2.pb(seg2[id]);
		return (int)(seg.size()) - 1;
	}

	int update(int nd, int l, int r, int pos, int op, int val){
		int ks = new_node(seg[nd], nd, lft[nd], rgt[nd]);
		
		if (l == r){
			if (op == 1)
				seg2[ks][val] = 1;
			if (op == 2)
				seg2[ks][val] = 0;
			if (op == 3)
				seg2[ks] ^= refbit;

			seg[ks] = seg2[ks].count();
			return ks;
		}
		
		int m = (l + r)/2, ps;
		if(pos <= m)
		    ps = update(lft[nd], l, m, pos, op, val), lft[ks] = ps;
		else 
			ps = update(rgt[nd], m + 1, r, pos, op, val), rgt[ks] = ps;
		
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

	int update(int l, int r, int pos, int op, int val){ return rt = update(rt, l, r, pos, op, val); } // ultima raiz
} 


int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m, q;
	cin>>n>>m>>q;

	frr(i, m)
		refbit[i] = 1;

	vi root = {0};

	int op, a, b;
	while (q--){
		cin>>op;
		if (op <= 2){
			cin>>a>>b;
			root.pb(seg::update(root.back(), 1, n, a, op, b));
		}
		else{
			cin>>a;
			if (op == 3)
				root.pb(seg::update(root.back(), 1, n, a, 3, 0));
			else
				root.pb(root[a]);
		}
		cout<<seg::query(root.back(), 1, n, 1, n)<<endl;
	}
}