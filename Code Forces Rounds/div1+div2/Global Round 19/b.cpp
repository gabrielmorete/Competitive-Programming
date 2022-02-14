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

int n, frq[MAXN];
void solve(){
	cin>>n;
	fr(i, n + 1)
		frq[i] = 0;

	frr(i, n){
		int x;
		cin>>x;
		if (x == 0)
			frq[i]++;
	}	

	frr(i, n)
		frq[i] += frq[i - 1];

	ll ans = 0;
	
	for (int i = 1; i <= n; i++)
		for (int j = i; j <= n; j++){
			ans += j - i + 1;
			ans += frq[j] - frq[i - 1];
		}

	cout<<ans<<endl;
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;
	while (T--)
		solve();
}