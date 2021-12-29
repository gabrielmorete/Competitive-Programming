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

ll n, hgt[MAXN], tot[MAXN];

bool test(ll val){
	fr(i, n)
		tot[i] = 0;

	for (int i = n - 1; i >= 0; i--){
		if (hgt[i] + tot[i] < val)
			return false;

		ll dlt = hgt[i] - max(0ll, (val - tot[i]));

		// dbg(dlt);
		dlt /= 3;
		// dbg(dlt);
		if (i >= 2){
			tot[i - 1] += dlt;
			tot[i - 2] += 2 * dlt;
		}
	}	

	return true;
}

void solve(){
	cin>>n;
	fr(i, n)
		cin>>hgt[i];

	ll ini = 1, fim = 1e9, bst = 1;	

	while (ini <= fim){
		ll mid = (ini + fim)/2;

		if (test(mid)){
			bst = mid;
			ini = mid + 1;
		}
		else
			fim = mid - 1;
	}

	cout<<bst<<endl;
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;

	while (T--)
		solve();
}