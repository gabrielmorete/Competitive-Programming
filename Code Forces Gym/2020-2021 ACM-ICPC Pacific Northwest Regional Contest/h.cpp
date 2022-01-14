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

int seg[4*MAXN];

void update(int node, int l, int r, int p, int val){
	if (p < l or r < p)
		return;
	if (l == r){
		seg[node] = val;
		return;
	}

	int m = (l + r)/2;
	update(node<<1, l, m, p, val);
	update(node<<1|1, m + 1, r, p, val);

	seg[node] = max(seg[node<<1], seg[node<<1|1]);
}

int query(int node, int l, int r, int ql int qr){
	if (qr < l or r < ql)
		return -INF;
	if (ql <= l and r <= qr)
		return seg[node];
	int m = (l + r)/2;

	return max(query(node<<1, l, m, ql, qr), query(node<<1|1, m + 1, r, ql, qr));
}

int n;
int ans[100100], rt[MAXN];
stack<pii> P; // number of people, who hired them
set<int> S; // compute mex
vi tme[MAXN], stk;

int mex(){
	for (auto y : stk)
		update(1, 1, n, y, -INF);

	int aux = query(1, 1, n, 1, n);

	for (auto y : stk)
		if (!tme[y].empty())
			update(1, 1, n, y, tme[y].back());

	if (aux > 0)
		return rt[aux];	


	for(int i = 1; i <= n; i++){
		if(S.find(i) == S.end()) return i;
	}
	return n + 1;
} 



signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	frr(i, n)
		update(1, 1, n, i, -INF);

	frr(i, n){
		int h, f;
		cin >> f >> h;
		S.clear();
		stk.clear();

		while(f != 0){
			pii x = P.top();
			P.pop();

			if(x.fst > f){
				x.fst -= f;
				f = 0;
				
				S.insert(x.snd);
				stk.pb(x.snd);

				P.push(x);
			}
			else{
				f -= x.fst;
				
				S.insert(x.snd);
				stk.insert(x.snd);
				
				tme[x.snd].pop_back();
			}
		}

		int func = mex();
		if(h != 0){
			P.push({h, func});

			tme[func].pb(i);
			update(1, 1, n, func, i);
		
			rt[i] = func;
		}
		ans[i] = func;
	}

	int k = 1;
	fr(i, n) k = max(k, ans[i]);

	cout << k << endl;

	fr(i, n) cout << ans[i] << ' ';
	gnl;
}