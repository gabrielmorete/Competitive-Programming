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
const ll mod = 998244353;


ll n, k, up[MAXN], fix[MAXN];

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin>>n>>k;

	char c;
	int p;
	fr(i, k){
		cin>>c>>p;

		if (c == 'L')
			up[p]++;
		else{
			up[0]++;
			up[p]--;
		}

		fix[p] = 1;
	}

	if (k > n){
		cout<<0<<endl;
		return 0;
	}


	ll now, ans;

	now = up[0];
	ans = 1;

	frr(i, n){
		now += up[i];
		now %= mod;
		if (fix[i])
			continue;
		ans = (ans * now) % mod;
	}

	cout<<ans<<endl;
}