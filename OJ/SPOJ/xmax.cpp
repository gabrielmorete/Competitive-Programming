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

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n;
	cin>>n;

	vector<ll> v(n);
	fr(i, n)
		cin>>v[i];

	sort(all(v));
	reverse(all(v));

	int p = 0;
	for (int j = 59; j >= 0; j--){
		int pos = -1;

		for (int i = p; i < n; i++)
			if (v[i]&(1ll<<j))
				pos = i;

		if (pos == -1)
			continue;

		swap(v[p], v[pos]);

		for (int i = p + 1; i < n; i++)
			if (v[i]&(1ll<<j))
				v[i] ^= v[p];
		p++;	
	}
	
	ll ans = 0;
	fr(i, n)
		if (ans < (ans^v[i]))
			ans ^= v[i];
	

	cout<<ans<<endl;
}