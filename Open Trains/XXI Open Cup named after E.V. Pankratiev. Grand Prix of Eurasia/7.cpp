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
const int MAXN = 210;

int n, cmp, id[MAXN], sz[MAXN];

int find(int a){
	if (a == id[a])
		return a;
	return id[a] = find(id[a]);
}

void merge(int a, int b){
	a = find(a);
	b = find(b);

	if (a == b)
		return;

	if (sz[a] < sz[b])
		swap(a, b);

	id[b] = a;
	sz[a] += sz[b];
	cmp--;
}

void solve(){
	fr(i, MAXN){
		sz[i] = 1;
		id[i] = i;
	}

	cin>>n;
	cmp = n;

	fr(i, n)
		fr(j, n){
			int x;
			cin>>x;
			if (x == 1)
				merge(i, j);
		}

	cout<<n - cmp<<endl;
}

signed main(){
	// freopen("input.txt", "r", stdin); 
	// freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;
	while (T--)
		solve();
}