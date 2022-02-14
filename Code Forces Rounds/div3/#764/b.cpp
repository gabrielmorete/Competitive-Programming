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
const int MAXN = 4e5 + 10;

bool tenta(ll a, ll b, ll c){
	ll r = c - b;
	
	ll m = (b - r)/a;

	if (m > 0 and a * m == (b - r))
		return true;
	return false;
}

bool tentb(ll a, ll b, ll c){
	ll r = c - a;

	if (r & 1)
		return false;

	r /= 2;

	ll m = (a + r)/b;

	if (m > 0 and m * b == (a + r))
		return true;

	return false;
}

bool tentc(ll a, ll b, ll c){
	ll r = b - a;

	ll m = (b + r)/c;

	if (m > 0 and m * c == (b + r))
		return true;
	return false;
}

void solve(){
	ll a, b, c;
	cin>>a>>b>>c;

	//para o a
	if(tenta(a, b, c) or tentb(a, b, c) or tentc(a, b, c))
		cout<<"Yes"<<endl;
	else
		cout<<"No"<<endl;
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;
	while (T--)
		solve();
}