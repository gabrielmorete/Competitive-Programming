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
const int MAXN = 3e5 + 10;

int freq[MAXN];

void solve(){
	int n;

	cin>>n;
	fill(freq, freq + n + 1, 0);

	int a;
	fr(i, n){
		cin>>a;
		freq[a]++;
	}

	int ans = 0;
	a = 0;
	frr(i, n){
		ans += (freq[i] + a)/i;
		a = (freq[i] + a) % i;
	}	
	cout<<ans<<endl;

}

int32_t main(){
	fastio;
	int T;
	cin>>T;
	while (T--)
		solve();
}