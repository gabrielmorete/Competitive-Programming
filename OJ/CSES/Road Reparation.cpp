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

ll n, m;
vector<array<ll, 3>> edges;

ll id[MAXN], sz[MAXN];

int find(int a){
	if (a == id[a])
		return a;
	return id[a] = find(id[a]);
}


bool merge(int a, int b){
	a = find(a);
	b = find(b);

	if (a == b) return 0;
	if (sz[a] < sz[b]) swap(a, b);

	id[b] = a;
	sz[a] += sz[b];
	return 1;
}


signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin>>n>>m;

	fr(i, m){
		int a, b, c;
		cin>>a>>b>>c;
		edges.pb({c, a, b});
	}


	sort(all(edges));

	frr(i, n){
		id[i] = i;
		sz[i] = 1;
	}

	ll cst = 0;
	for (auto x : edges){
		if (merge(x[1], x[2]))
			cst += x[0];
	}

	if (sz[find(1)] != n)
		cout<<"IMPOSSIBLE"<<endl;
	else
		cout<<cst<<endl;


}