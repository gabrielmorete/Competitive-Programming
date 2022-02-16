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

ll n, m;
vector<vector<ll>> p;

ll deg[MAXN];

bool test(ll val){
	fr(i, m)
		deg[i] = 0;

	fr(j, n){
		bool ok = 0;

		fr(i, m)
			if (p[i][j] >= val){
				ok = 1;
				deg[i]++;
			}
		if (!ok)
			return false;	
	}	
	// tem ao menos 1
	bool ok = 0;
	fr(i, m)
		if (deg[i] > 1)
			ok = 1; // economizei 1 loja

	return ok;
}



void solve(){
	cin>>m>>n;

	p.resize(m);

	fr(i, m){
		p[i].resize(n);

		fr(j, n)
			cin>>p[i][j];
	}


	ll ini = 0, fim = INF, bst = 0;

	while (ini <= fim){
		ll meio = (ini + fim)/2;
	
		if (test(meio)){
			bst = meio;
			ini = meio + 1;
		}
		else{
			fim = meio - 1;
		}
	}

	cout<<bst<<endl;
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;
	while (T--)
		solve();
}