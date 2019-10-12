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
	int a, b, c, d;

	cin>>a>>b>>c>>d;

	int ma, mc;
	ma = __gcd( a, b);
	mc = __gcd( c, d);
	a /= ma; b /= ma;
	c /= mc; d /= mc;

	if (a == c and b == d){
		cout<<"0/1"<<endl;
		return 0;
	}
	if ((long double) a/b < (long double) c/d){
		cout<<(b*c - a*d)/__gcd( b*c - a*d, b*c)<<'/'<<b*c/__gcd( b*c - a*d, b*c)<<endl;

	}
	else{
		cout<<(a*d - b*c)/__gcd( a*d - b*c, a*d)<<'/'<<a*d/__gcd( a*d - b*c, a*d)<<endl;

	}

}