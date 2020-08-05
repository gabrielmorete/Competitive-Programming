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

int m[55][55];
void solve(){
	int n;
	cin>>n;
	fr(i, n + 1){
		m[i][n] = 1;
		m[n][i] = 1;
	}

	string s;
	fr(i, n){
		cin>>s;
		fr(j, n)
			m[i][j] = s[j] - '0';
	}

	bool ok = 1;

	fr(i, n)
		fr(j, n)
			if (m[i][j] == 1){
				if (m[i + 1][j] == 0 and m[i][j + 1] == 0)
					ok = 0;
			}
	if (ok)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
}

int32_t main(){
	fastio;
	int T;
	cin>>T;
	while (T--)
		solve();
}