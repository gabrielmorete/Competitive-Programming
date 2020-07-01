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
	int n, k, m[350][350];

	cin>>n>>k;
	fr(i, n)
		fr(j, n)
			m[i][j] = 0;

	int aux = k/n;

	int stp = 0;

	while (stp < aux){
		for (int j = 0; j < n - stp; j++)
			m[j][stp + j] = 1;
		for (int j = 0; j < stp; j++)
			m[n - j - 1][stp - j - 1] = 1;	

		stp++;
	}

	aux = k % n;

	for (int j = 0; j < n - stp; j++)
		if (aux > 0){
			m[j][stp + j] = 1;
			aux--;
		}	
	for (int j = 0; j < stp; j++)
		if (aux > 0){
			m[n - j - 1][stp - j - 1] = 1;	
			aux--;
		}
	int ans = k % n? 2 : 0;	
	cout<<ans<<endl;
	fr(i, n){
		fr(j, n)
			cout<<m[i][j];
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