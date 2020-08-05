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
const ll mod = 1e9 + 7;

void solve(){
	int n, m, mapa[55][55], lin[55], col[55];
	fill(lin, lin + 55, 0);
	fill(col, col + 55, 0);

	cin>>n>>m;
	fr(i, n){
		fr(j, m)
			cin>>mapa[i][j];
	}

	// lin
	fr(i, n)
		fr(j, m)
			lin[i] += mapa[i][j];
	// col
	fr(j, m)
		fr(i, n)
			col[j] += mapa[i][j];
	
	int ans = 0;				
	fr(i, n)
		fr(j, m)
			if (lin[i] == 0 and col[j] == 0){
				lin[i]++;
				col[j]++;
				ans++;
			}

	if (ans % 2)
		cout<<"Ashish"<<endl;		
	else
		cout<<"Vivek"<<endl;
}

int32_t main(){
	fastio;
	int T;
	cin>>T;
	while (T--){
		solve();
	}
}