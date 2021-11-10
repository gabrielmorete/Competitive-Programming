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

set<int> d;

void fac(int n){
	for (int i = 1; i * i <= n; i++)
		if (n%i == 0){
			if (d.count(i))
				d.erase(i);
			if (d.count(n/i))
				d.erase(n/i);
		}
}

void solve(){
	d.clear();
	int n;
	char c;
	string s;

	cin>>n>>c>>s;

	vi v;
	fr(i, n)
		if (s[i] != c)
			v.pb(i + 1);

	if (v.size() == 0){
		cout<<0<<endl;
		return;
	}

	frr(i, n)
		d.insert(i);

	for (auto x : v)
		fac(x);

	if (!d.empty()){
		cout<<1<<endl;
		cout<<*d.begin()<<endl;
		return;
	}

	cout<<2<<endl;
	cout<<n - 1<<' '<<n<<endl;
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;
	while (T--)
		solve();
}