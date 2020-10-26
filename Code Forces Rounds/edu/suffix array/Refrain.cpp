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

#define int ll

int p[MAXN], c[MAXN], c_new[MAXN], cnt[MAXN], cp[MAXN], lcp[MAXN];
pair<int, int> a[MAXN];

int sz;  // array size
int t[2 * MAXN];

void modify(int p, int value) {  // set value at position p
  for (t[p += sz] = value; p > 1; p >>= 1) t[p>>1] = min(t[p], t[p^1]);
}

int query(int l, int r) {  // sum on interval [l, r)
	int res = sz;
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
		k = max(k - 1, 0ll);
	}
}

int res[MAXN];

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	string s;
	
	int n, m, x;
	cin>>n>>m;
	fr(i, n){
		cin>>x;
		s.pb('a' + x - 1);
	}

	if (n == 1){
		cout<<1<<endl<<1<<endl<<s[0] - 'a' + 1<<endl;
		return 0;
	}

	memset(t, INF, sizeof t);
	suffix_array(s);
	sz = n;

	fill(t, t + 2 * MAXN, n);

	for (ll i = 1; i <= n; i++){
		ll aux = query(0, lcp[i]);
		if (aux < 0)
			aux = -aux;

		modify(lcp[i], -i);

		if (aux >= n)
			aux = 0;

		res[i] = lcp[i] * (i - aux);
	}

	fill(t, t + 2 * MAXN, n);

	for (ll i = n; i > 0; i--){
		ll aux = query(0, lcp[i]);
		modify(lcp[i], i);

		res[i] += lcp[i] * (aux - i);
	}

	int mx = 0, pos = 0;

	for (int i = 1; i <= n; i++)
		if (res[i] > mx){
			mx = res[i];
			pos = i;
		}
	
	if (mx < n){
		cout<<n<<endl<<n<<endl;
		for (int i = 0; i < n; i++){
			cout<<(s[i] - 'a' + 1)<<' ';
		}
		gnl;
	}	
	else{
		cout<<mx<<endl;	
		cout<<lcp[pos]<<endl;
		for (int i = p[pos]; i < p[pos] + lcp[pos]; i++){
			cout<<(s[i] - 'a' + 1)<<' ';
		}
		gnl;
	}
}