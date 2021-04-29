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
const int MAXN = 3e6 + 10;
const ll mod = 1e9 + 9;

ll fib[MAXN], sum[MAXN], v[MAXN];
ll seg[MAXN], la[MAXN], lb[MAXN];

void build(int node, int l, int r){
	if (l == r){
		seg[node] = v[l];
	}
	else{
		int meio = (l + r)/2;
		build(node<<1, l, meio);
		build(node<<1|1, meio + 1, r);
		seg[node] = (seg[node<<1] + seg[node<<1|1]) % mod;
	}
}

void propagate(int node, int l, int r){
	int m = (r + l)/2;
	if (l != r){
		// filho esquerdo
		la[node<<1] = (la[node<<1] + la[node]) % mod;
		lb[node<<1] = (lb[node<<1] + lb[node]) % mod;

		// filho direito
		ll a = fib[m - l];
		ll b = fib[m - l + 1];

		la[node<<1|1] = (la[node<<1|1] + la[node] * a) % mod;
		lb[node<<1|1] = (lb[node<<1|1] + la[node] * b) % mod;

		a = fib[m - l + 1];
		b = fib[m - l + 2];

		la[node<<1|1] = (la[node<<1|1] + lb[node] * a) % mod;
		lb[node<<1|1] = (lb[node<<1|1] + lb[node] * b) % mod;
	}

	int k = r - l + 1;

	seg[node] = (seg[node] + la[node] * sum[k])% mod;
	seg[node] = (seg[node] + lb[node] * (sum[k + 1] - 1ll))% mod;
	la[node] = lb[node] = 0;
}

void update(int node, int l, int r, int ql, int qr){
	propagate(node, l, r);
	if (qr < l or r < ql)
		return;
	if (ql <= l and r <= qr){
		if (ql == l)
			la[node] = 1;
		else{	
			la[node] = fib[l - ql - 1];
			lb[node] = fib[l - ql];
		}
		propagate(node, l, r);
		return;
	}

	int meio = (l + r)/2;
	update(node<<1, l, meio, ql, qr);
	update(node<<1|1, meio + 1, r, ql, qr);
	seg[node] = (seg[node<<1] + seg[node<<1|1]) % mod;
}

ll query(int node, int l, int r, int ql, int qr){
	propagate(node, l, r);
	if (qr < l or r < ql)
		return 0;
	if (ql <= l and r <= qr)
		return seg[node];
	
	int meio = (l + r)/2;
	ll sa = query(node<<1, l, meio, ql, qr);
	ll sb = query(node<<1|1, meio + 1, r, ql, qr);
	return (sa + sb) % mod;
}


int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	fib[1] = 1;
	for (int i = 2; i < MAXN; i++)
		fib[i] = (fib[i - 1] + fib[i - 2]) % mod;
	for (int i = 1; i < MAXN; i++)
		sum[i] = (fib[i] + sum[i - 1]) % mod;

	int n, m;

	cin>>n>>m;
	frr(i, n)
		cin>>v[i];

	build(1, 1, n);
	
	int a, b, c;
	while (m--){
		cin>>a>>b>>c;
		if (a == 1)
			update(1, 1, n, b, c);		
		else
			cout<<query(1, 1, n, b, c)<<endl;
	}
}