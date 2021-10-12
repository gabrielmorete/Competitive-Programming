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
const int MAXN = 1e4 + 10;
const ll mod = 998244353;

ll n, a[MAXN], b[MAXN], now[MAXN], lst[MAXN];

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin>>n;

	fr(i, n)
		cin>>a[i];
	fr(i, n)
		cin>>b[i];

	for (int v = a[0]; v <= b[0]; v++)
		lst[v] = 1;

	for (int i = 1; i < n; i++){
		ll val = 0;
		for (int j = 0; j < 3001; j++){
			val += lst[j];
			val %= mod;
			if (a[i] <= j and j <= b[i])
				now[j] = val;
		}

		fr(j, 3001){
			lst[j] = now[j];
			now[j] = 0;
		}
	}

	ll ans = 0;
	fr(j, 3001)
		ans = (ans + lst[j]) % mod;

	cout<<ans<<endl;	
}