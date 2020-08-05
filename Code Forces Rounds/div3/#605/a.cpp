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

void solve(){
	ll v[3];
	cin>>v[0]>>v[1]>>v[2];
	sort(v, v + 3);

	ll a, b;
	a = v[1] - v[0];
	b = v[2] - v[1];

	if (a == 0 and b == 0){
		cout<<0<<endl;
		return;
	}
	else if (a == 0 and b != 0){
		b--;
		if (b > 0)
			b--;
		cout<<2*(a + b)<<endl;
		return;
	}
	if (a != 0 and b == 0){
		a--;
		if (a > 0)
			a--;
		cout<<2*(a + b)<<endl;
		return;	
	}
	else{
		a--;
		b--;
		cout<<2*(a + b)<<endl;
		return;
	}
}

int32_t main(){
	fastio;
	int T;
	cin>>T;
	while (T--)
		solve();
}