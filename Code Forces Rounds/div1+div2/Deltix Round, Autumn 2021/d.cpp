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

int id[MAXN], sz[MAXN];

int find(int a){
	if (a == id[a])
		return a;
	return id[a] = find(id[a]);
}

int merge(int a, int b){
	a = find(a);
	b = find(b);

	if (a == b) return true;

	if (sz[a] < sz[b])
		swap(a, b);

	id[b] = a;
	sz[a] += sz[b];

	return false;
}


int n, d;
vii edges;

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin>>n>>d;

	fr(i, d){
		int x, y;
		cin>>x>>y;
		edges.pb({x, y});
	}

	frr(i, n){
		id[i] = i;
		sz[i] = 1;
	}


	int x, y, sobra = 0;
	for (auto e : edges){
		tie(x, y) = e;

		sobra += merge(x, y);

		vii v;
		frr(i, n)
			if (find(i) == i)
				v.pb({sz[i], i});

		sort(all(v));
		reverse(all(v));

		int ans = 0;
		fr(i, 1 + sobra)
			ans += v[i].fst;

		cout<<ans - 1<<endl;
	}
}