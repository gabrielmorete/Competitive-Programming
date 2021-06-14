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
	int n;
	vi v, stk;

	cin>>n;
	int x;
	fr(i, n){
		cin>>x;
		if (x % 2)
			stk.pb(x);
		else
			v.pb(x);
	}

	while (!stk.empty()){
		v.pb(stk.back());
		stk.pop_back();
	}

	int ans = 0;

	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			if (__gcd(v[i], 2*v[j]) > 1)
				ans++;	
	cout<<ans<<endl;		
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;
	while (T--)
		solve();
}