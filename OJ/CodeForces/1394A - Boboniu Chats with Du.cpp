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

ll n, d, m, a[MAXN];
vector<ll> small, big;

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin>>n>>d>>m;
	
	frr(i, n)
		cin>>a[i];

	sort(a + 1, a + n + 1);

	for (int i = n; i > 0; i--)
		if (a[i] > m)
			big.pb(a[i]);
		else
			small.pb(a[i]);

	ll ans = 0, sbig = 0;
	for (auto x : big)
		sbig += x;
	int pbig = big.size();

	ll ssma = 0;
	for (int i = 0; i <= small.size(); i++){
		if (i > 0)
			ssma += small[i - 1];

		int q = n - i;
		int nb = (q + d)/(d + 1); // numero de caras grandes

		while (pbig > nb){
			sbig -= big[pbig - 1];
			pbig--;
		}

		ans = max(ans, sbig + ssma);
	}

	cout<<ans<<endl;
}