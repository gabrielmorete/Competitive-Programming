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

int n, a[MAXN];

void solve(){
	cin>>n;
	frr(i, n)
		cin>>a[i];

	int pos = 1;
	frr(i, n)
		if (a[i] < a[pos])
			pos = i;

	cout<<n - 1<<endl;
	frr(i, n)
		if (i != pos){
			int val = a[pos];
			if (i % 2 != pos % 2)
				val++;

			cout<<i<<' '<<pos<<' '<<val<<' '<<a[pos]<<endl;
		}			
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;
	while (T--)
		solve();
}