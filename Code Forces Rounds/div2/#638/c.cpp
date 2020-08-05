#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i,n)     for(int i=0;i<n;i++)
#define frr(i,n)    for(int i=1;i<=n;i++)

#define ms(x,i) memset(x,i,sizeof(x))
#define dbg(x)  cout << #x << " = " << x << endl
#define all(x)  x.begin(),x.end()

#define gnl cout << endl
#define chapa cout << "oi meu chapa" << endl
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
//cout << setprecision(9)<<fixed;

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = (long long)(1e18) + 100;   
const int MAXN = 100100;
const int MAXM = 1001000;
const ll mod=1e9+7;
const int LMAXN = 25;

void solve(){
	int n, k;
	string s;
	
	cin>>n>>k;
	cin>>s;

	sort(all(s));

	if (s[0] == s[n - 1]){
		int aux = (n + k - 1)/k;
		while (aux--)
			cout<<s[0];
		gnl;
		return;
	}
	
	vi values;
	int freq[1000];

	fr(i,1000)
		freq[i] = 0;

	for(auto x : s)
		freq[x]++;

	fr(i,1000)
		if (freq[i])
			values.pb(freq[i]);
		
	if (values.size() == 2 and values[0] == k){
		cout<<s[0];

		int aux = (values[1] + k - 1)/k;
		while (aux--)
			cout<<s[n - 1];
		gnl;
		return;
	}

	if (values[0] < k){
		cout<<s[k - 1]<<endl;
		return;	
	}	

	string ans;

	ans.pb(s[0]);
	for (int i = k; i < n; i++)
		ans.pb(s[i]);
	cout<<ans<<endl;
}

int main(){
	fastio;
	int t;
	cin>>t;
	while (t--)
		solve();
}