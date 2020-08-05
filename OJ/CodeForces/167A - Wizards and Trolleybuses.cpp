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
const long double eps = 0.000001;

int n, d, a, t, v;
long double tme[112345], dd, aa, tt, vv;
int main(){
	scanf("%d %d %d", &n, &a, &d);
	dd = d;
	aa = a;

	fr(i,n){
		scanf("%d %d", &t, &v);
		tt = t;
		vv = v;
		if ( (sqrt(2*aa*dd) - vv) <= eps){
			tme[i] = sqrt((2.0*dd)/aa) + tt;
		}
		else {
			long double t1, t2, s1, s2;
			t1 = vv/aa;
			s1 = (a*t1*t1)/2.0;
			s2 = dd - s1;
			t2 = s2/vv;
			tme[i] = tt + t1 + t2;
		}
	}
	long double mx = 0;

	fr(i,n){
		if ((mx - tme[i]) <= eps) {
			printf("%.10Lf\n", tme[i]);
			mx = tme[i];
		}	
		else
			printf("%.10Lf\n", mx);
	}


}