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

#define dbg(x)  cout << #x << " = " << x << endl
#define all(x)  x.begin(), x.end()

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

const int INF = 0x3f3f3f3f;
const ll llINF = (long long)(1e18) + 100;   
const int MAXN = 1e5 + 10;

ll n, a[MAXN];

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin>>n;
	fr(i, n)
		cin>>a[i];

	sort(a, a + n);

	ll sum = 0;
	fr(i, n)
		sum += a[i];
	

	long double ans = sum;

	ll coef = -n;

	long double lst = 0;

	for (int i = 0; i < n; i++){
		int p = i;
		while (p < n - 1 and a[p + 1] == a[i])
			p++;

		ll sz = p - i + 1;
		coef += 2*sz;
		sum -= a[i] * sz;

		long double now = a[i]/2.0;

		long double aux = now * coef + sum;

		ans = min(ans, aux);

		lst = now;
		i = p;
	}


	cout<<setprecision(9)<<fixed;
	cout<<(ans/n)<<endl;
}