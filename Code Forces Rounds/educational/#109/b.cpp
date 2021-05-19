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
	int n, a[55];

	cin>>n;
	frr(i, n)
		cin>>a[i];

	int ok = 1;
	frr(i, n)
		if (a[i] != i)
			ok = 0;

	if (ok == 1){
		cout<<0<<endl;
		return;
	}

	
	if (a[1] == n and a[n] == 1){
		cout<<3<<endl;
		return;
	}

	ok = 0;
	if (a[1] == 1 or a[n] == n)
		ok++;
	cout<<(2 - ok)<<endl;
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;
	while (T--)
		solve();
}