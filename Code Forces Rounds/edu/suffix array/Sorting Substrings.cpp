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
const int MAXN = 5e5 + 10;

int p[MAXN], c[MAXN], c_new[MAXN], cnt[MAXN], cp[MAXN], lcp[MAXN];
pair<int, int> a[MAXN];

int sz;  // array size
int t[2 * MAXN];

void build() {  // build the tree
  for (int i = sz - 1; i > 0; --i) 
  	t[i] = min(t[i<<1], t[i<<1|1]);
}

int query(int l, int r) {  // sum on interval [l, r)
	int res = INF;
	for (l += sz, r += sz; l < r; l >>= 1, r >>= 1) {
		if (l&1) res = min(res, t[l++]);
		if (r&1) res = min(t[--r], res);
	}
	return res;
}

void count_sort(int n){
	fill(cnt, cnt + n, 0);
	for (int i = 0; i < n; i++)
		cnt[c[i] + 1]++;
	for (int i = 1; i < n; i++)
		cnt[i] += cnt[i - 1];
	for (int i = 0; i < n; i++){
		int x = c[p[i]];
		cp[cnt[x]] = p[i];
		cnt[x]++;
	}
	for (int i = 0; i < n; i++)
		p[i] = cp[i];
}

// O(nlogn)
void suffix_array(string &s){
	int n = s.size() + 1;
	sz = n;
	for (int i = 0; i < n - 1; i++)
		a[i] = {s[i], i};
	a[n - 1] = {' ', n - 1};

	sort(a, a + n);

	p[0] = n - 1;
	c[p[0]] = 0;
	for (int i = 1; i < n; i++){
		p[i] = a[i].second;
		c[p[i]] = c[p[i - 1]] + (a[i].first != a[i - 1].first);
	}

	int k = 0;
	while ((1 << k) < n){
		for (int i = 0; i < n; i++)
			p[i] = (p[i] - (1 << k) + n) % n;

		count_sort(n);

		c_new[p[0]] = 0;
		for (int i = 1; i < n; i++){
			int eq = c[p[i - 1]] != c[p[i]];
			eq |= c[(p[i - 1] + (1 << k)) % n] != c[(p[i] + (1 << k)) % n];
			c_new[p[i]] = c_new[p[i - 1]] + eq;
		}
		for (int i = 0; i < n; i++)
			c[i] = c_new[i];	
		k++;
	}

	k = 0;
	for (int i = 0; i < n - 1; i++){
		int pi = c[i]; // is the inverse permutation
		int j = p[pi - 1];
		while (s[i + k] == s[j + k]) k++;
		lcp[pi - 1] = k;
		t[pi - 1 + sz] = k;
		k = max(k - 1, 0);
	}
	build();
}

bool cmp(pii a, pii b){
	int la, lb, ra, rb;
	tie(la, ra) = a;
	tie(lb, rb) = b;

	if (la == lb)
		return ra < rb;

	int pa = c[la], pb = c[lb];

	int lcpr = query(min(pa, pb), max(pa, pb));

	// cout<<la<<' '<<ra<<' '<<c[la]<<endl;
	// cout<<lb<<' '<<rb<<' '<<c[lb]<<endl;
	// cout<<min(pa, pb)<<' '<< max(pa, pb)<< ' '<< lcpr<<endl;
	// chapa;


	if (lcpr >= min(ra, rb)){
		if (ra != rb)
			return ra < rb;
		else
			return la < lb;
	}
	return pa < pb;
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	string s;
	cin>>s;

	memset(t, INF, sizeof t);
	suffix_array(s);

	// dbg(query(3, 4));

	// fr(i, 2 * sz)
	// 	dbg(t[i]);

	int n;
	cin>>n;

	vii v;

	int l, r;
	fr(i, n){
		cin>>l>>r;
		v.pb({l - 1, r - l + 1});
	}

	sort(all(v), cmp);

	for (auto x : v)
		cout<<x.fst + 1<<' '<< x.fst + x.snd<<endl;

}