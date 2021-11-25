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

ll k, n;

ll first(){
	ll ini = 1, fim = k, bst = 1;

	while (ini <= fim){
		ll meio = (ini + fim)/2;

		if (meio * (meio + 1) <= 2*n){
			bst = meio;
			ini = meio + 1;
		}
		else
			fim = meio - 1;
	}

	if (bst * (bst + 1) < 2*n)
		bst++;

	return min(bst, k);
}


ll second(){
	n -= (k * (k + 1))/2;

	ll ini = 1, fim = k - 1, bst = 1;

	while (ini <= fim){
		ll meio = (ini + fim)/2;

		if (meio * (k - 1 + k - meio) <= 2*n){
			bst = meio;
			ini = meio + 1;
		}
		else
			fim = meio - 1;
	}

	if (bst * (k - 1 + k - bst) < 2*n)
		bst++;

	return min(bst, k - 1);
}


void solve(){
	cin>>k>>n;

	if (k * (k + 1) < 2*n) // na segunda metade
		cout<< k + second()<<endl;
	else
		cout<<first()<<endl;
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;
	while (T--)
		solve();
}