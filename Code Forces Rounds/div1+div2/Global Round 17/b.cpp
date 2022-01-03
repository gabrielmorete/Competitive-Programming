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
	fr(i, n)
		cin>>a[i];

	int p = 0, q = n - 1;
	
	vi cand;

	while (p <= q){
		if (a[p] != a[q]){
			cand.pb(a[p]);
			cand.pb(a[q]);
			break;
		}
		p++;
		q--;
	}

	if (cand.size() == 0){
		cout<<"YES"<<endl;
		return;
	}

	bool ans = 0;
	fr(j, 2){
		vi v;
		fr(i, n)
			if (a[i] != cand[j])
				v.pb(a[i]);

		p = 0, q = (int)(v.size()) - 1;
		bool aux = 1;
		while (p <= q){
				if (v[p] != v[q]){
					aux = 0;
				}
			p++;
			q--;
		}
		ans |= aux;	
	}		

	if (ans)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;
	while (T--)
		solve();
}