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

int sqr(ll x){
	for (ll i = 1; i * i <= x; i++)
		if (i * i == x)
			return true;
	return false;	
}

void solve(){
	ll n;
	cin>>n;

	if (n % 2 == 0 and sqr(n/2))
		cout<<"YES"<<endl;
	else if (n % 4 == 0 and sqr(n/4))
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;
	while (T--)
		solve();
}