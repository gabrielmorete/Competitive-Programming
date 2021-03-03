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
	int n, U, L, R, D;

	cin>>n>>U>>R>>D>>L;

	for (int i = 0; i < 16; i++){
		int l = L, u = U, d = D, r = R;

		if (i&1){
			l--;
			u--;
		}
		if (i&2){
			u--;
			r--;
		}
		if (i&4){
			d--;
			l--;
		}
		if (i&8){
			d--;
			r--;
		}

		if (r >= 0 and l >= 0 and u >= 0 and d >= 0 and r < n - 1 and l < n - 1 and u < n - 1 and d < n - 1){
			cout<<"yes"<<endl;
			return;
		}
	}	

	cout<<"no"<<endl;
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;
	while (T--)
		solve();
}