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

ll n, a[MAXN], v[MAXN], sum[MAXN];

set<ll> win;

void solve(){
	win.clear();
	cin>>n;

	fr(i, n)
		cin>>a[i];
	
	fr(i, n)
		v[i] = a[i];

	sort(v, v + n);		

	sum[0] = 0;

	frr(i, n)
		sum[i] = sum[i - 1] + v[i - 1];

	win.insert(v[n - 1]);	

	for (int i = n - 2; i >= 0; i--){
		if (v[i] < v[i + 1]){ // toquei de valor
			if (sum[i + 1] >= v[i + 1] and win.find(v[i + 1]) != win.end())
				win.insert(v[i]);
		}
	}

	vi ans;
	fr(i, n){
		if (win.count(a[i]) != 0)
			ans.pb(i + 1);
	}

	cout<<ans.size()<<endl;
	for (auto x : ans)
		cout<<x<<' ';

	gnl;
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;
	while (T--)
		solve();
}