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
const int MAXN = 1e5;

ll sq(ll x){
	ll ans = 1;
	fr(i, 10)
		ans *= x;
	return ans;
}

int32_t main(){
	fastio;
	ll k, v[12];
	cin>>k;

	ll x = 1;

	while (sq(x) < k)
		x++;

	string s = "codeforces";

	fr(i, s.size())
		v[i] = x;

	ll aux = sq(x);

	fr(i, s.size()){
		if ((aux * (x - 1ll))/x >= k){
			v[i] = (x - 1ll);

			aux /= x;
			aux *= (x - 1ll);
		}
	}	


	fr(j, s.size()){
		fr(i, v[j])
			cout<<s[j];
	}
	gnl;
}