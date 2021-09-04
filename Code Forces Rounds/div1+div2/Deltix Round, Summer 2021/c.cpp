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

ll n, ans, a[MAXN];

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin>>n;
	fr(i, n)
		cin>>a[i];

	for (int i = 0; i < n; i += 2){ // começos
		ll abre = 0; 
		ll p = i + 1;
		ll resta = a[i];

		while (p < n){
			if (p & 1){ // fecha
				ll aux = a[p];
				if (abre >= aux){
					abre -= aux;
					if (abre == 0) // fez!
						ans++;
				}
				else{
					if (p > i + 1) // fechou + 1 não vazia
						ans++;

					aux -= abre;
					abre = 0;

					ll val = min(resta, aux);
					ans += val;
					resta -= val;
					aux -= val;
					if (aux > 0)
						p = n + 1;
				}
			}
			else{//abre
				abre += a[p];
			}
			p++;
		}
	}	

	cout<<ans<<endl;
}