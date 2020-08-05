#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fst first
#define snd second

#define fr(i,n)     for(int i=0;i<n;i++)
#define frr(i,n)    for(int i=1;i<=n;i++)

#define ms(x,i) memset(x,i,sizeof(x))
#define dbg(x)  cout << #x << " = " << x << endl
#define all(x)  x.begin(),x.end()

#define gnl cout << endl
#define chapa cout << "oi meu chapa" << endl
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
//cout << setprecision(9)<<fixed;

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = (long long)(1e18) + 100;   
const int MAXN = 1e5 + 10;
const ll mod=1e9+7;

void solve(){
	int n, v[1010];
	cin>>n;
	fr(i, n)
		cin>>v[i];
	

	int lst = 0;
	
	int a, b, p, q;
	p = 0;
	q = n - 1;

	a = b = 0;
	
	int ans = 0;
	while (p <= q){
		int aux = 0;
		ans++;

		while (aux <= lst and p <= q){
			aux += v[p];
			p++;
		}
		a += aux;
		lst = aux;

		if (p <= q)
			ans++;

		aux = 0;
		while (aux <= lst and p <= q){
			aux += v[q];
			q--;
		}
		b += aux;
		lst = aux;
		//ans++;
	}	
	cout<<ans<<' '<<a<<' '<<b<<endl;
}

int32_t main(){
	fastio;
	int T;
	cin>>T;
	while (T--)
		solve();
}