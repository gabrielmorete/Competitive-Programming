#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fst first
#define snd second

#define fr(i,n)     for (int i = 0; i < n; i++)
#define frr(i,n)    for (int i = 1; i <= n; i++)

// #define endl '\n'
#define gnl cout << endl
#define chapa cout << "oi meu chapa" << endl

#define dbg(x)  cout << #x << " = " << x << endl
#define all(x)  x.begin(), x.end()

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

const int INF = 0x3f3f3f3f;
const ll llINF = (long long)(1e12);   
const int MAXN = 4e5 + 10;

vector<ll> v;

map<pair<int, ll>, int> memo;

int pd(int pos, ll val){
	if (val < 0)
		return 1000;

	if (pos < 0)
		return __builtin_popcountll(val);

	if (memo.count({pos, val}))
		return memo[{pos, val}];

	int pdm = __builtin_popcountll(val);
	
	pdm = min(pdm, pd(pos - 1, val - v[pos]) + 1);

	pdm = min(pdm, pd(pos - 1, val));

	memo[{pos, val}] = pdm;
	return pdm;
}


signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	set<ll> q;

	ll fat = 6;
	for (ll i = 4; fat <= llINF; i++){
		q.insert(fat);
		fat *= i;
	}

	while (!q.empty()){
		v.pb(*q.begin());
		q.erase(q.begin());
	}

	int T;
	cin>>T;

	while (T--){
		memo.clear();
		ll n;
		cin>>n;

		int p = (int)(upper_bound(all(v), n) - v.begin());

		cout<<pd(p - 1, n)<<endl;
	}
}