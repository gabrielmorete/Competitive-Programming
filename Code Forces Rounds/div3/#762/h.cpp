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
const int MAXN = 4e5 + 10;
const int step = 100;

int n, q, p[MAXN], r[MAXN], skp[MAXN];

int run(int v){
	
	fr(i, step)
		v = p[v];

	return v;
}

void update(int a, int b){
	swap(p[a], p[b]);
	swap(r[p[a]], r[p[b]]);

	fr(i, step + 1){
		skp[a] = run(a);
		a = r[a];
	
		skp[b] = run(b);
		b = r[b];
	}
}

int query(int v, int k){
	while (k >= step){
		v = skp[v];
		k -= step;
	}

	while (k-- > 0)
		v = p[v];

	return v;
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin>>n>>q;

	frr(i, n){
		int x;
		cin>>x;
		p[i] = x; // permutation
		r[x] = i; // reverse
	}


	frr(i, n)
		skp[i] = run(i);

	int typ, a, b;
	while (q--){
		cin>>typ>>a>>b;

		if (typ == 1)
			update(a, b);
		else
			cout<<query(a, b)<<endl;
	}	
}