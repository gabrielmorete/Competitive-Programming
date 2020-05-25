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
const ll mod=1e9+7;

void solve(){
	string v[110];
	ll n, m;

	cin>>n>>m;

	fr(i, n)
		cin>>v[i];

	ll res = (1ll << m) - n; // Restam
	ll med = (res - 1ll)/2ll; // Nova mediana

	bool ok;
	string ans;
	for (int bit = 0; bit < m; bit++){
		
		ans.pb('1'); // vou tentar ligar o bit	

		ll at = 0;
		for (int j = 0; j < ans.size(); j++)
			if (ans[j] == '1')
				at += 1ll << (m - j - 1); // Guarda meu # atual 

		for (int i = 0; i < n; i++){
			ok = 1;
			for (int j = 0; j < ans.size(); j++){
				if (ans[j] > v[i][j] and ok){
					ok = 0;
					at--;
				}
				if (ans[j] < v[i][j])
					ok = 0;
			}
		}

		if (at > med) // Sou maior que a média
			ans[ans.size() - 1] = '0';
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