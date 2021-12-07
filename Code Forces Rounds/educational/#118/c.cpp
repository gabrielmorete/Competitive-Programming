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

ll n, a[200], h;

bool test(ll val){
	ll hp = h;

	fr(i, n - 1){
		ll aux = min(val, a[i + 1] - a[i]);
		hp -= aux;
		if (hp <= 0)
			return true;
	}

	return hp <= val;
}

void solve(){
	cin>>n>>h;

	fr(i, n)
		cin>>a[i];

	ll ini = 1, fim = llINF, bst = llINF;	

	while (ini <= fim){
		ll meio = (ini + fim)/2;

		if (test(meio)){
			bst = meio;
			fim = meio - 1;
		}
		else
			ini = meio + 1;
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