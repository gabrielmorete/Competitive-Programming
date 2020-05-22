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

int lp[MAXN];
vi pr;

void crivo(){
	for (int i = 2; i <= MAXN; i++) {
	    if (lp[i] == 0) {
	        lp[i] = i;
	        pr.pb(i);
	    }
	    for (int j=0; j<(int)pr.size() && pr[j]<=lp[i] && i*pr[j] <= MAXN; ++j)
	        lp[i * pr[j]] = pr[j];
	}
}
void solve(){
	int n;
	cin>>n;
	
	int mn, dst;
	mn = dst = 0;
	vi v;		

	int lst = 1;
	for (auto x : pr){
		while (n % x == 0){
			v.pb(x);
			mn++;
			if (lst != x){
				lst = x;
				dst++;
			}
			n /= x;
		}
	}

	if (n != 1){
		v.pb(n);
		mn++;
		dst++;
	}


	if (mn < 3){
		cout<<"NO"<<endl;
		return;
	}

	int a, b, c;
	a = b = c = 1;
	a = v[0];

	if (v[0] == v[1]){

		for (int i = 1; i <= 2; i++)
			b *= v[i];

		for (int i = 3; i < mn; i++)
			c *= v[i];
	}
	else{
		b *= v[1];

		for (int i = 2; i < mn; i++)
			c *= v[i];
	}

	if (a == b or b == c or a == c or a == 1 or b == 1 or c == 1)
		cout<<"NO"<<endl;
	else
		cout<<"YES"<<endl<<a<<' '<<b<<' '<<c<<endl;
}

int32_t main(){
	fastio;
	crivo();
	int T;
	cin>>T;
	while (T--)
		solve();
}