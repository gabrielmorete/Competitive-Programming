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

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n;

	cin>>n;

	int x = 0;
	vi v = {0};
	fr(i, n){
		int y;
		cin>>y;

		x = (x + y) % 360;
		v.pb(x);
	}

	sort(all(v));
	v.pb(360);

	int ans = 0;
	fr(i, v.size() - 1)
		ans = max(ans, v[i + 1] - v[i]);

	cout<<ans<<endl;
}