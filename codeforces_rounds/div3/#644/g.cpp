#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fst first
#define snd second

#define fr(i,n)     for (int i = 0; i < n; i++)
#define frr(i,n)    for (int i = 1; i <= n; i++)

//#define endl '\n'
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
const ll mod=1e9+7;

int n, m, a, b, ans[55][55], lin[55];

void solve(){
	cin>>n>>m>>a>>b;

	if (n * a != m * b){
		cout<<"NO"<<endl;
		return;
	}

	fr(i, n)
		fr(j, m)
			ans[i][j] = 0;

	fr(i, 55)
		lin[i] = 0;

	int tot = 0;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++){
			if (lin[i] < a){
				ans[i][tot] = 1;
				lin[i]++;
				tot = (tot + 1) % m;
			
			}
		}	

	cout<<"YES"<<endl;

	fr(i, n){
		fr(j, m)
			cout<<ans[i][j];
		gnl;	
	}
}

int32_t main(){
	fastio;
	int T;
	cin>>T;
	while (T--)
		solve();
}