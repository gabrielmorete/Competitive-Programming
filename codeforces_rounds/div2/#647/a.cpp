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
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
//cout << setprecision(9)<<fixed;

#define dbg(x)  cout << #x << " = " << x << endl
#define all(x)  x.begin(),x.end()

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

const int INF = 0x3f3f3f3f;
const ll llINF = (long long)(1e18) + 100;   
const int MAXN = 1e5 + 10;
const ll mod = 1e9+7;

void solve(){
	ll a, b;
	cin>>a>>b;
	if (a > b)
		swap(a, b);
	
	if (b % a  != 0){
		cout<<-1<<endl;
		return;
	}

	ll x = b/a;
	ll cnt = 0;
	
	while (x > 1 and x % 2 == 0){
		cnt++;
		x /= 2;
	}
	if (x != 1){
		cout<<-1<<endl;
		return;
	}

	ll ans = 0;
	ans += cnt/3;
	cnt %= 3;
	ans += cnt/2;
	cnt %= 2;
	ans += cnt;
	cout<<ans<<endl;
	
}

int32_t main(){
	fastio;
	int T;
	cin>>T;
	while (T--)
		solve();
}