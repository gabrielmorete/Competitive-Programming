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
const int MAXN = 2e5 + 10;

typedef tuple<int, int, int, int> tup;

int lin[MAXN], col[MAXN], ans[MAXN];
int h, w, n;

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin>>h>>w>>n;

	vector<tup> v;
	int a, b, c, d;
	fr(i, n){
		cin>>a>>b>>c;
		v.pb({c, a, b, i});
	}

	sort(all(v));
	reverse(all(v));

	memset(lin, -1, sizeof lin);
	memset(col, -1, sizeof col);

	int p = 0;
	while (p < n){
		int q = p;

		while (q < n and get<0>(v[q]) == get<0>(v[p]))
			q++;

		for (int i = p; i < q; i++){
			tie(a, b, c, d) = v[i];
			ans[d] = max(lin[b], col[c]) + 1;
		}

		for (int i = p; i < q; i++){
			tie(a, b, c, d) = v[i];
			lin[b] = max(lin[b], ans[d]);
			col[c] = max(col[c], ans[d]);
		}

		p = q;
	}

	fr(i, n)
		cout<<ans[i]<<endl;
}