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
const int MAXN = 1e6 + 10;

int n, k, a[MAXN], nxt[MAXN], dif, frq[MAXN], lst[MAXN];


vector<int> crd;

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin>>n>>k;

	crd.resize(n);

	frr(i, n){
		cin>>a[i];
		crd[i - 1] = a[i];
	}

	sort(all(crd));

	frr(i, n)
		a[i] = (int)(lower_bound(all(crd), a[i]) - crd.begin());

	fr(i, n)
		lst[i] = n + 1;

	for (int i = n; i > 0; i--){
		nxt[i] = lst[a[i]];
		lst[a[i]] = i;
	}	


	ll ans = 0;

	int r = 0, d = 0;

	for (int l = 1; l <= n; l++){
		if (dif < k){
			while (r + 1 <= n and dif < k){
				r++;
				if (frq[a[r]] == 0)
					dif++;
				frq[a[r]]++;
			}

			d = r; // limit point
		}

		while (r + 1 <= n and frq[a[r + 1]] > 0){ // wont increase dif
			r++;
			frq[a[r]]++;
		}

		if (dif == k)
			ans += r - d + 1;

		frq[a[l]]--;
		if (frq[a[l]] == 0)
			dif--;
		else
			d = max(d, nxt[l]);
	}

	cout<<ans<<endl;
}
