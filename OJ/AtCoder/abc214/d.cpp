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

ll id[MAXN], sz[MAXN];

ll find(ll a){
	if (id[a] == a)
		return a;
	return id[a] = find(id[a]);
}

void merge(ll a, ll b){
	a = find(a);
	b = find(b);
	if (a == b)
		return;
	if (sz[a] < sz[b])
		swap(a, b);
	id[b] = a;
	sz[a] += sz[b];
}

ll n, ans;

typedef tuple<ll, ll, ll> tup;

vector<tup> edges;

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	fr(i, MAXN){
		id[i] = i;
		sz[i] = 1;
	}


	cin>>n;

	ll a, b, c;
	fr(i, n - 1){
		cin>>a>>b>>c;
		edges.pb({c, a, b});
	}

	sort(all(edges));

	for (auto x : edges){
		tie(c, a, b) = x;
		ans += sz[find(a)] * sz[find(b)] * c;
		merge(a, b);
	}

	cout<<ans<<endl;
}	