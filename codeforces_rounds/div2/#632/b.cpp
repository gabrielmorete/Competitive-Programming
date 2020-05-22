#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fst first
#define snd second

#define fr(i,n)     for (int i = 0; i < n; i++)
#define frr(i,n)    for (int i = 1; i <= n; i++)

//#define endl '\n'
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
const ll mod=1e9+7;

int n, a[MAXN], b[MAXN];
bool mais[MAXN], menos[MAXN];
void solve(){
	
	cin>>n;
	fr(i, n)
		cin>>a[i];

	fr(i, n)
		cin>>b[i];

	fill(mais, mais + n, 0);
	fill(menos, menos + n, 0);		

	fr(i, n){
		if (a[i] < 0)
			menos[i + 1] = 1;
		if (i > 0 and menos[i - 1])
			menos[i] = 1;

		if (a[i] > 0)
			mais[i + 1] = 1;

		if (i > 0 and mais[i - 1])
			mais[i] = 1;
	}

	bool ok = 1;

	for (int i = n - 1; i > 0; i--){
		if (a[i] < b[i] and !mais[i])
			ok = 0;
		if (a[i] > b[i] and !menos[i])
			ok = 0;
	}

	if (a[0] != b[0])
		ok = 0;

	if (ok)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;

}

int32_t main(){
	fastio;
	int t;
	cin>>t;
	while (t--)
		solve();
}