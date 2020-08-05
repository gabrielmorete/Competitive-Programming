#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i,n)     for(int i=0;i<n;i++)
#define frr(i,n)    for(int i=1;i<=n;i++)

#define ms(x,i) memset(x,i,sizeof(x))
#define dbg(x)  cout << #x << " = " << x << endl
#define all(x)  x.begin(),x.end()

#define gnl cout << endl
#define chapa cout << "oi meu chapa" << endl
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
//cout << setprecision(9)<<fixed;

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = (long long)(1e18) + 100;   
const int MAXN = 100100;
const int MAXM = 1001000;
const ll mod=1e9+7;
const int LMAXN = 25;

string s;
vi chk;
int main(){
	fastio;

	for (char a = 'a'; a <= 'z'; a++)
		s.pb(a);
	for (char a = 'A'; a <= 'Z'; a++)
		s.pb(a);
	for (char a = '0'; a <= '9'; a++)
		s.pb(a);
	char mapa[111][111], ans[111][111];
	int t;
	cin>>t;
	while(t--){
		int r, c, k, sum;
		char a;
		cin>>r>>c>>k;

		sum = 0;
		fr(i,r)
			fr(j,c){
				cin>>a;
				mapa[i][j] = a;
				if (a == 'R')
					sum++;
		}
		int aux, aux2;
		aux = sum/k;
		aux2 = sum%k;

		chk.clear();
		fr(i,k){
			chk.pb(aux);
			if (aux2){
				chk[chk.size() - 1]++;
				aux2--;
			}
		}

		int cnt = 0;
		bool ok = 0;
		
		aux = 0;
		for (int i = 0; i < r; i++) {
			if (ok) {
				for (int j = 0; j < c; j++) {
					ans[i][j] = s[cnt];

					if (mapa[i][j] == '.')
						continue;
					
					aux++;
					if (aux == chk[cnt] and cnt < k - 1) {
						cnt++;
						aux = 0;
					}
				}
			}
			else {
				for (int j = c-1; j >= 0; j--) {
					ans[i][j] = s[cnt];
					
					if (mapa[i][j] == '.')
						continue;
					
					aux++;
					if (aux == chk[cnt] and cnt < k - 1) {
						cnt++;
						aux = 0;
					}
				}
			}
			ok = !ok;
		}
		fr(i,r){
			fr(j,c)
				cout<<ans[i][j];
			gnl;
		}

	}
}