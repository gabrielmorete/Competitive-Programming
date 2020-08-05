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
	int n, v[100];
	cin>>n;

	fr(i, n)
		cin>>v[i];

	int ev, od;
	ev = od = 0;
	fr(i, n){
		if (v[i] % 2)
			od++;
		else
			ev++;			
	}

	if (od % 2 == 0 and ev % 2 == 0){ // PARES
		cout<<"YES"<<endl;
		return;
	}
	
	// par adj;
	bool ok = 0;
	fr(i, n)
		fr(j, n)
			if (abs(v[i] - v[j]) == 1 and v[i] % 2 != v[j] % 2)
				ok = 1;
	if (ok)
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