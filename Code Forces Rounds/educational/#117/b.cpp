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

int ans[300];

void solve(){
	int n, a, d;
	cin>>n>>a>>d;

	ans[0] = a;
	ans[n - 1] = d;

	int p = n;
	for (int i = 1; i < n - 1; i++){
		while (p == a or p == d)
			p--;
		ans[i] = p;
		p--;
	}


	int val = ans[0];
	fr(i, n/2)
		val = min(val, ans[i]);

	if (val != a){
		cout<<-1<<endl;
		return;
	}	

	val = ans[n/2];
	fr(i, n/2)
		val = max(val, ans[n/2 + i]);

	if (val != d){
		cout<<-1<<endl;
		return;
	}	

	fr(i, n)
		cout<<ans[i]<<' ';
	gnl;
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;
	while (T--)
		solve();
}