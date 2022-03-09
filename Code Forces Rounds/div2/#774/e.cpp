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
const int MAXN = 2e7 + 10;

ll n, m, ans, inc[25];
bool perfect[MAXN], is_in[MAXN];

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin>>n>>m;

	ans = 1;

	ll now = 0;
	for (int j = 1; j < 20; j++){
		for (int k = 1; k <= m; k++)
			if (!is_in[j * k]){
				is_in[j * k] = 1;
				now++;
			}
		inc[j] = now;	
	}

	for (ll i = 2; i <= n; i++){
		if (perfect[i] == 0){
			
			ll pwr = i;
			for (int j = 1; pwr <= n; pwr *= i, j++){
				ans += inc[j] - inc[j - 1];
				perfect[pwr] = 1;	
			}
		}
	}

	cout<<ans<<endl;
}