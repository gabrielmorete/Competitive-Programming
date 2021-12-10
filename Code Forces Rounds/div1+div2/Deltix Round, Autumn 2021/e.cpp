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

int n, q;
string s;

int seg[4*MAXN][6];// a, b, c, ab, bc, abc

void merge(int a, int b, int c){
	fr(i, 3) // a, b, c
		seg[c][i] = seg[a][i] + seg[b][i];

	seg[c][3] = min(seg[a][0] + seg[b][3], seg[a][3] + seg[b][1]); // a ab, ab b
	seg[c][4] = min(seg[a][1] + seg[b][4], seg[a][4] + seg[b][2]); // b bc, bc, c
	seg[c][5] = min({seg[a][0] + seg[b][5], seg[a][3] + seg[b][4], seg[a][5] + seg[b][2]}); // a abc, ab bc, abc c
}

void update(int node, int l, int r, int pos){
	if (pos < l or r < pos)
		return;

	if (l == r){
		seg[node][0] = seg[node][1] = seg[node][2] = 0;
		seg[node][s[pos] - 'a'] = 1;
		return;
	}

	int m = (l + r)/2;

	update(node<<1, l, m, pos);
	update(node<<1|1, m + 1, r, pos);
	merge(node<<1, node<<1|1, node);
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin>>n>>q;
	cin>>s;

	fr(i, n)
		update(1, 0, n - 1, i);

	while (q--){
		int x;
		char c;
		cin>>x>>c;
		s[x - 1] = c;
		update(1, 0, n - 1, x - 1);
		cout<<seg[1][5]<<endl;
	}	
}