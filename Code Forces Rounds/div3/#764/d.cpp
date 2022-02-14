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
const int MAXN = 4e5 + 10;

int n, k, frq[55];
string s;

void solve(){
	cin>>n>>k;

	cin>>s;

	fr(i, 30)
		frq[i] = 0;

	for (auto x : s)
		frq[x - 'a']++;

	int sum = 0;
	fr(i, 30)
		sum += frq[i]/2; // par

	// tanto para cada
	int ans = 2*(sum/k); // tantos caracteres em cara

	sum -= sum % k;

	fr(i, 30)
		while (frq[i] > 1 and sum > 0){
			frq[i] -= 2;
			sum--;
		}		

	sum = 0;
	fr(i, 30)
		sum += frq[i];

	if (sum >= k)
		ans++;

	cout<<ans<<endl;
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;
	while (T--)
		solve();
}