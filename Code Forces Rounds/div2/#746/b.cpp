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
const int MAXN = 2e5 + 10;

int n, x, a[MAXN], b[MAXN];

void solve(){
	cin>>n>>x;
	fr(i, n)
		cin>>a[i];

	bool ok = 1;
	fr(i, n - 1)
		if (a[i + 1] < a[i])
			ok = 0;

	if (ok or x == 1){
		cout<<"yes"<<endl;
		return;
	}

	fr(i, n)
		b[i] = a[i];

	sort(b, b + n);
	
	ok = 1;
	frr(i, n)
		if (b[i - 1] != a[i - 1]){
			if ((i - 1) < x and (n - i) < x)
				ok = 0;
		}

	if (!ok)
		cout<<"no"<<endl;
	else
		cout<<"yes"<<endl;	
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;
	while (T--)
		solve();
}