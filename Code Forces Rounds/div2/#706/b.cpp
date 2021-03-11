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

void solve(){
	int n, k;
	cin>>n>>k;

	set<int> q;

	int x;
	fr(i, n){
		cin>>x;
		q.insert(-x);
	}

	int mex = 0;

	while (q.count(-mex) > 0)
		mex++;

	int mx = -(*q.begin());

	ll ans = q.size();

	if (k == 0){
		cout<<ans<<endl;
		return;
	}

	if (mex < mx){
		if (!q.count(-((mex + mx + 1)/2)))
			ans++;
		cout<<ans<<endl;
	}
	else{
		cout<<ans + k<<endl;
	}
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;
	while (T--)
		solve();
}