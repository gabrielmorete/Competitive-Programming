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
#define all(x)  x.begin(),x.end()

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

const int INF = 0x3f3f3f3f;
const ll llINF = (long long)(1e18) + 100;   
const int MAXN = 1e5 + 10;

int n, v[MAXN];

void solve(){
	cin>>n;
	fr(i, n)
		cin>>v[i];

	v[n] = INF;	
	int ans = 0;
	
	for (int i = n - 1; i >= 0; i--){
		if (v[i] + 1 < v[i + 1])
			v[i]++;

		if (v[i] != v[i + 1])
			ans++;		
	}
	
	cout<<ans<<endl;
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int T;

	cin>>T;
	while (T--)
		solve();
}