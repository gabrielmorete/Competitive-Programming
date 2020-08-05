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


map<pii, int> bns;
ll a[MAXN], b[MAXN], ans;

int32_t main(){
	fastio;
	int n;
	cin>>n;

	frr(i, n){
		cin>>a[i];
		ans += a[i];
	}

	int s, t, u, q;
	cin>>q;
	while (q--){
		cin>>s>>t>>u;
		if (bns[{s, t}] != 0){
			b[bns[{s, t}]]--;
			if (b[bns[{s, t}]] < a[bns[{s, t}]])
				ans++;
			bns[{s, t}] = 0;
		}

		if (u != 0){
			bns[{s, t}] = u;
			b[u]++;
			if (b[u] <= a[u])
				ans--;
		}
		cout<<ans<<endl;
	}
}