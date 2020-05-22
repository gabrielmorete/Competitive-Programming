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
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
//cout << setprecision(9)<<fixed;

#define dbg(x)  cout << #x << " = " << x << endl
#define all(x)  x.begin(),x.end()

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

const int INF = 0x3f3f3f3f;
const ll llINF = (long long)(1e18) + 100;   
const int MAXN = 5e5 + 10;
const ll mod=1e9+7;

int n, lp[MAXN];
vi d;	

void crivo(){
	d.pb(1);

	for (int i = 2; i <= n; i++){
		if (lp[i] != 0){
			d.pb(i/lp[i]);
			continue;
		}
		lp[i] = i;
		d.pb(1);

		for (int j = 2 * i; j <= n; j += i)
			if (lp[j] == 0)
				lp[j] = i;
	}
}


int32_t main(){
	fastio;
	cin>>n;
	crivo();
	sort(all(d));

	frr(i, n - 1)
		cout<<d[i]<<' ';
	gnl;
}