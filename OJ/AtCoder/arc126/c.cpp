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
const int MAXN = 7e5 + 10;

ll n, k, a[MAXN];
ll freq[MAXN], dif[MAXN];

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin>>n>>k;

	fr(i, n)
		cin>>a[i];

	sort(a, a + n);
	
	ll dlt = 0;
	fr(i, n)
		dlt += a[n - 1] - a[i];

	if (dlt <= k){ // caso 1
		k -= dlt;
		k /= n;

		cout<<a[n - 1] + k<<endl;
		return 0;
	}

	fr(i, n)
		freq[a[i]]++;
	
	frr(i, MAXN - 1)
		freq[i] += freq[i - 1];	


	for (ll i = 1; i < MAXN; i++){
		dif[i] = dif[i - 1] + freq[i - 1];
	}


	ll ans = 1;
	for (ll val = 1; val <= a[n - 1]; val++){
		ll cst = 0;
		for (ll mul = val; mul < MAXN; mul += val){
			cst += dif[mul] - (dif[mul - val] + val * freq[mul - val]);
		}

		if (cst <= k)
			ans = val;
	}

	cout<<ans<<endl;

}
