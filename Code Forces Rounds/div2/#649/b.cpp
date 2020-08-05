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
const int MAXN = 1e5 + 10;

void solve(){
	int n, v[MAXN];

	cin>>n;
	frr(i, n)
		cin>>v[i];


	bool up;	
	vi ans;
	ans.pb(v[1]);	

	if (v[2] > v[1])
		up = 1;
	else
		up = 0;

	for (int i = 2; i <= n; i++){
		if (up){
			if (v[i] > v[i - 1])
				continue;
			else{
				ans.pb(v[i - 1]);
				up = 0;
			}
		}
		else{
			if (v[i] < v[i - 1])
				continue;
			else{
				ans.pb(v[i - 1]);
				up = 1;
			}
		}
	}
	ans.pb(v[n]);
	
	cout<<ans.size()<<endl;
	for (int x : ans)
		cout<<x<<' ';
	gnl;


}

int32_t main(){
	fastio;
	int T;
	cin>>T;
	while (T--)
		solve();
}