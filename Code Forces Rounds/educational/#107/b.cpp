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

int get_sz(ll x){
	int ans = 0;
	while (x > 0){
		x /= 10;
		ans++;
	}
	return ans;
}

void solve(){
	int a, b, c;

	cin>>a>>b>>c;

	ll nc = 1;
	frr(i, c - 1)
		nc *= 10;

	ll na = nc;
	ll nb = nc;

	while (get_sz(na) < a)
		na *= 2;	
	while (get_sz(nb) < b)
		nb *= 3;	

	cout<<na<<' '<<nb<<endl;
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;
	while (T--)
		solve();
}