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
vector< vector<int> >  ans;

int32_t main(){
	fastio;
	cin>>n>>m;
	ans.resize(n + 10);
	fr(i, n + 10)
		ans[i].resize(m + 10);
	
	fr(i, n)
		frr(j, m)
			ans[i][j] = n + i;

	int x;		
	fr(i, n)
		frr(j, m){
			cin>>x;
			if (x % m == j % m){
				int aux = x/m;
				if (j == m)
					aux--;

				if (aux == i)
					ans[0][j]--; // não roda
				else if(aux < n){
					if (aux < i)
						ans[i - aux][j]--;
					if (aux > i)
						ans[n - aux + i][j]--;
				}
			}
		}

	frr(i, n - 1)
		frr(j, m)
			ans[i][j] = min(ans[i][j], ans[i - 1][j]);
	
	ll resp = 0;
	
	frr(j, m)
		resp += (ll) ans[n - 1][j];
	cout<<resp<<endl;				
}