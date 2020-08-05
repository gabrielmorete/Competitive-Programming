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

int n, m;
string v[11], ans;

int comp(int j){
	int val = 0;
	fr(i, m)
		if (ans[i] != v[j][i])
			val++;
	return val;	
}

void solve(){
	cin>>n>>m;
	fr(i, n)
		cin>>v[i];

	bool ok = 1;	
	for (int p = 0; p < m; p++){ // Posição que to mudando
		ans = v[0];
		for (char c = 'a'; c <= 'z'; c++){ // Caractere que estou tentando
			ans[p] = c;
			
			ok = 1;
			for (int i = 0; i < n; i++)
				if (comp(i) > 1)
					ok = 0;
			
			if (ok){
				cout<<ans<<endl;
				return;
			}	

		}
	}

	cout<<-1<<endl;
}

int32_t main(){
	fastio;
	int T;
	cin>>T;
	while (T--)
		solve();
}