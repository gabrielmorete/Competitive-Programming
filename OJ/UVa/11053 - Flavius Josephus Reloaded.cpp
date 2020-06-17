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

set<int> q;

ll sq(ll x){ return x * x;}

int32_t main(){
	fastio;

	ll n, a, b;
	ll ans, x;
	cin>>n;
	while (n){
		cin>>a>>b;

		q.clear();
		ans = x = 0;

		while (!q.count(x)){
			q.insert(x);
			x = ((a *(sq(x) % n) % n) + b) % n;
		}

		while (q.count(x)){
			ans++;
			q.erase(x);
			x = ((a *(sq(x) % n) % n) + b) % n;	
		}
		cout<<n - ans<<endl;
		cin>>n;
	}
}