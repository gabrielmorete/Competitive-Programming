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
	int k;

	cin>>k;

	if (k == 100){
		cout<<1<<endl;
		return;
	}

	int e = 1;
	int w = 0;

	fr(i, 100){
		if ((e * 100 == (e + w) * k) and (w * 100 == (e + w)*(100 - k))){
			cout<<(e + w)<<endl;
			return;
		}

		if (e * 100 < (e + w) * k)
			e++;
		else
			w++;
	}
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;
	while (T--)
		solve();
}