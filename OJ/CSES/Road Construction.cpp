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
ll id[MAXN], sz[MAXN], maxsz;

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
	maxsz = max(sz[a], maxsz);
	return 1;
}


signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin>>n>>m;

	frr(i, n){
		id[i] = i;
		sz[i] = 1;
	}

	maxsz = 1;
	int ans = n;

	fr(i, m){
		int a, b;
		cin>>a>>b;

		ans -= merge(a, b);

		cout<<ans<<' '<<maxsz<<endl;
	}
}