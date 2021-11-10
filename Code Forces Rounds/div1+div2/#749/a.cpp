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

void solve(){
	int n, a[110], sum = 0;

	cin>>n;
	fr(i, n){
		cin>>a[i];
		sum += a[i];
	}

	bool ok = 1;
	for (int v = 2; v < sum; v++)
		if (sum % v == 0)
			ok = 0;

	if (!ok){
		cout<<n<<endl;
		frr(i, n)
			cout<<i<<' ';
		gnl;	
	}	
	else{
		int p = 1;
		fr(i, n)
			if (a[i] % 2)
				p = i;

		cout<<n-1<<endl;
		frr(i, n)
			if (i != p + 1)
				cout<<i<<' ';
		gnl;
	}

}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;
	while (T--)
		solve();
}	