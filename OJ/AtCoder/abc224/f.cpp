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
const int MAXN = 3e5 + 10;
const ll mod = 998244353;

ll pre[MAXN], ans[MAXN];
ll n, v[MAXN];

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	string s;
	cin>>s;

	n = s.size();
	fr(i, n)	
		v[i + 1] = s[i] - '0';

	ll p2 = 1;	
	ll s10 = 0;
	for (int i = n; i > 0; i--){
		s10 = (s10 + p2) % mod;
		pre[i] = (s10 * v[i]) % mod;
		pre[i] = (pre[i] + pre[i + 1]) % mod;
		s10 = (s10*10ll) % mod;
		if (i < n)
			p2 = (p2 * 2) % mod;
	}	

	ll acum = 0;

	for (int i = n; i > 0; i--){
		ans[i] = (pre[i] + acum) % mod;
		acum = (acum + ans[i]) % mod;
	}

	ll val = 0;
	for (int i = 1; i <= n; i++)
		val = (val * 10 * v[i]) % mod;

	ans[0] = (ans[1] + val) % mod;

	cout<<ans[1]<<endl;
}