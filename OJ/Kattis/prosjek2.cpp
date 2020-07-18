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

#define dbg(x)  cout << #x << " = " << x << endl
#define all(x)  x.begin(),x.end()

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

const int INF = 0x3f3f3f3f;
const ll llINF = (long long)(1e18) + 100;   
const int MAXN = 3e5 + 10;
const ll mod = 1e9+7;

int n, k, v[MAXN];
long double soma[MAXN], best[MAXN];

bool test(long double value){
	long double aux;
	for (int i = n; i >= 0; i--){
		aux = i;
		aux *= value;
		aux = soma[i] - aux;
		if (i == n)
			best[i] = aux;
		else
			best[i] = max(aux, best[i + 1]);
		if (i + k <= n and best[i + k] >= aux)
			return true;
	}		

	return false;	
}

int32_t main(){
	fastio;
	cout << setprecision(9)<<fixed;

	cin>>n>>k;

	frr(i, n)
		cin>>v[i];

	frr(i, n)
		soma[i] = soma[i - 1] + v[i];	

	long double ini, fim, meio, ans;
	ini = ans = 1;
	fim = 1e6 + 1;	

	int cnt = 300;

	while (cnt--){
		meio = (ini + fim)/2;

		if (test(meio)){
			ini = meio;
			ans = max(ans, meio);
		}
		else
			fim = meio;
	}

	cout<<ans<<endl;
}