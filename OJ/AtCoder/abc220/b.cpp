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

ll to(string s, ll k){
	ll ans = 0, pwr = 1;
	reverse(all(s));

	for (auto x : s){
		ll aux = x - '0';
		ans += aux * pwr;
		pwr *= k;
	}

	return ans;
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int k;
	string s;

	cin>>k;

	cin>>s;

	ll a = to(s, k);

	cin>>s;
	ll b = to(s, k);

	cout<<a * b<<endl;
}