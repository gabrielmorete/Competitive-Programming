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

ll memo[(1<<20) + 10]; // desarranjos

void pd(){ // o número de bits ligados é a posição que vamos preencher

	for (int msk = (1<<20) - 1; msk >= 0; msk--){
		
		int on = __builtin_popcount(msk);
		memo[msk] = 0;
		if (on == 20) // todos estão em suas posições
			memo[msk] = 1;
		else{
			for (int i = 0; i < 20; i++){
				if (i != on and !(msk & (1<<i))) // não é a posição orginal e não foi usado 
					memo[msk] += memo[msk | (1<<i)];
			}
		}
	}

	memo[1] = 0; // não há desarranjo de 1 elemento
}

int shift;
vi ans;

void getans(int n, ll k){
	vi auxa;
	int msk = 0;
	for (int i = 20; i > n; i--) // fixamos os primeiros numeros como na função anterior
		msk |= (1 <<(20 - i));

	for (int i = 20 - n; i < 20; i++){ // posição
		for (int j = 20 - n; j < 20; j++){ // numero
			if (i == j)
				continue;
			if (msk & (1<<j)) // j já está
				continue;
			
			msk |= (1<<j); // coloca j

			if (memo[msk] >= k){ // estou dentro do intervalo de desarranjos
				auxa.pb(j);
				break;
			}
			else{
				k -= memo[msk];
				msk -= (1<<j); // tira j
			}
		}
	}

	int mn = *min_element(all(auxa)); // menor elemento para corrigir indexação
	for (auto l : auxa)
		ans.pb(l - mn + shift + 1);
}

void solve(){
	ans.clear();
	ll n, k;
	n = k = 0;
	
	cin>>n>>k;

	shift = 0;

	if (n <= 20)
		getans(n, k);
	else{
		for (int i = 1; i <= n - 20; i += 2){
			ans.pb(i + 1);
			ans.pb(i);

		}
		shift = ans.size();
		getans(n - ans.size(), k);
	}

	for (auto x : ans)
		cout<<x<<' ';
	gnl;
}


int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	pd();

	int T;
	cin>>T;

	while (T--)
		solve();
}