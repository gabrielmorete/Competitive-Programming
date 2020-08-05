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
const int MAXN = 2e5 + 10;
const ll mod=1e9+7;

int freq[300], last[MAXN];

int32_t main(){
	fastio;
	int n, k;
	string s;

	cin>>n>>k;
	cin>>s;

	char c;
	fr(i, k){
		cin>>c;
		freq[c] = 1;
	}

	frr(i, n){
		last[i] = n + 1;
		if (freq[s[i - 1]] == 0)
			last[i] = i;
	}
	
	for (int i = n - 1; i > 0; i--){
		last[i] = min(last[i], last[i + 1]);
	}

	ll ans = 0;
	frr(i, n){
		ans += (ll) last[i] - i;
	}
	cout<<ans<<endl;


}