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
const int MAXN = 5e5 + 10;

int n;
int hist[MAXN]; // hist[x] = qual o maior l tal que f(l, r)  = x
string s;

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin>>n>>s;

	ll ans = 0, cur = 0;

	memset(hist, -1, sizeof hist); // tenho que contar a posição zero

	for (int i = 0; i < n; i++){
		if (s[i] == '0'){
			ans += cur;
			continue;
		}

		ll l = i, r = i;
		while (r < n - 1 and s[r + 1] == '1')
			r++;

		for (ll x = 1; x <= r - l + 1; x++){ // tamanho do intervalo
			cur += (l - 1 + x) - hist[x]; // numero de caras que vão auentar o histograma
			ans += cur;
			hist[x] = r - x + 1;// novo maior l tal que f(l, r)  = x
		}
		i = r;
	}

	cout<<ans<<endl;
}