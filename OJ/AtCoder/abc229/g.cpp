#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fst first
#define snd second

#define fr(i,n)     for (int i = 0; i < n; i++)
#define frr(i,n)    for (int i = 1; i <= n; i++)

// #define endl '\n'
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

vi v;

ll n, k, sum[MAXN];

bool test(ll val){ // igualar um vetor ordenado para 1 elemento, joga pra mediana
	for (int i = 0; i + val - 1 < n; i++){
		ll x = v[i + val/2];
		ll cnt = val/2 + 1;
		ll cstl = x * cnt - sum[i + val/2];

		if (i > 0)
			cstl += sum[i - 1];

		ll cstr = sum[i + val - 1] - sum[i + val/2];
		cstr -= (val - cnt) * x;

		if (cstl + cstr <= k)
			return true;
	}
	return false;
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string s;

	cin>>s>>k;

	fr(i, s.size())
		if (s[i] == 'Y')
			v.pb(i);

	n = v.size();

	if (n == 0){
		cout<<0<<endl;
		return 0;
	}

	fr(i, n)
		v[i] -= i;


	sum[0] = v[0];
	frr(i, n - 1)
		sum[i] = sum[i - 1] + (ll)v[i];
	
	ll ini = 1, bst = 0, fim = n;

	while (ini <= fim){
		ll meio = (ini + fim)/2;

		if (test(meio)){
			bst = meio;
			ini = meio + 1;		
		}
		else
			fim = meio - 1;
	}

	cout<<bst<<endl;	
}