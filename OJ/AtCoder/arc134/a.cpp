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

ll n, w, l, a[MAXN];

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin>>n>>l>>w;

	stack<ll> stk;

	fr(i, n)
		cin>>a[i];

	stk.push(l);
	fr(i, n)
		stk.push(a[n - i - 1]);

	ll ans = 0, l = 0;
	
	while (!stk.empty()){
		ll x = stk.top();
		stk.pop();

		if (l < x){
			ll dlt = x - l;
			ll aux = (dlt + w - 1)/w;

			ans += aux;
			l += aux * w;
		}

		l = max(l, x + w);
	}

	cout<<ans<<endl;
}