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

int n, freq[40];

void solve(){
	fr(i, 40)
		freq[i] = 0;	

	cin>>n;

	int x;
	fr(i, n){
		cin>>x;
		fr(j, 30)
			if (x&(1<<j))
				freq[j]++;
	}

	vi ans;

	frr(i, n){
		bool ok = 1;
		fr(j, 30)
			if (freq[j] % i != 0)
				ok = 0;
		if (ok)
			ans.pb(i);	
	}

	for (auto x :ans)
		cout<<x<<' ';
		gnl;			
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;
	while (T--)
		solve();
}