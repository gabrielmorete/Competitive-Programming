#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fst first
#define snd second

#define fr(i,n)     for (int i = 0; i < n; i++)
#define frr(i,n)    for (int i = 1; i <= n; i++)

// #define endl '\n'
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

ll x;

bool rec(ll a, ll b){
	if (a < b) swap(a, b);
	
	while (a >= x){
		if (a == x or b == x) 
			return true;
		if (b <= 0) 
			return false;

		ll mul = (a - x)/b;	
		if (mul == 0) mul = 1;

		a = a - mul*b;

		if (a < b) swap(a, b);
	}

	return false;
}


void solve(){
	ll a, b;

	cin>>a>>b>>x;

	if (rec(a, b))
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;
	while (T--)
		solve();
}