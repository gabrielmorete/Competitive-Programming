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

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	ll n, k;
	cin>>n>>k;

	vector<ll> a;
	a.resize(n);
	fr(i, n)
		cin>>a[i];

	ll ini = 0, bst = 0, fim = llINF/k;
	
	while (ini <= fim){
		ll meio = (ini + fim)/2;
		ll sum = 0;
		for (auto x : a)
			sum += min(x, meio);
		if (sum >= meio * k){
			bst = meio;
			ini = meio + 1;
		}
		else
			fim = meio - 1;
	}		

	cout<<bst<<endl;
}