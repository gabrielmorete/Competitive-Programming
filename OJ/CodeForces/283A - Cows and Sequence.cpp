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
	ll n, sum, a[212345], sz;
	ms(a, 0);


	cin>>n;

	ll ty, k, x;

	sum = 0;
	sz = 1;

	while (n--){
		cin>>ty;
		if (ty == 1){
			cin>>k>>x;
			sum += x*k;
			a[k] -= x;
			a[0] += x;
		}
		else if (ty == 2){
			cin>>k;
			a[sz++] += k;
			a[sz] = -k;
			sum += k;
		}
		else {
			sum += a[sz];
			a[sz - 1] += a[sz];
			a[sz] = 0;
			sz--;
		}
		cout << setprecision(9)<<(double) sum/sz<<endl;
	}
}