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

ll n, x, a[MAXN], sum[MAXN];

void solve(){
	cin>>n;
	frr(i, n)
		cin>>a[i];

	cin>>x;	

	ll ans = (n + 1) / 2;	

	frr(i, n)
		sum[i] = sum[i - 1] + a[i];

	a[n + 1] = -INF;	

	ll lst = 0, ini = 1, dsc = 0;

	vi fora;

	for (ll i = 1; i <= n; i++){
		ll sz = i - ini + 1;

		if (sz == 1){ // começando
			if (a[i] < x)
				lst = i; // ultimo menor
			continue;	
		}

		if (sz * x > sum[i] - sum[ini - 1]){// problema, só acontece se tem < x
			if (a[i] < x){
				ini = i + 1;
				fora.pb(i);
				dsc++;
			}
			else{
				dsc++;

				if (a[i] + a[i + 1] >= 2*x){
					fora.pb(lst);
					ini = lst + 1;
				}
				else
					ini = i + 1;
			}
		}
		else{
			if (a[i] < x){
				if (a[i - 1] + a[i] < 2 * x){ // funciona pois sz > 1
					dsc++;
					fora.pb(i);
					ini = i + 1;
				}
				else if (ini <= lst and sum[i] - sum[lst - 1] < x * (i - lst + 1)){
					dsc++;
					fora.pb(i);
					ini = i + 1;
				}

				lst = i;
			}
			else{
				if (ini <= lst and sum[i] - sum[lst - 1] < x * (i - lst + 1)){
					dsc++;
					if (a[i] + a[i + 1] >= 2*x){
						fora.pb(lst);
						ini = lst + 1;
					}
					else
						ini = i + 1;				}
			}
		}
	}

	ans = max(ans, n - dsc);

	cout<<ans<<endl;
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;

	while (T--)
		solve();
}