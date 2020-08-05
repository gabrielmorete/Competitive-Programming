#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define mp make_pair
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
typedef vector<ll> vll;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = (long long)(1e18) + 100;   
const int MAXN = 100100;
const int MAXM = 1001000;
const ll mod=1e9+7;
const int LMAXN = 25;

int main(){
	fastio;
	int t, n, m, sum, x;
	vii v;

	cin>>t;
	while(t--){
		cin>>n>>m;
		
		v.clear();
		sum = 0;
		fr(i,n){
			cin>>x;
			sum += 2*x;
			v.pb({x, i + 1});
		}
		if(n == 2 or m < n){
			cout<<-1<<endl;
			continue;
		}
		sort(all(v));
		int a, b, c, d;
		a = v[0].fst;
		b = v[0].snd;
		c = v[1].fst;
		d = v[1].snd;

		cout<<sum + (m-n)*(a + c)<<endl;
		frr(i,n - 1)
			cout<<i<<' '<<i+1<<endl;
		cout<<n<<' '<<1<<endl;
		fr(i,m-n)
			cout<<b<<' '<<d<<endl;

	}
}