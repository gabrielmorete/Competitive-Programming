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
const ll mod = 1e9 + 7;

void solve(){
	ll n, ans, val, num, res;

	cin>>n;

	ans = 0;
	val = 1;
	num = 2;
	res = n;
	while (val <= n){
		ll valn = val;
		while ((val % num) != 0)
			val += valn;

		// cheguei no mod
		ll aux = (res - (n/val)) % mod; // numero de caras que num é o menor divisor
		ans = (ans + num * aux) % mod;
		res = n/val; // os multiplos
		num++;	
	}

	cout<<ans<<endl;
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;
	while (T--)
		solve();
}