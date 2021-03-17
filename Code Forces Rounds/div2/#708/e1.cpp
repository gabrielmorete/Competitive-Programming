#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fst first
#define snd second

#define fr(i,n)     for (int i = 0; i < n; i++)
#define frr(i,n)    for (int i = 1; i <= n; i++)

// #define endl '\n'
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
const int MAXN = 1e7 + 10;

int lp[MAXN + 100];
vector<int> pr;

void crivo(){

	for (ll i = 2; i < MAXN; ++i) {
	    if (lp[i] == 0) {
	        lp[i] = i;
	        pr.push_back (i);
	    }
	    for (ll j = 0; j<(ll)pr.size() && pr[j] <= lp[i] && ((ll)i* ((ll) pr[j]))< ((ll) MAXN); ++j)
	        lp[i * pr[j]] = pr[j];
	}
}

int n, k, v[212345];
map<int, int> freq;
void solve(){
	cin>>n>>k;

	fr(i, n)
		cin>>v[i];

	fr(i, n){
		int aux = v[i];

		int nv = 1;
		while (aux > 1){
			int pr = lp[aux];
			int frq = 0;

			while (lp[aux] == pr){
				frq++;
				aux /= lp[aux];
			}

			if (frq % 2)
				nv *= pr;
		}

		v[i] = nv;
	}	
	int p = 0;

	int ans = 0;

	while (p < n){
		int q = p;
		freq[v[p]] = 1;

		while (q + 1 < n and freq[v[q + 1]] == 0){
			q++;
			freq[v[q]] = 1;
		}

		// cout<<p<<' '<<q<<endl;

		ans++;
		freq.clear();
		p = q + 1;
	}
	cout<<ans<<endl;
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	crivo();
	int T;
	cin>>T;
	while (T--)
		solve();

}