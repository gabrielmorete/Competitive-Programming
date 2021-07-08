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
	ll n, a, b;

	cin>>n>>a>>b;

	if (n == 1 or b == 1 or (n % b) == 1){
		cout<<"Yes"<<endl;
		return;
	}

	if (a == 1){
		cout<<"No"<<endl;
		return;
	}

	// todos da forma a^k + rb

	ll pwr = 1;

	while (pwr <= n){
		if ((n - pwr) % b == 0){
			cout<<"Yes"<<endl;
			return;
		}
		pwr *= a;
	}

	cout<<"No"<<endl;
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;
	while (T--)
		solve();
}