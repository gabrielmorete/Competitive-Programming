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


const ll llINF = (long long)(1e18) + 100;   
const int MAXN = 1e5 + 10;
const int INF = 40*MAXN;
int v[MAXN];

int32_t main(){
	fastio;
	int n;
	cin>>n;
	fr(i, n)
		cin>>v[i];

	int ans, cur, val;
	ans = 0;
	fr(mx, 31){
		cur = 0;
		fr(i, n){
			val = v[i] > mx? -INF : v[i];
			cur += val;

			ans = max(ans, cur - mx);
			cur = max(cur, 0);
		}
	}

	cout<<ans<<endl;
}