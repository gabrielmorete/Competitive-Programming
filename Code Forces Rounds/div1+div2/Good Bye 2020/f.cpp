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

int id[MAXN], sz[MAXN];

int find(int a){
	if (id[a] == a)
		return a;
	return id[a] = find(id[a]);
}

int merge(int a, int b){
	a = find(a);
	b = find(b);

	if (a == b)
		return 0;

	if (sz[b] > sz[a])
		swap(a, b);

	id[b] = a;
	sz[a] += sz[b];
	return 1;
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	fr(i, MAXN){
		id[i] = i;
		sz[i] = 1;
	}

	int n, m, k, x, y;

	cin>>n>>m;
	vi ans;

	fr(i, n){
		cin>>k;

		y = 0;
		if (k == 1)
			cin>>x;
		else
			cin>>x>>y;

		if (merge(x, y))
			ans.pb(i + 1);			
	}

	ll sum = 1;
	ll mod = 1e9 + 7;

	for (auto x : ans){
		sum <<= 1;
		sum %= mod;
	}

	cout<<sum<<' '<<ans.size()<<endl;
	for (auto x : ans)
		cout<<x<<' ';
	gnl;
}