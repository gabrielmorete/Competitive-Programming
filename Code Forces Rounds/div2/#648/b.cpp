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
const ll mod = 1e9 + 7;

void solve(){
	int n, v[555];
	bool zr, um;
	cin>>n;
	fr(i, n)
		cin>>v[i];
	
	zr = um = 0;
	int x;
	fr(i, n){
		cin>>x;
		if (x == 0)
			zr = 1;
		else
			um = 1;
	}

	bool ok = 1;
	fr(i, n - 1){
		if (v[i] > v[i + 1])
			ok = 0;
	}

	if (ok){
		cout<<"yes"<<endl;
		return;
	}

	if (zr and um)
		cout<<"yes"<<endl;
	else
		cout<<"no"<<endl;

}

int32_t main(){
	fastio;
	int T;
	cin>>T;
	while (T--){
		solve();
	}
}