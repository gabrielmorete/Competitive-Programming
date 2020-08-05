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
const int MAXN = 1e6 + 10;

ll sum[MAXN + 1];

int32_t main(){
	fastio;
	ll a, b, c, d;
	cin>>a>>b>>c>>d;

	for (ll x = a; x <= b; x++){
		sum[x + b]++;
		sum[x + c + 1]--;
	}
	frr(i, MAXN) // update
		sum[i] += sum[i - 1];

	frr(i, MAXN) // acum
		sum[i] += sum[i - 1];
	
	ll ans = 0;
	for (ll z = c; z <= d; z++)
		ans += sum[MAXN] - sum[z]; // # x + y > z		
	cout<<ans<<endl;
}