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
const int MAXN = 4e5 + 10;

int n, k[MAXN], h[MAXN];

void solve(){
	cin>>n;
	frr(i, n)
		cin>>k[i];
	
	frr(i, n)
		cin>>h[i];

	map<int, int> cmp;
	frr(i, n)
		cmp[k[i] - h[i] + 1] = max<int>(cmp[k[i] - h[i] + 1], k[i]);
	
	vii event;
	for (auto e : cmp)
		event.pb({e.fst, e.snd});
	n = event.size();
	
	ll ans = 0;
	int p = 0;
	while (p < n){
		int q = p + 1;
		int end = event[p].snd;

		while (q < n and (event[q].fst <= end or event[q].snd <= end)){
			end = max(end, event[q].snd);
			q++;
		}

		ll dlt = end - event[p].fst + 1;

		ans += (dlt * (dlt + 1))/2;
		p = q;
	}

	cout<<ans<<endl;
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;
	while (T--)
		solve();
}