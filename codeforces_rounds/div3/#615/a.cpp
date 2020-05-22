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
	int v[3], n;
	cin>>v[0]>>v[1]>>v[2]>>n;
	sort(v, v + 3);

	if (n >= v[2] - v[0]){
		n -= v[2] - v[0];
		v[0] = v[2];
	}
	if (n >= v[2] - v[1]){
		n -= v[2] - v[1]; 
		v[1] = v[2];
	}
	if (v[0] == v[1] and v[1] == v[2] and n % 3 == 0)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
}

int32_t main(){
	fastio;
	int T;
	cin>>T;
	while (T--)
		solve();
}