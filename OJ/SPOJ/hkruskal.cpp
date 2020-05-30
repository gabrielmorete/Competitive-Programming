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
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
//cout << setprecision(9)<<fixed;

#define dbg(x)  cout << #x << " = " << x << endl
#define all(x)  x.begin(),x.end()

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

const int INF = 0x3f3f3f3f;
const ll llINF = (long long)(1e18) + 100;   
const int MAXN = 1e5 + 10;
const ll mod = 1e9+7;

int n, m;

int id[MAXN], sz[MAXN];
int find(int a){
	return a == id[a] ? a : id[a] = find(id[a]);
}

bool merge(int a, int b){
	a = find(a);
	b = find(b);
	if (a == b) return false;
	if (sz[a] < sz[b])
		swap(a, b);
	id[b] = a;
	sz[a] += sz[b];

	return true;
}

vector< tuple<ll, ll, ll> > edge;

ll sum, ways;

void calc(int p){
	map< pair<ll,ll>, ll > fp;
	set<int> q;
	ll cnt = 0, mp = 0, a, b;
	int aux = get<0>(edge[p]);

	while (p < m and get<0>(edge[p]) == aux){
		a = find(get<1>(edge[p]));
		b = find(get<2>(edge[p]));

		if (a > b)
			swap(a, b);

		if (a != b){
			q.insert(a);
			q.insert(b);

			mp = max(mp, ++fp[{a, b}]);
			
			cnt++;
		}

		p++;
	}
	
	if (q.size() == 2 or q.size() == 4){
		ways = (ways * mp) % mod;
		return;
	}

	if (q.size() != 3 or cnt < 3) // Mult por 1
		return;
	
	if (mp == 2)
		ways = (ways * 2ll) % mod;
	else
		ways = (ways * 3ll) % mod;
}

void kruskal(){
	sum = 0;
	ways = 1;

	sort(all(edge));

	ll lst = -1;	

	for (int i = 0; i < m; i++){
		if (get<0>(edge[i]) != lst){
			calc(i);
			lst = get<0>(edge[i]);
		}

		if (merge(get<1>(edge[i]), get<2>(edge[i])))
			sum = (sum + get<0>(edge[i])) % mod;
	}
}

int32_t main(){
	fastio;
	cin>>n>>m;

	frr(i, n){
		id[i] = i;
		sz[i] = 1;
	}

	int a, b, c;
	fr(i, m){
		cin>>a>>b>>c;
		edge.pb({c, a, b});
	}

	kruskal();

	cout<<sum<<' '<<ways<<endl;
}