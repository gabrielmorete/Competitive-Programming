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
	vi ans;

	while (n > k){
		ans.pb(n);
		n--;
	}

	for (int i = k - 1; i > 0; i--){
		if (k % 2){
			if (i > k/2)
				ans.pb(i);
			else
				break;
		}	
		else{
			if (i >= k/2)
				ans.pb(i);
			else
				break;
		}
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