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

int n, v[55];

void solve(){
	vi ans;

	cin>>n;
	fr(i, n)
		cin>>v[i];


	for (int i = 0; i < n - 1; i++){
		ans.pb(v[i]);

		int aux = v[i];

		while (2 * aux < v[i + 1]){
			ans.pb(aux);
			aux *= 2;
		}

		aux = v[i + 1];
		
		while (2 * aux < v[i]){
			ans.pb(aux);
			aux *= 2;
		}
	}	

	ans.pb(v[n - 1]);

	cout<<ans.size() - n <<endl;
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;
	while (T--)
		solve();
}