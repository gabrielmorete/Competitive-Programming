#include "bits/stdc++.h"
using namespace std;

#define pb push_back
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
typedef vector<pii> vii;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = (long long)(1e18) + 100;   
const int MAXN = 1e5 + 10;
const ll mod=1e9+7;

void solve(){
	int n, v[8008], acum[8008];
	bool freq[8080];
	cin>>n;

	frr(i, n){
		freq[i] = 0;
		cin>>v[i];
		acum[i] = v[i];
	}
	acum[0] = 0;

	frr(i, n)
		acum[i] += acum[i - 1];



	for (int i = 0; i < n; i++){
		for (int j = i + 2; j <= n; j++)
			if ((acum[j] - acum[i]) <= n)
				freq[acum[j] - acum[i]] = true;
	}

	int ans = 0;
	frr(i, n)
		if (freq[v[i]])
			ans++;
	
	cout<<ans<<endl;	

}

int32_t main(){
	fastio;
	int T;
	cin>>T;
	while (T--)
		solve();
}