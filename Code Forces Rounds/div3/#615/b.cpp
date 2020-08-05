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
const ll mod=1e9+7;

void solve(){
	int n;
	vii v;
	cin>>n;

	int a, b;
	fr(i, n){
		cin>>a>>b;
		v.pb({a, b});
	}

	sort(all(v));	
	bool ok = 1;
	int hgt = -1;

	for (auto x : v){
		if (x.snd < hgt)
			ok = 0;
		hgt = x.snd;
	}

	if (!ok){
		cout<<"NO"<<endl;
		return;
	}

	a = 0;
	b = 0;
	string ans;

	for (auto x : v){
		while (a < x.fst){
			ans.pb('R');
			a++;
		}
		while (b < x.snd){
			ans.pb('U');
			b++;
		}
	}

	cout<<"YES"<<endl;
	cout<<ans<<endl;
}

int32_t main(){
	fastio;
	int T;
	cin>>T;
	while (T--)
		solve();
}