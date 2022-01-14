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
const int MAXN = 4e3 + 10;
const int szbit = 160;

int n, m, k;
bitset<szbit> a[MAXN], b[MAXN];

bitset<szbit> to_bit(string s){
	bitset<szbit> c;

	reverse(all(s));

	fr(i, k){
		int aux = (s[i] >= 'a'? s[i] - 'a' + 10 : s[i] - '0');

		fr(j, 4)
			if (aux & (1<<j))
				c[4 * i + j] = 1;
	}

	return c;
}

vi basis, blsb;

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin>>n>>m>>k;

	int zero = n + 1;

	string s;
	fr(i, n){
		cin>>s;

		bitset<szbit> c = to_bit(s);
	
		fr(i, basis.size())
			if (c[ blsb[i] ] == 1)
				c = c^a[ basis[i] ];
	
		if (c.count() == 0)
			zero = min(zero, i);
		else{
			int lsb = 0;
			while (c[lsb] == 0)
				lsb++;

			basis.pb(i);
			blsb.pb(lsb);
		}

		a[i] = c;
	}

	if (zero == n + 1)
		zero = -2;

	fr(i, m){
		cin>>s;
		bitset<szbit> c = to_bit(s);
	
		if (c.count() == 0){
			cout<<zero + 1<<endl;
			continue;
		}

		int ans = -2;

		fr(i, basis.size()){
			if (c[blsb[i]] == 1)
				c = c^a[ basis[i] ];

			if (c.count() == 0){
				ans = basis[i];
				break;
			}
		}

		cout<<ans + 1<<endl;
	}
}