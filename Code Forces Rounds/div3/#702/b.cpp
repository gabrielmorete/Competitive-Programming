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

void solve(){
	int n, r[3];

	cin>>n;

	r[0] = r[1] = r[2] = 0;

	int x;
	fr(i, n){
		cin>>x;
		r[x%3]++;
	}

	int ans = 0;

	fr(i, 20){
		if (r[i % 3] > n/3){
			int dlt = r[i % 3] - n/3;
			ans += dlt;
			r[i % 3] -= dlt;
			r[(i + 1) % 3] += dlt;
		}
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