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
#define all(x)  x.begin(),x.end()

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

const int INF = 0x3f3f3f3f;
const ll llINF = (long long)(1e18) + 100;   
const int MAXN = 1e5 + 10;

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int T;
	ll x1, y1, z1, x2, y2, z2, ans, aux;

	cin>>T;

	while (T--){
		ans = 0;
		cin>>x1>>y1>>z1;
		cin>>x2>>y2>>z2;

		if (min(z1, y2) > 0){
			ans += min(z1, y2) * 2;
			aux = min(z1, y2);
			z1 -= aux; y2 -= aux;
		}

		if (x2 + y2 > 0 and y1 > 0){ // zerar y1
			aux = min(y1, x2);
			y1 -= aux; x2 -= aux;
			aux = min(y1, y2);
			y1 -= aux; y2 -= aux;
		}

		if (x1 + z1 > 0 and z2 > 0){
			aux = min(x1, z2);
			x1 -= aux; z2 -= aux;
			aux = min(z1, z2);
			z1 -= aux; z2 -= aux;
		}

		if (y1 > 0 and z2 > 0){
			aux = min(y1, z2);
			ans -= 2 * aux;			
		}
		
		cout<<ans<<endl;
	}
}