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

ll n, frq[4];

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin>>n;

	ll x, y;

	fr(i, n){
		cin>>x>>y;
		if (x % 4 == 0 and y % 4 == 0) frq[0]++;
		if (x % 4 == 2 and y % 4 == 0) frq[1]++;
		if (x % 4 == 0 and y % 4 == 2) frq[2]++;
		if (x % 4 == 2 and y % 4 == 2) frq[3]++;
	}

	ll ans = 0;

	fr(i, 4){
		ans += ((frq[i]) * (frq[i] - 1ll) * (frq[i] - 2ll))/6ll; // combina os 3 de mesmo tipo
		ans += ((frq[i]) * (frq[i] - 1) * (n - frq[i]))/2; // combina dois de mesmo tipo com um diferente
		// tres difetnes não da 0 mod4
	}

	cout<<ans<<endl;
}