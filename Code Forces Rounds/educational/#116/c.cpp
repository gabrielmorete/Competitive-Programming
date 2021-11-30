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

ll n, k, a[19], dst[19], pwr[19];

void solve(){
	cin>>n>>k;
	
	fr(i, 19)
		a[i] = 0;

	fr(i, n){
		int x;
		cin>>x;
		a[x] = 1;
	}	

	fr(i, 19){
		if (a[i] == 1)
			dst[i] = 0;
		else
			dst[i] = dst[i - 1] + 1;
	}


	ll val = 0;
	for (int i = 0; i < 19; i++){
		for (int j = 0; j < 9; j++){
			val += pwr[i];
			k -= pwr[dst[i]];

			if (k < 0){
				for (int l = i - 1; l >= 0; l--){
					while (k + pwr[dst[l]] < 0){
						val -= pwr[l];
						k += pwr[dst[l]];
					}
				}

				cout<<val<<endl;
				return;
			}
		}
	}
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	pwr[0] = 1;
	frr(i, 18)
		pwr[i] = pwr[i - 1] * 10ll;	

	int T;
	cin>>T;
	while (T--)
		solve();
}